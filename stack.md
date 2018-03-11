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


## Stack impelementation using C
```
#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR stack=NULL;



int isempty(stack) 
NODEPTR stack;
{
	return ( stack == NULL );
}

void push(stack, x)
NODEPTR *stack;
int x;
{
	NODEPTR np;
	np = (NODEPTR) malloc(sizeof(struct node));
	np->info = x;

	if ( isempty(*stack))
		np->next = NULL;
	else 
	 	np->next = (*stack);

	(*stack) = np;
}

int pop(stack)
NODEPTR *stack;
{
	NODEPTR np;
	int info;

	if ( isempty(*stack) )
	{
		printf("\n\tEmpty Stack. Invalid pop");
		exit(1);
	}
	
	np = *stack;
	info = (*stack)->info;

	*stack = (*stack)->next;
	free(np);

    return(info);
}

void print_stack(stack)
NODEPTR stack;
{
	NODEPTR np;
	if ( isempty(stack) ) 
	{
		printf("\n\tStack is empty");
		return;
	}

	printf("\n\tStack : ");	
	for ( np = stack; np != NULL; np = np->next )
		printf("%d ", np->info);
	printf("\n");

}

int main(void)
{
 NODEPTR stack = NULL;
 int opt;
 int num = 0;

 while(1) 
 {
    system("clear");
	printf("\n\n\tSTACK IMPLEMENTATION\n");
	printf("\t--------------------\n");
	printf("\t1. print stack\n");
	printf("\t2. push\n");
	printf("\t3. pop\n");
	printf("\t4. exit\n");
	printf("\n\tEnter choice : ");
	scanf("%d", &opt);

	switch(opt) {
		case 1:
			print_stack(stack);
			break;
		case 2:
			printf("\n\tEnter number to push : ");
			scanf("%d", &num);
			push(&stack, num);
			printf("\tpushed info %d to stack",num);
			break;
		case 3:
			num = pop(&stack);
			printf("\n\tpop-ed element: %d", num);
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("\n\tEnter a valid choice");
			break;
	}

	fseek(stdin,0,SEEK_END); /* ignore any newline in input buffer */
	printf("\n\n\tPress enter to proceed ...");
	getchar();
   }
 exit(1);
}

```
