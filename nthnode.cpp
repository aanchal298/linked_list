#include<bits/stdc++.h>
using namespace std;
struct ll{
    int val;
    struct ll *next;
};
struct ll * nthnode(struct ll *head,int n)
{
    struct ll *p=head;
    int c=1;
    while(c!=n)
    {
        p = p->next;
        c++;
    }
    return p;
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

int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 1);
    insertbeginning(&head, 4);
    insertbeginning(&head, 1);
    insertbeginning(&head, 12);
    insertbeginning(&head, 1);
    struct ll *dg=nthnode(head,3);
    cout<<dg->val<<endl;
    return 0;

}
