//	6. Write a program to create a Linked List of n elements and do the following  operaons:
// a) Insert at 1sst posion, last posion and nth posion. b) Delete at 1st posion, last posion and kth posion. 
// c) Check a given element is present or not in Linked list. 


#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node* next; 
};
struct node* head=NULL;

void print()
{
	struct node* current=head;
	while(current!=NULL)
	{
		printf("%d",current->data);
		printf(" -> ");
		current=current->next;
	}
	printf("NULL\n\n");
}
void insertatbeg(int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
}
void insertatend(int x){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		struct node* temp2=head;
	while(temp2->next!=NULL)
	  temp2=temp2->next;
	  temp2->next=temp;
	}
}
void insertn(int n,int value)
{  int i;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(head==NULL)
	{
		temp->next=head;
		head=temp;
	}
	struct node* temp3=head;
	for(i=0;i<n-2;i++)
	{
		temp3=temp3->next;
	}
	temp->next=temp3->next;
	temp3->next=temp;
}
void deletionfrombeg()
{
	struct node* temp2=head;
	if(head==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		head=head->next;
	}
}

void deletionfromk(int k)
{
	int i;
	struct node* temp3=head;
	if(head==NULL)printf("linked list is empty.\n");
	else if(k==1)head=head->next;
	else
	{
		struct node* temp4=head;
		for(i=0;i<k-2;i++)
		temp4=temp4->next;
		temp4->next=temp4->next->next;
		
	}
}

void deletionfromend()
{ int i;
	struct node* current=head;
	if(head==NULL)
	printf("linked list is empty\n");
	else
	{
		struct node* t=head;
		while(current->next!=NULL)
		{
			t=current;
			current=current->next;
		}
		t->next=NULL;
	}
}

void search(int x)
{
	struct node* current=head;
	while(current!=NULL)
	{
		if(current->data==x)
		{
			printf("element %d is present in the linked list\n\n",x);
			return;
		}
		
		current=current->next;
	}
	printf("element %d is not present in linked list\n",x);
}

int main()
{   //initial linked list is

   insertatend(9);
    insertatend(11);
    insertatend(12);
    insertatend(13);
    insertatend(14);
    printf("initial linked list is:\n");
    print();
   
	int i,n,choice;
	printf("-----------MENU-------------\n");
	printf("1.Insert at first position\n");
	printf("2.Insert at last position\n");
	printf("3.Insert at nth position\n");
	printf("4.Delete from   front position\n");
	printf("5.Delete from   end position\n");
	printf("6.Delete from  nth position\n");
	printf("7.Delete from   front position\n");
	printf("enter ur choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insertatbeg(1);
			insertatbeg(2);
		    insertatbeg(3);
		    print();
		    break;
		case 2:
		    	insertatend(4);
		    	insertatend(5);
		    	insertatend(6);
		    	print();
		    	break;
		case 3:
		insertn(2,10);
	    insertn(2,15);
	    insertn(2,9);
		print();
		   break; 	
			
   case 4:
 deletionfrombeg();  
 deletionfrombeg(); 
 print(); 
 break;
 
 
 case 5:
 		deletionfromend();
 		deletionfromend();
 		print();
 		break;
		
		
	case 6:
 deletionfromk(2);
 deletionfromk(1);
 deletionfromk(1);
 print();
 break;
	
	case 7:	
	search(5);
	search(50);
	return 0;
		}
}
