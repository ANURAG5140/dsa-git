#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;


void insertatbeg(node **start,int item)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=*start;
	*start=ptr;
}
void insertatend(node **start,int item)
{
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(*start ==NULL)
	*start=ptr;
	else{
		last=*start;
		while(last->next!=NULL)
		last=last->next;
		last->next=ptr;
	}
}
void display(node *start)
{
	if(start==NULL)
	{
		printf("\n linked list is empty");
		return;
	}
	while(start!=NULL)
	{
		printf("%d->",start->info);
		start=start->next;
	}
}
void deleteatbeg(node **start)
{
	node *ptr;
	if(*start ==NULL)
	{
		printf("\n linked list is empty");
		return;
	}
	ptr=*start;
	*start=ptr->next;
	printf("\n deleted value=%d",ptr->info);
	free(ptr);
}
void deleteatend(node **start)
{
	node *ptr,*last;
	if(*start==NULL)
	{
		printf("\n linked list is empty");
		return;
	}
	if ((*start)-> next==NULL)
	{
		ptr =*start;
		*start=ptr->next;
		
	}
	else{
		last=*start;
		while(last->next->next!=NULL)
		last=last->next;
		ptr=last->next;
		last->next=NULL;
	}
	printf("\n deleted value %d",ptr->info);
	free(ptr);
}
void displayinrev(node *start)
{
	if(start->next!=NULL)
	displayinrev(start->next);
	printf("%d",start->info);
}
int main()
{
	int item,choice;
	node *head;
	head=NULL;
	while(1)
	{
		printf("\n ....linked list menu....\n");
		printf("\n 1 insert at beg");
		printf("\n 2 insert at end");
		printf("\n 3 delete at beg");
		printf("\n 4 delete at end");
		printf("\n 5 display in order");
		printf("\n 6 display in reverse");
		printf("\n 7 exit");
		printf("\n enter your choice:");
		scanf("%d",choice);
		switch(choice)
		{
			case 1: 
			printf("\n enter item=");
			scanf("%d",&item);
			insertatbeg(&head,item);
			break;
			
			case 2: 
			printf("\n enter item=");
			scanf("%d",&item);
			insertatend(&head,item);
			break;
			
			case 3: 
			
			deleteatbeg(&head);
			break;
			
			case 4: 
			
			deleteatend(&head);
			break;
			
			case 5: 
			
			display(head);
			break;
			
			case 6: 
			
			displayinrev(head);
			break;
			
			default: exit(1);
		}
		
	}
}
