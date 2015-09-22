#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct ll *next;
    int data;
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
void swapalt(struct ll **head)
{
    struct ll *p,*q,*r;
    r=(*head);
    p=r->next;
    q=p->next;
    p->next=r;
    r->next=q;
    (*head)=p;

    p=(*head)->next;

    while(1)
    {
        if(p->next==NULL)
            break;
        if(p->next->next==NULL)
            break;
        q=p->next;
        r=q->next;
        cout<<p->data<<" "<<q->data<<" "<<r->data<<endl;
        q->next=r->next;
        r->next=q;
         p->next=r;
        if(p->next!=NULL)
            p=p->next->next;
        if(p==NULL)
            break;

    }
}

int main()
{
    struct ll *head=NULL;
   // insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 15);
    insertbeginning(&head, 10);
    insertbeginning(&head, 7);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    display(head);
    swapalt(&head);
    display(head);
    return 0;
}


