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
void split(struct ll *head,struct ll **a,struct ll **b)
{
    if(head==NULL || head->next==NULL)
    {
        (*a)=head;
        (*b)=NULL;
    }
    struct ll *p=NULL,*s=head,*f=head;
    while(s && f && f->next)
    {
        f=f->next->next;
        p=s;
        s=s->next;
    }
    (*a)=head;
    p->next=NULL;
    (*b)=s;
}
struct ll * merge(struct ll *a,struct ll *b)
{
    struct ll *temp;
    temp=(ll*)malloc(sizeof(ll));
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->data > b->data)
    {
        temp->data=b->data;
        temp->next=merge(a,b->next);
    }
    else if(a->data < b->data)
    {
        temp->data=a->data;
        temp->next=merge(a->next,b);
    }
    else if(a->data = b->data)
    {
        temp->data=a->data;
        temp->next=merge(a->next,b->next);
    }
    return temp;
}

void mergesort(struct ll **head)
{
    struct ll *hh=(*head);
    if(hh==NULL || hh->next==NULL)
        return;
    struct ll *a,*b;
    split(hh,&a,&b);
    mergesort(&a);
    mergesort(&b);
    (*head)=merge(a,b);
}



int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 11);
    insertbeginning(&head, 1);
    insertbeginning(&head, 2);
    insertbeginning(&head, 6);
    insertbeginning(&head, 3);
    insertbeginning(&head, 5);
    insertbeginning(&head, 9);
    insertbeginning(&head, 10);
    display(head);
    mergesort(&head);
    display(head);
    return 0;
}
