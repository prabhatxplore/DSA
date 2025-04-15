#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insert_at_pos(int pos, int val)
{
    struct Node *temp = head;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    if (pos == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    int i = 0;
    while (temp != NULL && i<pos-1)
    {

        temp = temp->next;
        i++;
    }
    if(temp ==NULL){
        printf("Invalid index\n");
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;

    printf("inserted..\n");

}
void last_insert(int data)
{
    struct Node *temp = head;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (temp == NULL)
    {
        head = newNode;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void begin_insert(int data)
{

    struct Node *temp = head;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void display()
{
    if (head == NULL)
    {
        return;
    }
    struct Node *temp;
    temp = head;
    printf("|");
    while (temp != NULL)
    {
        printf("  %d  |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    begin_insert(10);
    begin_insert(90);
    begin_insert(60);
    last_insert(123);
    last_insert(16);
    last_insert(13);
    display();
    insert_at_pos(1,2);
    display();
    insert_at_pos(3,2);
    display();
    return 0;
}
