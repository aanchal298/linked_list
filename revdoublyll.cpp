#include<bits/stdc++.h>
using namespace std;

struct doublyll{
    int data;
    struct doublyll *prev;
    struct doublyll *next;
};
void insertbeginning(struct doublyll **head,int n)
{
    struct doublyll *newnode=(doublyll*)malloc(sizeof(doublyll));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    if((*head)==NULL)
    {
        (*head)=newnode;
    }
    else
    {
        struct doublyll *p=(*head);
        p->prev=newnode;
        newnode->next=p;
        (*head)=newnode;
    }
}
void insertend(struct doublyll **head,int n)
{
    struct doublyll *newnode,*p,*q;
    newnode=(doublyll*)malloc(sizeof(doublyll));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    if((*head)==NULL)
    {
        (*head)=newnode;
    }
    else
    {
        p=(*head);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=newnode;
        newnode->prev=p;
    }
}
void display(struct doublyll *head)
{
    if((head) == NULL)
        return;
    struct doublyll *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void deletebeginning(struct doublyll **head)
{
    if((*head)==NULL)
        return;
    struct doublyll *p ,*q;
    q=(*head);
    p=(*head)->next;
    free(q);
    p->prev=NULL;
    (*head)=p;
}
void deleteend(struct doublyll **head)
{
    if((*head)==NULL)
        return;
    struct doublyll *p,*q;
    p=(*head);
    while(p->next!=NULL)
        p=p->next;
    q=p->prev;
    q->next=NULL;
}
void reversed(struct doublyll **head)
{
    if((*head)==NULL)
        return;

    struct doublyll *c=(*head);
    struct doublyll *n=NULL;
    while(c)
    {
        n=c->prev;
        c->prev=c->next;
        c->next=n;
        c=c->prev;
    }
    if(n!=NULL)
    (*head) = n->prev;
}
int main()
{
    struct doublyll *head=NULL;
    insertbeginning(&head,10);
    insertbeginning(&head,9);
    insertbeginning(&head,8);
    insertbeginning(&head,7);
    insertbeginning(&head,6);
    insertbeginning(&head,5);
    display(head);
    reversed(&head);
    display(head);
    return 0;
}
