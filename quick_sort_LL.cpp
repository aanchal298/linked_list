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
struct ll * findend(struct ll *head)
{
    struct ll *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
};
struct ll * partition(struct ll *h,struct ll *e,struct ll **nh,struct ll **ne)
{
    struct ll *c=h,*p=NULL,*tail;
    struct ll *pivot=e;
    tail=pivot;
    while(c!=pivot)
    {
        if(c->data > pivot->data)
        {
            p=c;
            struct ll *temp=c->next;
            (*ne)->next=c;
            (*ne)=c;
            c=temp;
        }
        else
        {
            if(p)
                p->next=c->next;
            struct ll *oo=c->next;
            c->next=NULL;
            tail->next=c;
            tail=c;
            c=oo;
        }
    }
    if((*nh)==NULL)
        (*nh)=pivot;
    return pivot;
};
struct ll *quickrecur(struct ll *h,struct ll *e)
{
    struct ll *nh=NULL,*ne=NULL;
    if(h==NULL || h==e)
        return h;
    struct ll *pivot=partition(h,e,&nh,&ne);
    if(pivot!=nh)
    {
        struct ll *q=nh;
        while(q->next!=pivot)
            q=q->next;
        q->next=NULL;
        nh=quickrecur(nh,q);
        struct ll *temp=findend(nh);
        temp->next=pivot;

    }
    pivot->next=quickrecur(pivot->next,ne);
    return nh;
};


void quicksort(struct ll **head)
{
    struct ll *e=findend((*head));
    (*head)=quickrecur((*head),e);
}


int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,5);
    insertbeginning(&head,20);
    insertbeginning(&head,4);
    insertbeginning(&head,3);
    insertbeginning(&head,30);
    display(head);
    quicksort(&head);
    display(head);
    return 0;
}
