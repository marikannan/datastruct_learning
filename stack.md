# Stack
A **Stack** is an ordered collection of items into which new items can be inserted and items can be deleted at the same end, called the top of Stack.

## Operations
The two changes which can be made to stack is given special names.

* Push : When an item is added to a stack, it is called **pushed** onto the stack.
* Pop : When an item is removed from stack, it is called **popped** from stack

Based on the kind of operations it permits, stack is sometimes called as **pushdown** list.

If there is no item in the stack, it is called **empty stack**. There is another special opration called **stacktop** which returns top element of stack.

## An Example
Now we can see an usage of stack in the below example,

Consider an mathematical expression that includes several sets of nested parentheses; for example,
```
7 - ((X* ((X + Y) / (J - 3)) + Y) / (4 - 2.5))
```

We want to ensure that the parentheses are nested correctly such that,
1. Equal number of right and left parentheses.
2. Every right parenthesis is preced by a matching left parentheses.

To solve this problem, we will consider that each left parenthesis as opening a scope and each right parenthesis as closing scope. The nesting depth at a particular point in an expression is the number of scopes that have been opend and not yet closed at that point.
*  **Parenthesis count** is the number of left parenthesis minus number of right parenthesis

```
7 - ( ( X * ( ( X + Y ) / ( J - 3 ) ) + Y ) / ( 4 - 2.5 ) )
0 0 1 2 2 2 3 4 4 4 4 3 3 4 4 4 4 3 2 2 2 1 1 2 2 2  2  1 0
```

The below two conditions should be true to form a acceptable expression with correct parenthesis,
1. Parenthesis count at the end of expression is zero ( 0 ).
2. Parenthesis count at each point in the expression is nonnegative.

This problem can be solved using stack with two operations of pop(), push(). 
```
valid = true;
s = the empty stack;

while ( we have not read entire string ) {

  read the next symbol ( symb) of the string;
  
  if (symb == '(' || symb == '[' || symb == '{' )
    push(s,symb);
  
  if (symb == ')' || symb == ']' || symb == '}' )
    if (empty(s))
      valid = false;
    else {
      i = pop(s);
      if (i is not the matching opener of symb)
        valid = false;
    }
 }
 
 if(!empty(s))
  valid = false;
  
 if (valid)
   printf("%s, "the string is valid");
 else
   printf("%s", "the string is invalid");
  
```
