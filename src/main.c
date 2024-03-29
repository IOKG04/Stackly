#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "stack.h"

stack data, return_stack;
char *code;
int code_length;

void read_code(char *path){
    FILE *code_file = fopen(path, "r");
    if(code_file == NULL){
	printf("Error 02: Code file doesn't exist\n");
	exit(-2);
    }
    fseek(code_file, 0L, SEEK_END);
    long file_length = ftell(code_file) + 1;
    code = malloc(file_length);
    code_length = file_length;
    if(code == NULL){
	fclose(code_file);
	printf("Error 100: Internal\nPlease report what you did to get here and the exit code to the dev\n");
	exit(-100);
    }
    rewind(code_file);
    fread(code, 1, file_length, code_file);
    fclose(code_file);
}

int main(int argc, char **argv){
    // exit on too few arguments
    if(argc < 2){
	printf("Error 01: No arguments specified\n");
	exit(-1);
    }

    // load file
    read_code(argv[1]);

    // create stacks
    stack_create(&data);
    stack_create(&return_stack);

    // set no line buffering (thx chatgpt :3)
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    // execute file
    char running = 1;
    register char *ip = code;
    while(running){
	s32 a, b;
	switch(*ip){
	    case 'q':
		running = 0;
		break;
	    case '+':
		a = stack_pop(&data);
		b = stack_pop(&data);
		stack_push(&data, b + a);
		break;
	    case '-':
		a = stack_pop(&data);
		b = stack_pop(&data);
		stack_push(&data, b - a);
		break;
	    case '*':
		a = stack_pop(&data);
		b = stack_pop(&data);
		stack_push(&data, b * a);
		break;
	    case '/':
		a = stack_pop(&data);
		b = stack_pop(&data);
		stack_push(&data, b / a);
		break;
	    case '!':
		a = stack_pop(&data);
		if(a != 0) stack_push(&data, 0);
		else stack_push(&data, 1);
		break;
	    case 'p':
		stack_pop(&data);
		break;
	    case 'r':
		ip = code + stack_pop(&return_stack);
		break;
	    case 'd':
		stack_push(&data, stack_peek(&data));
		break;
	    case ':':
		printf("%i", stack_pop(&data));
		break;
	    case '.':
		printf("%c", stack_pop(&data));
		break;
	    case ';':
		scanf("%i", &a);
		stack_push(&data, a);
		break;
	    case ',':
		stack_push(&data, getchar());
		break;
	    case '[':
		a = stack_pop(&data);
		if(a == 0){
		    while(++ip < code + code_length && (*ip != ']' || a != 0)){
		        if(*ip == '[') ++a;
		        else if(*ip == ']') --a;
		    }
		}
		break;
	    case ']':
		a = 0;
		while(--ip >= 0 && (*ip != '[' || a != 0)){
		    if(*ip == '[') --a;
		    else if(*ip == ']') ++a;
		}
		--ip;
		break;
	    default:
		// number
		if(*ip >= 0x30 && *ip <= 0x39){
		    char n[16] = {0};
		    int i = 0;
		    while(*ip >= 0x30 && *ip <= 0x39 && i < 15){
			n[i++] = *(ip++);
		    }
		    --ip;
		    stack_push(&data, strtol(n, NULL, 10));
		}
		break;
	}
	++ip;
	if(ip >= code + code_length) running = 0;
    }

    // clean and return
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    int return_val = stack_peek(&data);
    stack_clean(&data);
    stack_clean(&return_stack);
    return return_val;
}
