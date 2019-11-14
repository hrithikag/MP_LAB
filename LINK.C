#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList
{
   char data[20];
   struct LinkedList *next;
};

typedef struct LinkedList *node; //Define node as pointer of data type struct LinkedList

node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}

node addNode(node head, char value[]){
    node temp,p;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    strcpy(temp->data,value); // add element's value to data part of node
    if(head == NULL){
	head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
	    p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
	p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}

node reverseList(node head)
{
  node curr = head, prev = NULL, next = NULL;
  while(curr != NULL)
  {
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

node mergeList(node first, node reverse) {
  node head = first;
  node merged = NULL;
  char checkNone[] = "None";
  while(head != NULL) {
    if(!strcmp(head -> data, checkNone))
      merged = addNode(merged, reverse -> data);
    else if(!strcmp(reverse -> data, checkNone))
      merged = addNode(merged, head -> data);
    else {
      strcat(head -> data, reverse -> data);
      merged = addNode(merged, head -> data);
    }
    head = head -> next;
    reverse = reverse -> next;
  }
  return merged;
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
	    printf("%s \t", tmp->data);   // prints the data of current node
	    tmp = tmp->next;                 // advances the position of current node
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
  printf("\nEnter length of both lists: ");
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    printf("\n(FIRST LIST) Enter element for node #%d: ",i+1);
    scanf("%s",str);
    first = addNode(first,str);
  }
  for(i = 0; i < n; i++) {
    printf("\n(SECOND LIST) Enter element for node #%d: ",i+1);
    scanf("%s",str);
    second = addNode(second,str);
  }
  clrscr();
  printf("\nFirst list : ");
  display(first);
  printf("\nSecond list: ");
  display(second);
  printf("\nMerged list: ");
  merged = mergeList(first, reverseList(second));
  display(merged);
  getch();
  return 0;
}