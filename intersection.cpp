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
void intersect(struct ll *head1,struct ll *head2)
{
    if(head1==NULL || head2==NULL)
        return ;
    struct ll *p=head1,*q=head2,*a=NULL,*head3=NULL;
    while(p && q)
    {
        if(p->data==q->data)
        {
            struct ll *newnode=(ll*)malloc(sizeof(ll));
            newnode->data=p->data;
            newnode->next=NULL;
            if(head3==NULL)
            {
                a=newnode;
                head3=a;
            }
            else
            {
                a->next=newnode;
                a=a->next;
            }
          p=p->next;
          q=q->next;
        }
        else if(p->data > q->data)
            q=q->next;
        else if(p->data < q->data)
            p=p->next;
    }
    display(head3);
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
    intersect(head,head2);
    return 0;
}


