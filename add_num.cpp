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

struct ll * add(struct ll *first,struct ll *second)
{
    struct ll *a=first,*b=second,*res,*rhead=NULL,*newnode;
    int sum=0,carry=0;
    while(a!=NULL || b!=NULL)
    {
        int sum= carry + (a? a->data:0) +(b?b->data:0);
        newnode=(ll*)malloc(sizeof(ll));
        newnode->data=sum%10;
        newnode->next=NULL;
        if(rhead==NULL)
        {
            res=newnode;
            rhead=res;
        }
        else{
            res->next=newnode;
            res=res->next;
        }
        carry=sum/10;
        if(a)
            a=a->next;
        if(b)
            b=b->next;
    }
    if(carry>0)
    {
        newnode=(ll*)malloc(sizeof(ll));
        newnode->data=carry;
        newnode->next=NULL;
        res->next=newnode;
    }
    return rhead;
};
void reverse(struct ll **head)
{
    if((*head)==NULL)
        return;
    struct ll *first,*rest;
    first=(*head);

    rest=(*head)->next;
    if(rest==NULL)
        return;
    reverse(&rest);
    first->next->next=first;
    first->next=NULL;
    (*head)=rest;
}


int main()
{
    struct ll *head1=NULL;
    struct ll *head2=NULL;
    insertbeginning(&head1, 8);
    insertbeginning(&head1, 4);
    display(head1);
    reverse(&head1);
    insertbeginning(&head2, 7);
    insertbeginning(&head2, 5);
    insertbeginning(&head2, 9);
    insertbeginning(&head2, 4);
    insertbeginning(&head2, 6);
    display(head2);
    reverse(&head2);

   // insertbeginning(&head2, 54);

    struct ll *yy=add(head1,head2);
    reverse(&yy);
    display(yy);

    return 0;
}

