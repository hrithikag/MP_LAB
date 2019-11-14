#include<conio.h>
#include <stdio.h>
#include <stdlib.h>

#define size 5

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

NODE push(int item, NODE top, int *len) {
	NODE p;
	if (*len == size - 1) {
		printf("Stack Overflow \n");
		return top;
	}
	p = getnode();
	p -> data = item;
	p -> next = top;
	top = p;
	printf("Pushed! \n");
	(*len)++;
	return top;
}

NODE pop(NODE top, int *len) {
	NODE p = top;
	if (top == NULL) {
		printf("Underflow \n");
		return top;
	}
	printf("Popped! \n");
	top = p -> next;
	free(p);
	(*len)--;
	return top;
}

void display (NODE top) {
	NODE p;
	if (top == NULL) {
		printf("Empty List \n");
		return;
	}
	printf("\nStack: \n");
	p = top;
	while (p != NULL) {
		printf("%d \n", p -> data);
		p = p -> next;
	}
}

int main() {
	int choice, len = 0, ele;
	NODE top = NULL;

	do {
		clrscr();
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Exit \n");
		printf("Enter Choice: ");
		scanf("%d", &choice);

		switch (choice) {
		    case 1: printf("Enter Element: ");
			    scanf("%d", &ele);
			    top = push(ele, top, &len);
			    getch();
			    break;

		    case 2: top = pop(top, &len);
			    getch();
			    break;

		    case 3: display(top);
			    getch();
			    break;

		    case 4: exit(0);
			    break;
		    
		    default: printf("Invalid Choice \n");
		}

	} while (choice != 4);

	return 0;
}