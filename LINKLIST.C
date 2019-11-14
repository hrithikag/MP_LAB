#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}*Node;

Node getnode()
{
  Node p;
  p=(Node) malloc (sizeof(Node));
  if(p!=NULL)
    return p;
  else
    {
      printf("Memory is not allocated");
      exit(0);
      return p;
    }
}

Node insert_front(Node head,int item)
{
  Node p;
  p=getnode();
  p->data=item;
  p->next=head;
  head=p;
  return head;
}

Node insert_end(Node head,int item)
{
  Node p,q;
  q=getnode();
  q->data=item;
  q->next=NULL;
  if(head==NULL)
     return q;
  p=head;
  while(p->next!=NULL)
     p=p->next;
  p->next=q;
  return head;
}

Node insert_pos(int item, int pos, Node head)
{
    Node curr,newn, prev = NULL;
    int count = 1;
    newn = getnode();
    newn -> data = item;
    newn -> next = NULL;
    if (head == NULL)
    {
	if (pos == 1)
	{
	    Node p;
	    p=getnode();
	    p->data=item;
	    p->next=head;
	    head=p;
	    return head;
	}
	else
	{
	    printf("\nInvalid position!");
	    getch();
	    return head;
	}
    }
    else
    {
	if (pos == 1)
	{
		newn -> next = head;
		head = newn;
		return head;
	}
	else
	{
		curr = head;
		while (curr != NULL && count != pos)
		{
			prev = curr;
			curr = curr -> next;
			count ++;
		}
		if (count == pos)
		{
			prev -> next = newn;
			newn -> next = curr;
			return head;
		}
		else
		{
			printf("\nInvalid position! \n");
			getch();
			return head;
		}
	}
    }
}

void display(Node head)
{
  Node p;
  if(head==NULL)
    {
      printf("\nList is empty\n");
    }
  else
    {
      p=head;
      printf("\nList:");
      printf("\n----\n\n");
      while(p!=NULL)
	{
	  printf("%d ",p->data);
	  p=p->next;
	 }
      printf("\n");
     }
}

int main()
{
  Node head=NULL;
  int option,ele,value,pos;
  while(1)
   {
     clrscr();
     printf("\n1)Insert Front\n2)Insert End\n3)Insert in position\n4)Display\n5)Exit\n");
     printf("Enter your choice: ");
     scanf("%d",&option);
     switch(option)
       {
	 case 1: printf("\nEnter the element to be inserted: ");
		 scanf("%d",&ele);
		 head=insert_front(head,ele);
		 break;
	 case 2: printf("\nEnter the element to be inserted: ");
		 scanf("%d",&ele);
		 head=insert_end(head,ele);
		 break;
	 case 3: printf("\nEnter the element to be inserted: ");
		 scanf("%d",&ele);
		 printf("\nEnter the position in which it is to be inserted: ");
		 scanf("%d",&pos);
		 head=insert_pos(ele,pos,head);
		 break;
	 case 4: clrscr();
		 display(head);
		 getch();
		 break;
	 case 5: exit(0);
	 default: printf("Invalid Input.");
		  getch();
       }
   }
}
