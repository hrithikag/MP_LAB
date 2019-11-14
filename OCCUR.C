#include<conio.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

void push(int b, int a[], int *top)
{
   if(*top==30)
      printf("\n\nStack Overflow.");
   else
   {
      (*top)++;
      a[*top]=b;
   }
}

void pop(int a[], int *top)
{
   if((*top)==-1)
      printf("\n\nStack Underflow.");
   else
   {
      printf("Element to be deleted: %d",a[*top]);
      (*top)--;
   }
}

void update(int a[], int *top)
{
   int min,i;
   int j=0;
   int temp,count=0;
   min=a[0];
   for(i=1;i<=(*top);i++)
   {
	    if(min>a[i])
	    {
		min=a[i];
		j=i;
	    }
   }
   for(i=j+1;i<=(*top);i++)
   {
	 if(min==a[i])
	    count++;
   }
   for(i=0;i<=(*top);i++)
   {
	 if(a[i]!=min && i!=0 && i>j)
	 {
	    if(a[i-1]==min)
	    {
	       if(i==(*top))
	       {
		  temp=a[i];
		  a[i-count-1]=temp;
		  a[i]=a[i-count-1];
	       }
	       else
	       {
		  temp=a[i];
		  a[i-1]=temp;
		  a[i]=a[i-1];
	       }
	    }
	    else
	    {
	       temp=a[i];
	       a[i-1]=temp;
	       a[i]=a[i-1];
	    }
	 }
   }
   a[--i]=min;
   while(count!=0)
   {
	    a[--i]=min;
	    count--;
   }
}


void display(int a[], int *top)
{
   int i,j;
   for(i=0;i<=(*top);i++)
   {
      printf("%d\t",a[i]);
   }
}

void main()
{
   int top=-1;
   int a[30];
   int item;
   int ch;
   clrscr();
   while(1)
   {
   clrscr();
   printf("Stack Operations:\n");
   printf("-----------------\n\n");
   printf("1. Push an element.\n");
   printf("2. Pop an element.\n");
   printf("3. Update the stack.\n");
   printf("4. Display the stack.\n");
   printf("5. Exit the program.\n\n");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:
      {
	 clrscr();
	 printf("Enter the element to be inserted: ");
	 scanf("%d",&item);
	 push(item,a,&top);
	 break;
      }
      case 2:
      {
	 clrscr();
	 pop(a,&top);
	 getch();
	 break;
      }
      case 3:
      {
	 clrscr();
	 if(top==-1)
	 {
	    printf("\n\nStack underflow.");
	    getch();
	 }
	 else
	 {
	    update(a,&top);
	    printf("Updated stack:\n");
	    printf("-------------\n\n");
	    display(a,&top);
	    getch();
	 }
	 break;
      }
      case 4:
      {
	 clrscr();
	 if(top==-1)
	 {
	     printf("\n\nStack Underflow.");
	     getch();
	 }
	 else
	 {
	    printf("Stack:\n");
	    printf("-----\n\n");
	    display(a,&top);
	    getch();
	 }
	 break;
      }
      case 5:
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