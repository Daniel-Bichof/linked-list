#include <stdio.h>
#include <stdlib.h>

typedef struct node
{  
    struct node *prev;  
    int music;
    struct node *next;   
} node;

void addMusic();

int main(void)
{
    /* Initialize nodes */
    struct node *head;
    struct node *one;

    /* Allocate memory */
    one = malloc(sizeof(struct node ));
    // two = malloc(sizeof(struct node *)); 

    /* Assign data values */
    one->music = 1;
    // two->music = 2;

    printf("%p\n", *one);
    printf("%i\n", one->music);
    free(head);
    free(one);
    
}


void addMusic()
{   
    struct node *ex;
}