/*
1. Design, Develop and Implement a menu driven Program in C for the following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
*/

#include <stdio.h>

int n, a[100], ch;

void create()
{
	printf("\nEnter no. of elements: ");
	scanf("%d", &n);
	printf("\nEnter the elements to be stored in the array:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void display()
{
	printf("\nElements in the array are: \n");
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
}

void insert()
{
	int pos, val;
	printf("\nEnter the position of the element to insert: ");
	scanf("%d", &pos);
	printf("\nEnter the value of element: ");
	scanf("%d", &val);
	n++;
	for (int i = n; i >= pos; i--)
		a[i] = a[i - 1];
	a[pos - 1] = val;
}

void delete()
{
	int pos,elem;
	printf("\nEnter the position of the element to be deleted: ");
	scanf("%d", &pos);
	elem = a[pos - 1];
	for (int i = pos - 1; i <= n; i++)
		a[i] = a[i + 1];
	n--;
	printf("\nElement %d has been deleted.\n", elem);
}

void menu()
{
	while (1)
	{
		printf("\nMENU:\n");
		printf("\n1.Create an array with n elements.");
		printf("\n2.Dispaly elements in the array.");
		printf("\n3.Insert an element to the array.");
		printf("\n4.Delete an element from the array.");
		printf("\n5.Exit");
		printf("\nEnter your choice: \n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insert();
			break;
		case 4:
			delete();
			break;
		case 5:
			return;
		default:
			printf("\nInvalid Choice\n");
		}
	}
}

int main()
{
	menu();
	return 0;
}
