#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// LISTA DUPLA LINKADA CIRCULAR

typedef struct node
{
    struct node *prev;
    char *musica;
    char *artista;
    int *duracao;
    struct node *next;
} node;

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

int length();
bool isEmpty();
void insertBeginning(char *musica);
void insertMiddle(char *musica, int pos);
void insertLast(char *musica);
void printList();
int menu();

int main(void)
{
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    int op, num, pos, c;
    char *musica, artista;
    system("clear");
    

while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite a musica desejada: ");
			scanf("%s", musica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			insertBeginning(musica);
			break;
		case 2:
			printf("Digite a musica desejada: ");
			scanf("%c", musica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			insertLast(musica);
			break;
		case 3:
			printf("Digite a musica desejada: ");
			scanf("%c", musica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a posicao que deseja inserir: ");
			scanf("%i", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			insertMiddle(musica, pos);
			break;
		/*case 4:
			int res;
			printf("Digite a musica a ser removida: ");
			scanf("%c", musica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(musica);
			if (res == 1)
				printf("musica removida.");
			else
				printf("musica nao encontrado.");
			break;
        */
		case 5:
			printList();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;

    insertLast("Happy together");
    insertLast("Africa");
    insertBeginning("Yellow submarine");
    insertBeginning("Blackbird");
    printList();
    
    // printf("head: %s\n", head->data);

    printf("length: %i\n", length());

}

int menu()
{
    
	int op, c;

	printf("1.Inserir no inicio da lista encadeada simples\n");
	printf("2.Inserir no fim da lista encadeada simples\n");
	printf("3.Inserir no meio da lista encadeada simples\n");
	printf("4.Remover da lista encadeada simples\n");
	printf("5.Listar a lista encadeada simples\n");
	printf("6.Sair\n");
	printf("Digite sua escolha: ");

}


int length()
{
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }
    return length;
}

bool isEmpty()
{
    return head == NULL;
}

void insertBeginning(char *musica)
{
    struct node *tmp = malloc(sizeof(struct node));
    tmp->musica = musica;

    if (head == NULL)
    {
        head = tmp;
        head->next = NULL;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }

}
void insertMiddle(char *musica, int pos)
{
    struct node *newMusic = malloc(sizeof(struct node));
    struct node *tmp = malloc(sizeof(struct node));
    struct node *current = malloc(sizeof(struct node));

    newMusic->musica = musica;

    if (pos == 0){
        head = newMusic;
        head->next = NULL;
    } else
    {
        current = head;
        for(int i = 0; i < pos; i++){
            current = current->next;
        }
        tmp->next = newMusic;
    }
}

void insertLast(char *musica)
{
    struct node *tmp, *currentElement;
    tmp = malloc(sizeof(struct node));
    currentElement = malloc(sizeof(struct node));

    tmp->musica = musica;

   if (head == NULL)
    {
        head = tmp;
        head->next = NULL;
    }
    else
    {
        currentElement = head;
        while(currentElement->next != NULL)
        {
            currentElement = currentElement->next;
        }
        currentElement->next = tmp;
        tmp->next = NULL;
        tmp->prev = currentElement;
    }
}

void printList()
{
    struct node *current;
    current = malloc(sizeof(struct node));
    current = NULL;
    current = head;

    printf("[ ");
    while (current != NULL)
    {
        
    printf("' ");
        printf("%s ", current->musica);
        if(current->next != NULL)
        {
            printf("', ");
        } else { 
            printf("' ");
        }
        current = current->next;
    }
        printf("]\n");
}
