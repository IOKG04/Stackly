# Stackly

(Note: The Interpreter is for Windows 10. If you want to use it on Linux or Mac: Download the Master version and compile Program.cs)

Stackly is an essoteric Programming Language I'm programming in c#.

Data is stored using 3 Stacks.

The Synatx is '(Command) (Argument 1) (Argument 2) (Argument ...)'. Every Command takes up one Line. You can't put more than one Command in one Line.

You can use the Stacks and the Queue using 'A' (Stack 1), 'B' (Stack 2) and 'C' (Stack 3).

Commands:

Rmv (Stack)                     | Pop's the top value of (Stack)
 
Dbl (Stack)                     | Doubles the top value of (Stack)
 
PshC (Stack)                    | Pushes number of values on (Stack) onto (Stack)
 
InN (Stack)                     | Get's Input as a Number and pushes it onto (Stack)
 
InC (Stack)                     | Get's Input as a Character and pushes its AscII-Value onto (Stack)
 
OutN (Stack)                    | Pop's the top value of (Stack) and Output's it as a Number
 
OutC (Stack)                    | Pop's the top value of (Stack) and Output's the AscII-Charater coresponding to the Poped value
 
Pop (Stack 1) (Stack 2)         | Pop's the top value of (Stack 1) and Pushes it onto (Stack 2)
 
Push (Stack) (Value)            | Pushes (Value) onto (Stack)
 
PopA (Stack 1) (Stack 2)        | Pop's the top value of (Stack 1) and (Stack 2) and Pushes the result of '(first value) + (second value)' onto (Stack 1)
 
PopS (Stack 1) (Stack 2)        | Pop's the top value of (Stack 1) and (Stack 2) and Pushes the result of '(first value) - (second value)' onto (Stack 1)
 
PopM (Stack 1) (Stack 2)        | Pop's the top value of (Stack 1) and (Stack 2) and Pushes the result of '(first value) * (second value)' onto (Stack 1)
 
PopD (Stack 1) (Stack 2)        | Pop's the top value of (Stack 1) and (Stack 2)and Pushes the result of '(first value) / (second value)' onto (Stack 1)
 
PopP (Stack 1) (Stack 2)        | Pop's the top value of (Stack 1) and (Stack 2) and Pushes the result of '(first value) % (second value)' onto (Stack 1)
 
GoTo (Line)                     | Jump's to (Line)
 
GIfZ (Line) (Stack)             | Pop's the top value of (Stack) and Jump's to (Line) if the poped value is 0
 
GIfG (Line) (Stack 1) (Stack 2) | Pop's the top value of (Stack 1) and (Stack 2) and Jump's to (Line) if the first poped value is greater than the second poped value
 
GSub (Line) (Stack)             | Pushes the current Line onto (Stack) and Jump's to (Line)
 
Rtrn (Stack)                    | Pop's the top value of (Stack) and Jump's to it
 
Stp                             | Stop's the execution

(The Commands don't have to be capitalised, Linenumbers are starting with Line 1, Variable (Stack 1) and (Stack 2) can't be the same, The values are stored as Integers (So devision rounds down to the Integer smaler than the actual result))

PS.: No warranty that everything works as intended. I maybe did Errors.

PPS.: I'm in 8th grade, still learning English. So if you find mistakes (Capitilation not included because I want to make the important words stand out), please tell me, so I can learn more English faster. (I'm from Germany)
