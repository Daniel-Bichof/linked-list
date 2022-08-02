#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
        struct  node *prev;
        int data;
        struct node *next;
}node;

    
struct node *head;  
struct node *last;  
struct node *current;  

int length() {
    int length = 0;
    struct node *current;

    for(current = head; current != NULL; current = current->next){
        length++;
    }
    return length;
}

bool isEmpty() {
    return head == NULL;
}

void insertElementsBeginning()
{
	printf("\n");

}

void insertLast(int num)
{
	struct node *tmp = NULL;
	tmp = malloc(sizeof(struct node));
	tmp->data = num;
	struct node *currentElement = head;
    currentElement->next = tmp;
    
 
    printf("tmp: %i\n", tmp->data);
    printf("tmp: %p\n", tmp->prev);
    printf("tmp: %p\n", tmp->next);
    printf("tmp: %p\n", tmp);
    
    printf("currentElement: %i\n", currentElement->data);
}


void printList(node *i)
{

	struct node *lastElement = i;
	lastElement = malloc(sizeof(struct node));
    printf("%p\n", lastElement);
    printf("%i\n", lastElement->data);

    if (lastElement->next != NULL)
    {
        printf("Last element: %p\n", lastElement);
        lastElement = lastElement->next;
        printList(lastElement);
    }

}


int main(void)
{

    head = (struct node *) malloc(sizeof(struct node));
	
	printf("head: %p\n", head);
        
    insertLast(8);

	printf("test\n");
    printf("head: %i\n", head->data);

	// printAllList(head);
}
