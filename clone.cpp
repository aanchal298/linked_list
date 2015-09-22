#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
    struct ll *arbit;
};

void insertend(struct ll **head,int n)
{
    struct ll *p,*newnode;
    newnode=(ll*)malloc(sizeof(ll));
    newnode->data=n;
    newnode->next=NULL;
    newnode->arbit=NULL;
    if((*head)==NULL)
        (*head)=newnode;
    else
    {
        p=(*head);
        while(p->next!=NULL)
            p=p->next;
        p->next=newnode;
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
void clone(struct ll *head)
{

    struct ll *p=NULL,*c=head,*n;
    while(c!=NULL)
    {
        struct ll *newnode=(ll*)malloc(sizeof(ll));
        newnode->data=c->data;
        newnode->next=c->next;
        c->next=newnode;
        if(c->next->next)
            c=c->next->next;
        else break;
    }
    c=head;
    while(c!=NULL)
    {
        c->next->arbit=c->arbit->next;
        if(c->next->next)
            c=c->next->next;
        else
            break;
    }
    c=head;
    struct ll *rhead=NULL,*r;
    rhead=head->next;
    r=head->next;
    while(c)
    {

        c->next=c->next->next;
        c=c->next;
        if(r->next)
        {
            r->next=r->next->next;
            r=r->next;
        }
        else break;
    }
    p=head;int i;
    for(i=0;i<5;i++)
    {
        cout<<p->arbit->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    struct ll *head=NULL;
    insertend(&head,1);
    insertend(&head,2);
    insertend(&head,3);
    insertend(&head,4);
    insertend(&head,5);
    head->arbit=head->next->next;
    head->next->arbit=head;
    head->next->next->arbit=head->next->next->next->next;
    head->next->next->next->arbit=head->next->next;
    head->next->next->next->next->arbit=head->next;
    clone(head);
    return 0;

}
