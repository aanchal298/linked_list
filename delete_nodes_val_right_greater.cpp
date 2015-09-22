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

void deletenodes(struct ll *head)
{
    int max=0;
    struct ll *p=NULL,*c=(head);
    while(c)
    {
        if(c->data < max)
        {
            p->next=c->next;
            free(c);
            c=p->next;
        }
        if(c->data>max)
        {
             max=c->data;
             p=c;
             c=c->next;
        }
    }
}
void reverse(struct ll **head)
{
    struct ll *c=(*head),*p=NULL,*n;
    while(c)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    (*head)=p;
}
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 3);
    insertbeginning(&head, 2);
    insertbeginning(&head, 6);
    insertbeginning(&head, 5);
    struct ll *head2=NULL;
    insertbeginning(&head, 11);
    insertbeginning(&head, 10);
    insertbeginning(&head, 15);
    insertbeginning(&head2, 12);
    display(head);
    reverse(&head);
    display(head);
    deletenodes(head);
    reverse(&head);
    display(head);
    return 0;
}

