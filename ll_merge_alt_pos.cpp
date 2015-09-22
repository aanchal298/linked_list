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

void merge(struct ll *head1,struct ll **head2)
{
    if(head1==NULL || (*head2)==NULL)
        return;
    struct ll *a=head1,*b=(*head2),*temp,*temp2;
    while(a!=NULL && b!=NULL)
    {
        temp=a->next;
        a->next=b;
        temp2 = b->next;
        b->next=temp;
        (*head2)=temp2;
        a=a->next->next;
        b=temp2;
    }

}
int main()
{
    struct ll *head=NULL,*pp,*head2=NULL;
    insertbeginning(&head, 11);
    insertbeginning(&head, 13);
    insertbeginning(&head, 17);
    insertbeginning(&head, 7);
    insertbeginning(&head, 5);

    display(head);
    insertbeginning(&head2, 6);
    insertbeginning(&head2, 4);
    insertbeginning(&head2, 2);
    //insertbeginning(&head2, 10);
   // insertbeginning(&head2, 12);
    display(head2);
    merge(head,&head2);
    display(head);
    display(head2);

    return 0;
}
