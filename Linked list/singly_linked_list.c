#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void last_insert(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *lastNode = head;
        while (lastNode->next != NULL)

        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    printf("%d element inserted at end \n", val);
}

void deletion_begin()
{
    struct Node *temp = head;
    head = temp->next;
    free(temp);
}
void deletion_end()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("empty list.\n");
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}
void insertion_at_position(int pos, int val)
{
    struct Node *temp = head;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = val;

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        printf("%d inserted at index 0\n",val );
        return;
    }
    if (head == NULL)
    {
        head = newNode;
        printf("%d default insertion at index 0\n",val);
        return;
    }
    int i;
    for (i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid index\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at index %d\n",val ,i+1);
}
void find(int val)
{
    struct Node *temp = head;

    for (int i = 0; temp != NULL; i++)
    {
        if (temp->data == val)
        {
            printf("%d element found at index %d\n", temp->data, i);
            return;
        }
        temp = temp->next;
    }
    printf("%d element not found \n", val);
}

void begin_insert(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Empty List..");
    }
    printf("|");
    while (temp != NULL)
    {
        printf("   %d   |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    begin_insert(10);
    begin_insert(20);
    begin_insert(30);
    last_insert(60);
    find(10);
    display();
    deletion_end();
    display();
    deletion_begin();
    display();
    insertion_at_position(1, 22);
    insertion_at_position(1, 26);
    insertion_at_position(1, 25);
    display();
    return 0;
}