#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct ll *next;
    int
    data;
};
int count(struct ll *head)
{
    if(head==NULL)
        return 0;
    struct ll *p=head;
    int c=1;
    while(p->next!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}

void printmid(struct ll *head)
{
     struct ll *i=head,*j=head;
     while(j->next!=NULL&&j->next->next!=NULL)
     {
         i=i->next;
         j=j->next->next;
     }
    cout<<i->data<<endl;
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
void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
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
void insertend(struct ll **head,int n)
{
    struct ll *node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=NULL;
    if((*head)==NULL)
    {
        (*head)=node;
    }
    else
    {
        struct ll *p=(*head);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=node;
    }
}
struct ll * intersect(struct ll *h1,struct ll *h2)
{
    struct ll *a=h1,*b=h2,*c;
    int c1=1,c2=1;
    while(a->next!=NULL)
    {
        a=a->next;
        c1++;
    }
    while(b->next!=NULL)
    {
        b=b->next;
        c2++;
    }
    int d=c1-c2;
    if(d>0)
    {
        a=h1;
        int cc=0;
        while(cc!=d)
        {
            a=a->next;
            cc++;
        }
        b=h2;
        while(a&&b)
        {
            if(a==b)
                return a;
            a=a->next;
            b=b->next;
        }
    }
    else
    {
        b=h2;
        int cc=0;
        while(cc!=d)
        {
            b=b->next;
            cc++;
        }
        a=h1;
        while(a&&b)
        {
            if(a==b)
                return a;
            a=a->next;
            b=b->next;
        }
    }
};

int main()
{

    struct ll *head1=NULL,*head2=NULL;
    insertbeginning(&head2,8);
    insertbeginning(&head2,7);
    insertend(&head1,9);
    insertend(&head1,1);
    insertend(&head1,2);
    insertend(&head1,3);
    struct ll *newnode;
    newnode=(ll*)malloc(sizeof(ll));
    newnode->data=4;
    newnode->next=NULL;
    head2->next->next=newnode;
    head1->next->next->next->next=newnode;
    insertend(&head1,5);
    insertend(&head1,6);
    insertend(&head1,7);
    display(head1);
    display(head2);
    struct ll *p=intersect(head1,head2);
    cout<<p->data<<endl;
    return 0;
}

