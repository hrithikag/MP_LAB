#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList
{
   char data[20];
   struct LinkedList *next;
};

typedef struct LinkedList *node;

node createNode(){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}

node addNode(node head, char value[]){
    node temp,p;
    temp = createNode();
    strcpy(temp->data,value);
    if(head == NULL){
	head = temp;
    }
    else{
	p  = head;
	while(p->next != NULL){
	    p = p->next;
	}
	p->next = temp;
    }
    return head;
}

void findmid(node head)
{
   int count=1;
   node curr=head, temp=head;
   while(curr->next!=NULL)
   {
      curr=curr->next;
      count++;
   }
   if((count%2)!=0)
      count=count/2;
   else
      count=(count+1)/2;
   while(temp->next!=NULL && count!=0)
   {
      temp=temp->next;
      count--;
   }
   printf("\n\n\nThe middle element is: %s",temp->data);
}

void display(node head)
{
    node tmp=NULL;
    if(head == NULL)
    {
	printf(" No data found in the empty list.");
    }
    else
    {
	tmp = head;
	while(tmp != NULL)
	{
	    printf("%s ", tmp->data);
	    if(tmp->next!=NULL)
	       printf("-> ");
	    tmp = tmp->next;
	}
    }
}

int main() {
  int n,i;
  char str[10];
  node first = NULL;
  node second = NULL;
  node merged = NULL;
  clrscr();
  printf("\nEnter length of the list: ");
  scanf("%d",&n);
  clrscr();
  for(i = 0; i < n; i++) {
    printf("\nEnter element for node #%d: ",i+1);
    scanf("%s",str);
    first = addNode(first,str);
  }
  clrscr();
  printf("\nList:\n");
  printf("----\n\n");
  display(first);
  findmid(first);
  getch();
  return 0;
}