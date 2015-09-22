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
struct ll * reversenodes(struct ll *head,int k)
{
    int count=1;
    struct ll *p=NULL,*c=(head),*n,*temp;
    if((head)==NULL || (head)->next==NULL)
        return head;

    while(c!=NULL && count<=k)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        count++;
    }
    (head)->next=reversenodes(c,k);
    return p;
}
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

    display(head);
    pp=reversenodes(head,2);
    display(pp);

    return 0;
}

