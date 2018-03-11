## Queue
A **Queue** is an ordered collection of items into which new items can be inserted and items can be deleted at the different ends.

## Operations
The two changes which can be made to Queue is given special names.

* Enqueue : When an item is added to a Queue, it is called **enqueued** onto the Queue.
* Dequeue : When an item is removed from Queue, it is called **dequeued** from Queue


If there is no item in the Queue, it is called **empty Queue**.

## Queue impelementation using C
```
#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR queue=NULL;



int isempty(queue) 
NODEPTR queue;
{
	return ( queue == NULL );
}

void enqueue(queue, x)
NODEPTR *queue;
int x;
{
	NODEPTR np;
	NODEPTR tnp; /* temporary node pointer */

	np = (NODEPTR) malloc(sizeof(struct node));
	np->info = x;
	np->next = NULL;

	if ( isempty(*queue) )
	{
		*queue = np;
	}
	else 
	{
		for (tnp = *queue; tnp->next != NULL; tnp = tnp->next )
			;
 		tnp->next = np;
	}
}

int dequeue(queue)
NODEPTR *queue;
{
	NODEPTR np;
	int info;

	if ( isempty(*queue) )
	{
		printf("\n\tEmpty Queue. Invalid dequeue");
		exit(1);
	}
	
	np = *queue;
	info = (*queue)->info;

	*queue = (*queue)->next;
	free(np);

    return(info);
}

void print_queue(queue)
NODEPTR queue;
{
	NODEPTR np;
	if ( isempty(queue) ) 
	{
		printf("\n\tQueue is empty");
		return;
	}

	printf("\n\tQueue : ");	
	for ( np = queue; np != NULL; np = np->next )
		printf("%d ", np->info);
	printf("\n");

}

int main(void)
{
 NODEPTR queue = NULL;
 int opt;
 int num = 0;

 while(1) 
 {
    //system("clear");
	printf("\n\n\tSTACK IMPLEMENTATION\n");
	printf("\t--------------------\n");
	printf("\t1. print queue\n");
	printf("\t2. enqueue\n");
	printf("\t3. dequeue\n");
	printf("\t4. exit\n");
	printf("\n\tEnter choice : ");
	scanf("%d", &opt);

	switch(opt) {
		case 1:
			print_queue(queue);
			break;
		case 2:
			printf("\n\tEnter number to enqueue : ");
			scanf("%d", &num);
			enqueue(&queue, num);
			printf("\tenqueue-ed info %d to queue",num);
			break;
		case 3:
			num = dequeue(&queue);
			printf("\n\tdequeue-ed element: %d", num);
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
