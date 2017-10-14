//MERGING OF TWO LINKED LISTS
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
struct node
{
   int data;
   struct node* next;
};
void MoveNode(struct node** destRef, struct node** sourceRef);
void  insert(struct node** head,int x)
  {
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;
  if(*head==NULL)
    {
      *head=temp;
    }
    else
    {
       struct node* temp1=*head;
       while(temp1->next!=NULL)
       temp1=temp1->next;
       temp1->next=temp;
    }
  }
struct node* SortedMerge(struct node* a, struct node* b)
{
    
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}
void print(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void MoveNode(struct node** destRef, struct node** sourceRef)
{
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}
int main()
  {
   struct node* head1=NULL;
   struct node* head2=NULL;
   struct node* res=NULL;
    insert(&head1,2);
    insert(&head1,4);
    insert(&head1,6);
    insert(&head1,8);
    insert(&head2,1);
    insert(&head2,3);
    insert(&head2,5);
    insert(&head2,7);
     res = SortedMerge(head1, head2);
 
    printf("Merged Linked List is: \n");
    print(res);
 
    return 0;
  }
