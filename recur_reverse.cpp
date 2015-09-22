#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct ll *next;
    int val;
};

void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->val=n;
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
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
void countn(struct ll *head,int n)
{
    struct ll *p=head;
    int c=0;
    while(p!=NULL)
    {
        if(p->val==n)
            c++;
        p=p->next;
    }
    cout<<c<<endl;
}
void recurreverse(struct ll **head)
{
    if((*head)==NULL)
        return;
    struct ll *first,*rest;
    first=(*head);
    rest=(*head)->next;
    if(rest==NULL)
        return;
    recurreverse(&rest);
    first->next->next=first;
    first->next=NULL;
    (*head)=rest;

}
int main()
{
    struct ll *head=NULL;
    //insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 54);
    insertbeginning(&head, 52);
    insertbeginning(&head, 56);
    insertbeginning(&head, 57);
    insertbeginning(&head, 52);
    display(head);
    recurreverse(&head);
    display(head);
    cout<<endl;

    return 0;
}
