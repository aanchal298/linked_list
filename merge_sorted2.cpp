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
struct ll * merge(struct ll *h1,struct ll *h2)
{
    if(h1==NULL)
        return h2;
    else if(h2==NULL)
        return h1;

    struct ll *p,*head3=NULL;
    struct ll *a=h1,*b=h2;
    while(a&&b)
    {
        struct ll *newnode=(ll*)malloc(sizeof(ll));
        newnode->next=NULL;
        if(a->data > b->data)
        {
            newnode->data=b->data;
            b=b->next;
        }
        else if(a->data==b->data)
        {
            newnode->data=a->data;
            a=a->next;
            b=b->next;
        }
        else if(a->data < b->data)
        {
            newnode->data=a->data;
            a=a->next;
        }
        if(head3==NULL)
        {
            p=newnode;
            head3=p;
        }
        else
        {
            p->next=newnode;
            p=p->next;
        }
    }
    if(b)
        p->next=b;
    if(a)
        p->next=a;
    return head3;

}


int main()
{
    struct ll *head=NULL,*head1=NULL;
    insertbeginning(&head, 15);
    insertbeginning(&head, 10);
    insertbeginning(&head, 5);
    insertbeginning(&head1, 20);
    insertbeginning(&head1, 3);
    insertbeginning(&head1, 2);

    display(head);
    display(head1);
    struct ll *t=merge(head1,head);
    display(t);
    return 0;
}
