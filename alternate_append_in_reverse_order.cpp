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
void function(struct ll *head)
{
    struct ll *p=head,*e,*ehead=NULL;
    struct ll *newnode;
    while(p && p->next && p->next->next)
    {
        newnode=(ll*)malloc(sizeof(ll));
        newnode->data=p->next->data;
        newnode->next=NULL;
        if(ehead==NULL)
        {
            e=newnode;
            ehead=e;
        }
        else
        {
            newnode->next=ehead;
            ehead=newnode;
        }
        if(p->next)
        p->next=p->next->next;
        p=p->next;
    }
    p=head;
    while(p->next!=NULL)
        p=p->next;
    p->next=ehead;
}
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 6);
    insertbeginning(&head, 5);
    insertbeginning(&head, 4);
    insertbeginning(&head, 3);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);

    display(head);
    function(head);
    display(head);
    return 0;
}

