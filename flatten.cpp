#include<bits/stdc++.h>
using namespace std;
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
struct ll{
    int data;
    struct ll *next;
    struct ll *child;
};
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
void flatten(struct ll *head)
{
    struct ll *c=head,*t,*p=head;
    while(p->next!=NULL)
        p=p->next;
    t=p;
    while(c!=NULL)
    {
        if(c->child)
        {
            p=c->child;
            t->next=p;
            c->child=NULL;
            while(p->next!=NULL)
                p=p->next;
            t=p;
        }
        c=c->next;

    }
    display(head);
}

void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=NULL;
    node->child=NULL;
    if((*head)==NULL)
        (*head)=node;
    else
    {
        struct ll *p=(*head);
        node->next=p;
        (*head)=node;
    }

}
int main()
{
    struct ll *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*head5=NULL,*head6=NULL,*head7=NULL,*head8=NULL;
    insertbeginning(&head1,11);
    insertbeginning(&head1,7);
    insertbeginning(&head1,12);
    insertbeginning(&head1,5);
    insertbeginning(&head1,10);

    insertbeginning(&head2,13);
    insertbeginning(&head2,20);
    insertbeginning(&head2,4);

    insertbeginning(&head3,6);
    insertbeginning(&head3,17);

    insertbeginning(&head4,2);

    insertbeginning(&head5,16);

    insertbeginning(&head6,8);
    insertbeginning(&head6,9);

    insertbeginning(&head7,3);

    insertbeginning(&head8,15);
    insertbeginning(&head8,19);


    head1->child=head2;
    head1->next->next->next->child=head3;
    head2->next->child=head4;
    head2->next->next->child=head5;
    head5->child=head7;
    head3->child=head6;
    head6->child=head8;

    flatten(head1);
    return 0;
}
