// LISTA DUPLA ENCADEADA NÃO CIRCULAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MUSICA 1024
#define DELIMITADOR ","
#define QUEBRA "\n"

typedef struct node
{
    struct node *prev;
    char *musica;
    char *artista;
    char *duracao;
    struct node *next;
} node;

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

int length();
bool isEmpty();
void insertBeginning(char *musica, char *artista, char *tempo);
void insertMiddle(char *musica, int pos);
void insertLast(char *musica, char *artista, char *tempo);
void printList();
int menu();

int main(int argc, char *argv[])
{
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    if (argc != 2)
    {
        printf("Uso: ./list [arquivo]\n");
    }
    else
    {
        char *teste;
        teste ="dani";
        insertBeginning(teste, "teste", "1");
        teste ="show";
        insertBeginning(teste, "top", "2");

        printList();
        int op = menu();
        FILE *fp = fopen(argv[1], "r");
        char *argFile;
        char col1, col2, col3;
        char linha[MAX_MUSICA];
        argFile = argv[1];
        char *campo;
        int countLinha = 0;
        char *musica, *artista, *tempo;

        while (fgets(linha, MAX_MUSICA, fp) != NULL)
        {   
            // printf("Linha %i: ", countLinha);
                // separa tokens
            // printf("Campos:\n");
            campo = strtok(linha, DELIMITADOR);

            while (campo != NULL)
            {
                if(countLinha > 0)
                {
                    musica = campo;
                    artista = strtok(NULL, DELIMITADOR);
                    tempo = strtok(NULL, DELIMITADOR);
                    // printf("%s,%s %s\n", musica, artista, tempo);
                    insertBeginning(musica, artista, tempo);
                }
                campo = strtok(NULL, DELIMITADOR);
            }
            countLinha ++;
        }

        while ((col1 = fgetc(fp)) != EOF);
    
        while (1)
        {
            switch (op)
            {
            case 1:
                printList();
                return 0;
            case 2:
                printf("saindo \n");
                return 0;
            default:
                break;
            }
        }
    }
}

int menu()
{
    int op, c;

    printf("1.Listar a lista encadeada dupla\n");
    printf("2.Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    system("clear");
    return op;
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

void insertBeginning(char *musica, char *artista, char *tempo)
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

    if (pos == 0)
    {
        head = newMusic;
        head->next = NULL;
    }
    else
    {
        current = head;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        tmp->next = newMusic;
    }
}

void insertLast(char *musica, char *artista, char *tempo)
{
    struct node *tmp, *currentElement;
    tmp = malloc(sizeof(struct node));
    currentElement = malloc(sizeof(struct node));

    tmp->musica = musica;
    tmp->artista = artista;
    tmp->duracao = tempo;

    if (head == NULL)
    {
        head = tmp;
        head->next = NULL;
    }
    else
    {
        currentElement = head;
        while (currentElement->next != NULL)
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
        if (current->next != NULL)
        {
            printf("', ");
        }
        else
        {
            printf("' ");
        }
        current = current->next;
    }
    printf("]\n");
}
