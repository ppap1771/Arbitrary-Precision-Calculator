/* Including header files */
#include <stdio.h>
#include <stdlib.h>

/* Colors for fun! */
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define NC "\e[0m"

/* Structure to represent each node of the doubly linked list */
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} dll;

/* Push element at the end of the doubly linked list */
void push_back(dll **head, dll **tail, int data)
{
    dll *node = (dll *)malloc(sizeof(dll));
    if (node == NULL)
    {
        fprintf(stderr, RED "[ERROR]" NC ": Overflow! \n");
        exit(EXIT_FAILURE);
    }
    node->prev = NULL;
    node->data = data;
    node->next = NULL;

    /* If doubly linked list is empty */
    if (*head == NULL)
    {
        *head = node;
        *tail = node;
        return;
    }
    (*tail)->next = node;
    node->prev = *tail;
    *tail = node;
}

/* Push element at the beginning of the doubly linked list */
void push_front(dll **head, dll **tail, int data)
{
    dll *node = (dll *)malloc(sizeof(dll));
    if (node == NULL)
    {
        fprintf(stderr, RED "[ERROR]" NC ": Overflow! \n");
        exit(EXIT_FAILURE);
    }
    node->prev = NULL;
    node->data = data;
    node->next = NULL;

    /* If doubly linked list is empty */
    if (*head == NULL)
    {
        *head = node;
        *tail = node;
        return;
    }
    (*head)->prev = node;
    node->next = *head;
    *head = node;
}

/* Pop element from the end of the doubly linked list */
void pop_back(dll **head, dll **tail)
{
    if (*head == NULL)
    {
        fprintf(stderr, YEL "[WARNING]" NC ": Underflow! \n");
        return;
    }

    /* If element to pop is the only element */
    if ((*tail)->prev == NULL)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }

    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
}

/* Pop element from the beginning of the doubly linked list */
void pop_front(dll **head, dll **tail)
{
    if (*head == NULL)
    {
        fprintf(stderr, YEL "[WARNING]" NC ": Underflow! \n");
        return;
    }

    /* If element to pop is the only element */
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }

    *head = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;
}

/* Displaying linked list */
void print_front(dll **head, dll **tail)
{
    dll *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", (temp)->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Displaying reversed linked list */
void print_back(dll **head, dll **tail)
{
    dll *temp = *tail;
    while (temp != NULL)
    {
        printf("%d ", (temp)->data);
        temp = temp->prev;
    }
    printf("\n");
}
