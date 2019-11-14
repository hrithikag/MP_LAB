#include<stdio.h>
#include<conio.h>
#include<process.h>
#define size 5

void enqueue(int q[],int *r,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		(*r)++;
		scanf("%d",&q[*r]);
	}
}


void divi(int q[],int *f,int n)
{
	int count,i;
	while(*f<n)
	{

			if(q[*f]%1==0&&q[*f]%2==0&&q[*f]%3==0&&q[*f]%4==0&&q[*f]%5==0&&q[*f]%6==0&&q[*f]%7==0&&q[*f]%8==0&&q[*f]%9==0&&q[*f]%10==0)
			count=10;
			else
			count=0;


		if(count==10)
	       printf("%d evenly divisible \n",q[*f]);
	       else

		printf("%d not divisible \n",q[*f]);

		(*f)++;
	}

}
void main()
{
	int q[20];
	int r,f,n;
	clrscr();
	r=-1;
	f=0;
	printf("Enter the number of elements in queue\n");
	scanf("%d",&n);
	printf("enter whole numbers\n");
	enqueue(q,&r,n);
	divi(q,&f,n);

	getch();
}