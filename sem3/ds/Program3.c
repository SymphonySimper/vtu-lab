/*
3. Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers
(Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations
*/
#include <stdio.h>

int s[5], top = -1;

void push()
{
    if (top == 4)
        printf("\nStack overflow!!!!\n");
    else
    {
        printf("\nEnter element to insert:");
        scanf("%d", &s[++top]);
    }
}

void pop()
{
    if (top == -1)
        printf("\nStack underflow!!!\n");
    else
        printf("\nElement popped is: %d\n", s[top--]);
}
void display()
{
    int t = top;
    if (t == -1)
        printf("\nStack empty!!\n");
    else
        printf("\nStack elements are:\n");
    while (t >= 0)
        printf("%d ", s[t--]);
}
void palindrome()
{
    int num[5], rev[5], i, t;
    for (i = 0, t = top; t >= 0; i++, t--)
        num[i] = rev[t] = s[t];
    for (i = 0; i <= top; i++)
        if (num[i] != rev[i])
            break;
    if (i == top + 1)
        printf("\nIt is a palindrome\n");
    else
        printf("\nIt is not a palindrome\n");
}

void menu()
{
    int choice;
    while (1)
    {
        printf("\nStack operations\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.Palindrome\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
            break;
        case 4:
            display();
            break;
        case 5:
            return;
        default:
            printf("\nInvalid choice");
        }
    }
}
int main()
{
    menu();
    return 0;
}