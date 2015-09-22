#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
};
void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->
    data=n;
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

void split(struct ll *head)
{
    struct ll *p=head,*a,*b,*head1=NULL,*head2=NULL;
    if(head==NULL)
        return;
    while(p)
    {
        struct ll *newnode=(ll*)malloc(sizeof(ll));
        newnode->next=NULL;
        if(p->data==0)
        {
            newnode->data=0;
            if(head1==NULL)
            {
                a=newnode;
                head1=a;
            }
            else
            {
                a->next=newnode;
                a=a->next;
            }
        }
        else
        {
            newnode->data=1;
            if(head2==NULL)
            {
                b=newnode;
                head2=b;
            }
            else
            {
                b->next=newnode;
                b=b->next;
            }
        }
        p=p->next;
    }
    display(head1);
    display(head2);

}

int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,1);
    insertbeginning(&head,0);
    insertbeginning(&head,1);
    insertbeginning(&head,0);
    insertbeginning(&head,1);
    insertbeginning(&head,0);
    display(head);
    split(head);
    return 0;

}
