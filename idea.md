## Syntax idea

### Truth machiene

```
;0![d:]:

;       get input as number
!       not operator (0 -> 1, else -> 0)
[...]   repeat while top value != 0 (peek)
d       duplicate
:       output top as number (pop)
```

### Factorial (recursive)

```
;FACT:FACT(d1={p1r}d1-FACT*r

FACT    function name (all caps)
\n      ignored (only for readability)
(       assign function
[n]     push [n]
{...}   execute if top value != 0
p       pop top value
r       return from function (needed as functions do not end)
-       subtract top from second top
```

## Commands

...(    assign functions
...)    assign label
[...]   repeat while top != 0 (peek)
{...}   execute if top != 0 (peek)
