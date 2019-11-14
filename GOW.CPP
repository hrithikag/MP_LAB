#include<stdio.h>
#include<conio.h>
#include<process.h>
int top=-1;
int a[30];
void push(int);
void pop();
void display();

void push(int b)
{
   if(top==30)
      printf("\n\nStack Overflow.");
   else
   {
      top++;
      a[top]=b;
   }
}

void pop()
{
   if(top==-1)
      printf("\n\nStack Underflow.");
   else
   {
      printf("Element to be deleted: %d",a[top]);
      top--;
   }
}

void display()
{
   if(top==-1)
      printf("\n\nStack Underflow.");
   else
   {
      for(int i=0;i<=top;i++)
      {
	 printf("%d\t",a[i]);
      }
   }
}

void main()
{
   int item;
   int ch;
   clrscr();
   while(1)
   {
   clrscr();
   printf("Stack Operations:\n");
   printf("-----------------\n\n\n");
   printf("1. Push an element.\n");
   printf("2. Pop an element.\n");
   printf("3. Display the stack.\n");
   printf("4. Exit the program.\n\n");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:
      {
	 clrscr();
	 printf("Enter the element to be inserted: ");
	 scanf("%d",&item);
	 push(item);
	 break;
      }
      case 2:
      {
	 clrscr();
	 pop();
	 getch();
	 break;
      }
      case 3:
      {
	 clrscr();
	 printf("Stack:\n");
	 printf("-----\n\n");
	 display();
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
   getch();
}
