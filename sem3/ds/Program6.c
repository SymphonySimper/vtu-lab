/*
6. Design, Develop and Implement a menu driven Program in C for the following operations on Circular QUEUE of Characters 
(Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations
*/
#include <stdio.h>
#include <stdlib.h>
#define max 5
int q[max], f = -1, r = -1;
void ins()
{
    if (f == (r + 1) % max)
        printf("\nQueue overflow\n");
    else
    {
        if (f == -1)
            f++;
        r = (r + 1) % max;
        printf("\nEnter element to be inserted:");
        scanf("%d", &q[r]);
    }
}
void del()
{
    if (r == -1)
        printf("\nQueue underflow");
    else
    {
        printf("\nElemnt deleted is:%d\n", q[f]);
        if (f == r)
            f = r = -1;
        else
            f = (f + 1) % max;
    }
}
void disp()
{
    if (f == -1)
        printf("\nQueue empty\n");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = f; i != r; i = (i + 1) % max)
            printf("%d\t", q[i]);
        printf("%d", q[i]);
        printf("\nFront is at:%d\nRear is at:%d\n", q[f], q[r]);
    }
}
void menu()
{
    int choice;
    while (1)
    {
        printf("\nCircular Queue operations\n");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ins();
            break;
        case 2:
            del();
            break;
        case 3:
            disp();
            break;
        case 4:
            return;
        default:
            printf("\nInvalid choice...!\n");
        }
    }
}
int main()
{
    menu();
    return 0;
}
