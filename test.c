#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
        struct  node *prev;
        int data;
        struct node *next;
}node;


node *head;



int main(void)
{
	node *one, *zero = NULL;

    head = (struct node *) calloc(1, sizeof(struct node));
	zero = (struct node *) malloc(sizeof(struct node));
	one = (struct node *) malloc(sizeof(struct node));

	printf("head: %p\n", head);
    printf("zero: %p\n", zero);
	printf("one:  %p\n", one);

}