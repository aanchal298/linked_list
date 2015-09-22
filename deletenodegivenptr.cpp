#include<bits/stdc++.h>
using namespace std;
struct ll{
    int val;
    struct ll *next;
};
void deletegiven(struct ll *node)
{
    int yy=node->next->val;
    node->next=node->next->next;
    node->val=yy;

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
    display(head);
    deletegiven(head->next);
    display(head);
    return 0;

}
