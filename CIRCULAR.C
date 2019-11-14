#include <stdio.h>
#include <process.h>
#include <conio.h>
#define size 5

void enqueue(int queue[], int *r, int *f)
{
	int ele;
	if ((*r == size - 1 && *f == 0) || (*f == *r + 1))
	{
		printf("Queue Overflow \n");
		getch();
		return;
	}
	else
	{
		printf("Enter element to be inserted: ");
		scanf("%d", &ele);
		if (*f == -1) *f = 0;
		*r = (*r + 1) % size;
		queue[*r] = ele;
	}
}

int dequeue(int queue[],int *f, int *r)
{
	int ele;
	if (*f == -1)
	{
		printf("Queue Underflow \n");
		return -999;
	}
	else
	{
		ele = queue[*f];
		if (*f == *r)
		{
			*f = -1;
			*r = -1;
			return ele;
		}
		else
		{
			*f = (*f + 1) % size;
			return ele;
		}
	}
}

void display(int queue[], int f, int r)
{
	int i;
	if (f == -1)
		printf("Queue Underflow\n");
	else
	{
		printf("Queue:\n");
		printf("-----\n\n");
		for (i = f; i != r; i = (i + 1) % size) printf("%d \t", queue[i]);
		printf("%d", queue[i]);
	}
}

void main()
{
	int queue[10];
	int f = -1, r = -1, option,ch;
	while(1)
	{
		clrscr();
		printf("Circular Queue Operations:\n");
		printf("-------------------------\n\n");
		printf("1.Insert an element\n2.Delete an element \n3.Display the queue \n4.Exit the program\n\n");
		printf("Choose operation to be done: ");
		scanf("%d", &option);

		switch (option)
		{
			case 1: clrscr();
				enqueue(queue, &r, &f);
				break;

			case 2: clrscr();
				ch = dequeue(queue, &f, &r);
				if (ch == -999)
				{
				   getch();
				   break;
				}

				else
				{
				   printf("The Deleted Element is : %d \n", ch);
				   getch();
				   break;
				}

			case 3: clrscr();
				display(queue, f, r);
				getch();
				break;
			case 4: exit(0);
			default: clrscr();
				 printf("\nInvalid Input \n");
				 getch();
		}
	}
}