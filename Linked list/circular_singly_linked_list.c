#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void insert(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("%d is inserted\n", val);
}

void display()
{
    struct Node *temp = tail->next;
    if (temp == NULL)
    {
        printf("empty list.\n");
        return;
    }
    do
    {
        printf(" %d  ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");

    // printing tail data
    // printf(" %d  ", temp->data);
}
// delete node by value
void delete(int key)
{
    if (tail == NULL)
    {
        printf("empty list\n");
        return;
    }

    struct Node *temp = tail->next, *prev = tail;

    while (1)
    {
        if (temp->data == key)
        {
            if (temp == prev)
            {
                free(temp);
                tail = NULL;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
            }
            printf("%d value deleted.\n", key);
            return;
        }
        temp = temp->next;
        prev = prev->next;
        if (temp == tail->next)
        {
            break;
        }
    }
    printf("%d value not found \n",key);
}

int main()
{
    insert(10);
    insert(30);
    insert(50);
    insert(50);
    insert(50);
    insert(50);
    insert(60);
    display();
    delete (50);
    delete (50);
    delete (50);
    delete (50);
    delete (60);
    display();
    display();
    display();
    return 0;
}