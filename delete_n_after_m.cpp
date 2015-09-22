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
struct ll * deleten(struct ll *head,int n,int m,int b)
{
    if(head==NULL)
        return NULL;
    struct ll *p=head,*q;
    int count=1;
    if(b==0)
    {
        while(p!=NULL && count <=m)
        {
            p=p->next;
            count++;
        }
        q=p->next;
        if(p->next)
           p->next=deleten(q,n,m,1);

        return head;
    }
    else if(b==1)
    {
        while(p!=NULL && count<=n)
        {
            p=p->next;
            count++;
        }
        if(p->next)
        return(deleten(p->next,m,n,0));
        else
            return NULL;
    }
};
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 1);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    insertbeginning(&head, 4);
    insertbeginning(&head, 3);
    insertbeginning(&head, 6);
     insertbeginning(&head, 13);
    insertbeginning(&head, 14);
    insertbeginning(&head, 15);
    insertbeginning(&head, 0);
    insertbeginning(&head, 20);
    insertbeginning(&head, 30);
    insertbeginning(&head, 40);
    insertbeginning(&head, 50);
    insertbeginning(&head, 60);
    insertbeginning(&head, 70);

    display(head);
    pp=deleten(head,3,3,0);
    display(pp);

    return 0;
}

