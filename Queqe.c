#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node {
	char *data;
	t_node *next;
}t_node;

typedef struct {
	t_node *head;
	t_node *tail;
} queue;

void queue_init (queue *q)
{
	q->head = NULL;
	q->tail = NULL
}

int enqueue( queue *q, char *val)
{
	t_node * new_node = malloc(sizeof(t_node));
	if(new_node == NULL)
	{
		return(0);
	}
	memcpy(new_node->value,val);
	new_node->next = NULL;
	if(q->tail != NULL)
	{
		q->tail->next = new_node;
	}
	q->tail = new_node;
	if(q->head == NULL)
	{
		q->head = new_node;
	}
	return(1);
}
int dequeue( queue *q ) 
{
	if (q->head == NULL) 
	{
		return QUEUE_EMPTY;
	}
	t_node *temp = q->head;
	char *out = temp->value;
	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	free(temp);
	return(out);
}
void show()
{
	
}
int main()
{
	int input_size = 1000;
	int deNum;
	char userInput[input_size];
	char *token;
	queue q1;
	init_queue(&q1);
	fgets(userInput,input_size,stdin);
	//Replace the \n with Null characters to split the word.
	if(userInput[strlen(userInput-1)] == "\n")
	{
		userInput[strlen(userInput)-1] = "\0"; 
	}	
	token = strtok(userInput," ");
	while(token != NULL)
	{
		enqueqe(token);
		token = strtok(NULL," ");
	}
	printf("How many element you want to dequeue: ");
	scanf("%d",&deNum);

}
