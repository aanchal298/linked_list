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
struct ll * merge(struct ll *a,struct ll *b)
{
    struct ll *temp;
    temp=(ll*)malloc(sizeof(ll));
    if(a==NULL)
        return b;
    if(b==NULL)
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
struct ll * split(struct ll *head)
{
    struct ll *s=head,*f=head;
    while(s && f && f->next)
    {
        f=f->next->next;
        s=s->next;
    }
    return s;
}
struct ll * pairwiseswap(struct ll **head)
{
    if((*head)==NULL || (*head)->next==NULL)
        return (*head);
    struct ll *p,*q,*temp;
    p=(*head);
    q=(*head)->next;
    temp=(*head)->next->next;
    q->next=p;
    p->next=pairwiseswap(&temp);
    return q;
}
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 1);
    insertbeginning(&head, 10);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    insertbeginning(&head, 54);
    insertbeginning(&head, 4);

    display(head);
    head=pairwiseswap(&head);
    display(head);
    return 0;
}

