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
void rotate(struct ll **head,int k)
{
    if(k==0)
        return;
    struct ll *p=(*head),*n,*c,*d;
    int count=1;
    while(p && count!=k)
    {
        p=p->next;
        count++;
    }
    n=p->next;
    d=n;
    while(d->next!=NULL)
        d=d->next;
    c=(*head);
    d->next=c;
    p->next=NULL;
    (*head)=n;

}
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 60);
    insertbeginning(&head, 50);
    insertbeginning(&head, 40);
    insertbeginning(&head, 30);
    insertbeginning(&head, 20);
    insertbeginning(&head, 10);
    display(head);
    rotate(&head,4);
    display(head);

    return 0;
}

