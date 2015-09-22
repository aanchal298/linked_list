#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct ll *next;
    int data;
};
int count(struct ll *head)
{
    if(head==NULL)
        return 0;
    struct ll *p=head;
    int c=1;
    while(p->next!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}


void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=NULL;
    if((*head)==NULL)
        (*head)=node;
    else
    {
        struct ll *p=(*head);
        node->next=p;
        (*head)=node;
    }

}
void display(struct ll *head)
{
    if(head==NULL)
        return ;
    else
    {
        struct ll *p=head;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
struct ll * intersect(struct ll *head1,struct ll *head2)
{
    if(head1==NULL || head2==NULL)
        return NULL;
    if(head1->data > head2->data)
        return intersect(head1,head2->next);
    else if(head2->data > head1->data)
        return intersect(head1->next,head2);
    struct ll *temp=(ll*)malloc(sizeof(ll));
    temp->data=head1->data;
    temp->next=intersect(head1->next,head2->next);
    return temp;

}

int main()
{
    struct ll *head=NULL,*head2=NULL;
    //insertbeginning(&head, 51);
    //insertbeginning(&head, 52);
   // insertbeginning(&head, 53);
    insertbeginning(&head, 15);
   // insertbeginning(&head, 10);
    insertbeginning(&head, 7);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);

    display(head);
     insertbeginning(&head2, 15);
    insertbeginning(&head2, 10);
    insertbeginning(&head2, 7);
    //insertbeginning(&head2, 5);
    insertbeginning(&head2, 2);
    display(head2);
    struct ll *t=intersect(head,head2);
    display(t);
    return 0;
}


