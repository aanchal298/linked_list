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

void segregate(struct ll **head)
{
    struct ll *e=(*head),*c=(*head),*d,*ee,*ss=(*head);
    while(e->next!=NULL)
        e=e->next;
    ee=e;
    while(c->data % 2!=0 && c!=ee)
    {
        d=c;
        c=c->next;
        e->next=d;
        d->next=NULL;
        e=e->next;
    }

    if(c->data%2==0)
    {
        (*head)=c;
        e->next=ee;
        ee->next=NULL;
    }
    else
    {
        if(ee->data%2!=0)
            e->next=ee;
        ee->next=NULL;
        (*head)=ss;
        return;
    }
    struct ll *prev=NULL;
    while(c!=ee)
    {
        if(c->data%2==0)
        {
            prev=c;
            c=c->next;
        }
        else
        {
            prev->next=c->next;
            d=c;
            e->next=d;
            d->next=NULL;
            e=e->next;
            c=prev->next;
        }
    }
    if(ee->data%2!=0)
    {
        prev->next=ee->next;
        ee->next=NULL;
        e->next=ee;
    }
}



int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 11);
   // insertbeginning(&head, 10);
    insertbeginning(&head, 9);
   //insertbeginning(&head, 6);
    struct ll *head2=NULL;
    //insertbeginning(&head, 4);
insertbeginning(&head, 3);
    insertbeginning(&head, 1);
   // insertbeginning(&head, 54);

    display(head);
    segregate(&head);
    display(head);
    return 0;
}
