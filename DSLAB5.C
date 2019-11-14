#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node * NODE;

NODE getnode() {
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if (p != NULL) return p;
    else {
        printf("No Memory \n");
        return NULL;
    }
}

NODE insert_front(int item, NODE head) {
    NODE p;
    p = getnode();
    p -> data = item;
    p -> next = head;
    head = p;
    printf("Inserted \n");
    return head;
}

NODE insert_back(int item, NODE head) {
    NODE p, q;
    q = getnode();
    q -> data = item;
    q -> next = NULL;
    if (head == NULL) return q;
    p = head;
    while (p -> next != NULL) p = p -> next;
    p -> next = q;
    printf("Inserted \n");
    return head;
}

NODE insert_pos(int item, int pos, NODE head) {
    NODE curr, prev = NULL, newn;
    int count = 1;
    newn = getnode();
    newn -> data = item;
    newn -> next = NULL;
    if (head == NULL) {
	if (pos == 1) printf("Inserted \n");
	else printf("Invalid Position \n");
    }
    if (pos == 1) {
	newn -> next = head;
	head = newn;
	printf("Inserted \n");
	return head;
    } else {
	curr = head;
	while (curr != NULL && count != pos) {
	    prev = curr;
	    curr = curr -> next;
	    count ++;
	}
	if (count == pos) {
	    prev -> next = newn;
	    newn -> next = curr;
	    printf("Inserted \n");
	    return head;
	} else {
	    printf("Invalid Position \n");
	    return head;
	}
    }
}

NODE deletefront(NODE head) {

	NODE p = head;
	if (head== NULL) {
		printf("Empty \n");
		return head;}
	head = head->next;
	free(p);
	return head;
}
NODE deleterear(NODE head) {
	NODE p = head, prev;
	if (head == NULL) {
		printf("Empty \n");
		return NULL;
	}
	if (head -> next == NULL) {
		printf("Deleted \n");
		return NULL;
	}
	while (p -> next != NULL) {
		prev = p;
		p = p -> next;
	}
	free(p);
	prev -> next = NULL;
	return head;
}
NODE deleteval(NODE head, int val) {
	NODE curr = head, prev = NULL;
	int flag = 1;
	if (head == NULL)
	{
			printf("Empty \n");
	}
	if (curr != NULL && curr -> data == val) { // val is in head
		head = curr -> next;
		free(curr);
		printf("Deleted \n");
		curr = head;
	}
	while (curr -> next != NULL) {
		prev = curr;
		curr = curr -> next;
		if (curr -> data == val) {
			prev -> next = curr -> next;
			free(curr);
			flag = 0;
			printf("Deleted \n");
		}
	}
	if (flag == 1)
	{
		printf("Not Found \n");
	}
	return head;
}

NODE sort(NODE head){
	NODE p = head, q = NULL;
	int temp;
	if (head == NULL)
		return NULL;
	else
	{
		while (p -> next != NULL)
		{
			q = p -> next;
			while (q != NULL) {
				if (p -> data > q -> data) {
					temp = p -> data;
					p -> data = q -> data;
					q -> data = temp;
				}
				q = q -> next;
			}
			p = p -> next;
		}
		return head;
	}
}

NODE reverse(NODE head) {
	NODE curr = head, prev = NULL, nextn = NULL;
	if (head == NULL) return head;
	if (head -> next == NULL) return head;
	while (curr != NULL) {
		nextn = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nextn;
	}
	head = prev;
	return head;
}

NODE concatenate(NODE first, NODE sec) {
	NODE p = first;
	if (first == NULL) return sec;
	if (sec == NULL) return first;
	while (p -> next !=  NULL) p = p -> next;
	p -> next = sec;
	return first;
}

void display (NODE head) {
    NODE p;
    if (head == NULL) {
	printf("Empty List \n");
	return;
    }
    printf("\n");
    p = head;
    while (p != NULL) {
	printf(" %d ", p -> data);
	p = p -> next;
    }
}

int main() {
    int choice, pos, ele,val,wh;
    NODE head = NULL;
    NODE head1= NULL;
    clrscr();

    do {
	printf("\n-*-*-*-*-*-*-*-*-*-*-Main Menu-*-*-*-*-*-*-*-*-*-*-\n");
	printf("1.Enter from Front.\n");
	printf("2.Enter from End.\n");
	printf("3.Enter from Position. \n");
	printf("4.Delete element from front.\n");
	printf("5.Delete element from rear.\n");
	printf("6.Delete a certain value.\n");
	printf("7.Sort.\n");
	printf("8.Reverse.\n");
	printf("9.Concatenate.\n");
	printf("10.Display. \n");
	printf("11.Exit. \n");
	printf("---------------------------------\n");
	printf("Enter Choice:  \n");
	printf("---------------------------------\n");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: printf("Insert into which linked list (1/2): ");
		    scanf("%d",&wh);
		    printf("Enter Element \n");
		    scanf("%d", &ele);
		    if(wh==1)
		       head = insert_front(ele, head);
		    else if(wh==2)
		       head1= insert_front(ele,head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 2: printf("Insert into which linked list (1/2): ");
		    scanf("%d",&wh);
		    printf("Enter Element \n");
		    scanf("%d", &ele);
		    if(wh==1)
		       head = insert_back(ele, head);
		    else if(wh==2)
		       head1= insert_back(ele,head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 3: printf("Insert into which linked list (1/2): ");
		    scanf("%d",&wh);
		    printf("Enter Element and Position\n");
		    scanf("%d %d", &ele, &pos);
		    if(wh==1)
		       head = insert_pos(ele, pos, head);
		    else if(wh==2)
		       head1= insert_pos(ele,pos,head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 4: printf("Delete from which linked list (1/2): ");
		    scanf("%d",&wh);
		    if(wh==1)
		       head=deletefront(head);
		    else if(wh==2)
		       head1=deletefront(head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 5: printf("Delete from which linked list (1/2): ");
		    scanf("%d",&wh);
		    if(wh==1)
		       head=deleterear(head);
		    else if(wh==2)
		       head1=deleterear(head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 6: printf("Delete from which linked list (1/2): ");
		    scanf("%d",&wh);
		    printf("Enter element to be deleted\n");
		    scanf("%d",&val);
		    if(wh==1)
		       head=deleteval(head,val);
		    else if(wh==2)
		       head1=deleteval(head1,val);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 7: printf("Sort which linked list (1/2): ");
		    scanf("%d",&wh);
		    if(wh==1)
		       head=sort(head);
		    else if(wh==2)
		       head1=sort(head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 8: printf("Reverse which linked list (1/2): ");
		    scanf("%d",&wh);
		    if(wh==1)
		       head=reverse(head);
		    else if(wh==2)
		       head1=reverse(head1);
		    else
		       printf("Invalid! Only two linked lists exist.");
		    break;

	    case 9: printf("\nFirst List:\n");
		    display(head);
		    printf("\nSecond List:\n");
		    display(head1);
		    printf("\nConcatenated List:\n");
		    head=concatenate(head,head1);
		    display(head);
		    printf("\n");
		    break;

	    case 10: printf("Display which linked list? (1/2): ");
		     scanf("%d",&wh);
		     if(wh==1) display(head);
		     else if(wh==2) display(head1);
		     else
		       printf("Invalid! Only two linked lists exist.");
		     break;

	    case 11: exit(0);
		    break;

	    default: printf("Invalid Choice \n");
	}


    } while (choice != 11);

    return 0;
}