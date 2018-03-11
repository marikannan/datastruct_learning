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
