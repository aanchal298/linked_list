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
void detectloop(struct ll *head)
{
    struct ll *s=head,*f=head,*tatu,*matu=head,*p;
    while(f->next!= NULL && s!=NULL && f!=NULL)
    {
        f=f->next->next;
        s=s->next;
        if(f==s)
        {
            tatu=s;
            break;
        }
    }

    while(1)
    {
        p=tatu;
        while(p->next!=tatu)
        {

            if(p->next==matu)
            {
                p->next=NULL;
                return;
            }
             p=p->next;
        }
        matu=matu->next;

    }

}

int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 5);
    insertbeginning(&head, 4);
   // insertbeginning(&head, 51);
   // insertbeginning(&head, 54);
    struct ll *head2=NULL;
    insertbeginning(&head, 3);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);
   // insertbeginning(&head2, 54);
    head->next->next->next->next->next=head->next;
       detectloop(head);
    display(head);
    return 0;
}

