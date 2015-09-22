#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
};
void insertbeginning(struct ll **head,int n)
{
    struct ll *node,*c;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=node;
    if((*head)==NULL)
        (*head)=node;
    else
    {
        c=(*head);
        while(c->next!=(*head))
            c=c->next;

        c->next=node;
        node->next=(*head);
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
        while(p->next!=head)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<p->data;
        cout<<endl;
    }
}
void sortedinsert(struct ll **head,int n)
{
    struct ll *newnode,*c=(*head),*p=NULL;
    newnode=(ll*)malloc(sizeof(ll));
    newnode->data=n;
    newnode->next=NULL;
    if((*head)->data > n)
    {
        while(c->next!=(*head))
            c=c->next;
        c->next=newnode;
        newnode->next=(*head);
        (*head)=newnode;
    }
    else
    {
        while(c->data < n  )
        {
            if(c->next==(*head))
                break;
            p=c;
            c=c->next;
        }
        if(c->next!=(*head))
        {
             p->next=newnode;
            newnode->next=c;
        }
        else
        {
            if(c->data < n)
            {
                c->next=newnode;
                newnode->next=(*head);
            }
        }
    }
}

int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 10);
    insertbeginning(&head, 8);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    display(head);
    sortedinsert(&head,1);
    display(head);
    return 0;
}

