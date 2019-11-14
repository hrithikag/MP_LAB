#include<stdio.h>
#include<conio.h>
#include<process.h>
#define q_size 25
void enqueue(int q[], int *r)
{
    int item;
    printf("Enter the element to be inserted: ");
    scanf("%d",&item);
    if((*r)==(q_size-1))
	printf("The stack is full.\n");
    else
    {
	q[++(*r)]=item;
    }
}

void dequeue(int q[], int *r, int *f)
{
    if((*f)>(*r))
	printf("Stack is empty.\n");
    else
    {
	printf("Element to be deleted: %d",q[*f]);
	(*f)++;
    }
}

void display( int q[], int *r, int *f)
{
    int i,j;
    if((*f)>(*r))
	printf("Stack is empty.\n");
    else
    {
	for(i=(*f);i<=(*r);i++)
	     printf("%d\t",q[i]);
    }
}

void main()
{
   int a[q_size];
   int f=0;
   int r=-1;
   int i,ch;
   while(1)
   {
       clrscr();
       printf("Stack Operations:\n");
       printf("----------------\n\n\n");
       printf("1.Insert an element.\n");
       printf("2.Delete an element.\n");
       printf("3.Display the queue.\n");
       printf("4.Exit the program:\n\n");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:
	  {
	     clrscr();
	     enqueue(a, &r);
	     break;
	  }
	  case 2:
	  {
	     clrscr();
	     dequeue(a, &r, &f);
	     getch();
	     break;
	  }
	  case 3:
	  {
	     clrscr();
	     display(a, &r, &f);
	     getch();
	     break;
	  }
	  case 4:
	  {
	     clrscr();
	     printf("Thank you.");
	     getch();
	     exit(0);
	  }
	  default:
	  {
	     clrscr();
	     printf("Invalid option.");
	     getch();
	  }
       }
   }
}



