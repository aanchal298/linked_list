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
void reverse(struct ll **head)
{
    struct ll *p,*c,*n;
    p=NULL;
    c=(*head);
    while(c!=NULL)
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
    //insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 54);
    insertbeginning(&head, 52);
    insertbeginning(&head, 56);
    insertbeginning(&head, 57);
    insertbeginning(&head, 52);
    display(head);
    reverse(&head);
    display(head);
    cout<<endl;

    return 0;
}
