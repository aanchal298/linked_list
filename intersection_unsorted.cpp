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
void intersection(struct ll *head1,struct ll *head2)
{
    if(head1==NULL || head2==NULL)
        return;
    struct ll *res,*rhead=NULL,*a=head1,*b=head2;

    while(a)
    {
        b=head2;
        while(b)
        {
            if(a->data==b->data)
            {
                if(rhead==NULL)
                {
                    struct ll *nenode=(ll*)malloc(sizeof(ll));
                    nenode->data=a->data;
                    nenode->next=NULL;
                    res=nenode;
                    rhead=nenode;
                }
                else
                {
                    struct ll *nenode=(ll*)malloc(sizeof(ll));
                    nenode->data=a->data;
                    nenode->next=NULL;
                    res->next=nenode;
                    res=res->next;
                }
                break;
            }
            b=b->next;
        }
        a=a->next;
    }
    display(rhead);



}
int main()
{
    struct ll *head=NULL,*pp,*head2=NULL;
    insertbeginning(&head, 10);
    insertbeginning(&head, 15);
    insertbeginning(&head, 4);
    insertbeginning(&head, 20);
    insertbeginning(&head2, 8);
    insertbeginning(&head2, 2);
    insertbeginning(&head2, 4);
    insertbeginning(&head2, 10);
    display(head);
    display(head2);
    intersection(head,head2);

    return 0;
}
