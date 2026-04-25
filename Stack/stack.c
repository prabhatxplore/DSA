// Static implementation of stack
#include <stdio.h>
void push();
void pop();
void display();
void peek();

int top, stack[100], ch = 0, n;
int main()
{
    top = -1;
    printf("Maximum 100 elements: \n");
    printf("Enter the no of element you want to enter: \n");
    scanf("%d", &n);
    printf(" 1. push\n");
    printf(" 2. pop\n");
    printf(" 3. display\n");
    printf(" 4. peek\n");
    printf(" 5. exit\n");
    while (ch != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice (choose 1-5)\n");
        }
    }
}
void push()
{

    if (top >= n - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int value;
        printf("Enter values: \n");
        scanf("%d", &value);
        stack[++top] = value;
        printf("%d pushed\n", value);
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("Stack is empty\n");
    }
    else
        printf("%d popped \n", stack[top--]);
}
void peek()
{
    if (top <= -1)
    {
        printf("stack is empty\n");
    }
    else
        printf("%d is peeked\n", stack[top]);
}

void display()
{
    if (top <= -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i > -1; i--)
        {
            printf("%d \n", stack[i]);
        }
    }
}