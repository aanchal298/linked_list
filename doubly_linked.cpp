#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *prev;
    struct ll *next;
};
void insertbeginning(struct ll **head,int n)
{
    struct ll *newnode=(ll*)malloc(sizeof(ll));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    if((*head)==NULL)
    {
        (*head)=newnode;
    }
    else
    {
        struct ll *p=(*head);
        p->prev=newnode;
        newnode->next=p;
        (*head)=newnode;
    }
}
void insertend(struct ll **head,int n)
{
    struct ll *newnode,*p,*q;
    newnode=(ll*)malloc(sizeof(ll));
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
void display(struct ll *head)
{
    if((head) == NULL)
        return;
    struct ll *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void deletebeginning(struct ll **head)
{
    if((*head)==NULL)
        return;
    struct ll *p ,*q;
    q=(*head);
    p=(*head)->next;
    free(q);
    p->prev=NULL;
    (*head)=p;
}
void deleteend(struct ll **head)
{
    if((*head)==NULL)
        return;
    struct ll *p,*q;
    p=(*head);
    while(p->next!=NULL)
        p=p->next;
    q=p->prev;
    q->next=NULL;
}
void deletepar(struct ll **head,struct ll *node)
{
    if((*head)==NULL)
        return;

    struct ll *h=(*head),*p,*q;
    while(h!=NULL)
    {
        if(h==node)
        {
            p=h->prev;
            q=h->next;
            p->next=q;
            q->prev=p;
            break;
        }
        h=h->next;
    }
}
int main()
{
    struct ll *head=NULL;
    int y;
    cout<<"1.insertbeginning 2.insertend 3.deletebeginning 4.deleteend 5.display"<<endl;
    do
    {
        cin>>y;
        switch(y)
        {
            case 1:
            {
                int n;
                cin>>n;
                insertbeginning(&head,n);
                break;
            }
            case 2:
            {
                int n;
                cin>>n;
                insertend(&head,n);
                break;
            }
            case 3:
            {
                deletebeginning(&head);
                break;
            }
            case 4:
            {
                deleteend(&head);
                break;
            }
            case 5:
            {
                display(head);
                break;
            }
            case 6:
            {
                //cin>>n;
                deletepar(&head,head->next);

            }
        }

    }while(y>0);
    return 0;
}
