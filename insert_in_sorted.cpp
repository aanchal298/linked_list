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

void printmid(struct ll *head)
{
     struct ll *i=head,*j=head;
     while(j->next!=NULL&&j->next->next!=NULL)
     {
         i=i->next;
         j=j->next->next;
     }
    cout<<i->
    data<<endl;
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
void insertin(struct ll **head,int num)
{
    struct ll *newnode;
    newnode=(ll*)malloc(sizeof(ll));
    newnode->data=num;
    newnode->next=NULL;
    if((*head)==NULL)
        (*head)=newnode;
    else if((*head)->data > num)
    {
        struct ll * ii=(*head);
        (*head)=newnode;
        newnode->next=ii;
    }
    else
    {
        struct ll *p=(*head);
        while(p->next)
        {
            if(p->data < num && p->next->data > num)
            {
                struct ll * j=p->next;
                p->next=newnode;
                newnode->next=j;
                break;
            }
            else
                p=p->next;

        }
        if(p->data < num)
            p->next=newnode;
    }
}
void printrev(struct ll *head)
{
    if(head==NULL)
        return;
    printrev(head->next);
    cout<<head->data<<" ";

}
int main()
{
    struct ll *head=NULL;
    //insertbeginning(&head, 51);
    //insertbeginning(&head, 52);
   // insertbeginning(&head, 53);
    insertbeginning(&head, 15);
    insertbeginning(&head, 10);
    insertbeginning(&head, 7);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    display(head);
    printrev(head);
    return 0;
}
