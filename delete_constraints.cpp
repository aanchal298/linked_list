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
void deletenode(struct ll *head,struct ll * node)
{
    struct ll *p,*q;
    if(head==NULL || node==NULL)
        return;
    if(head==node)
    {
        p=head->next;
        head->data=p->data;
        head->next=p->next;
        free(p);
    }
    else
    {
        p=head;
        while(p)
        {
            if(p==node)
            {
                q->next=p->next;
                free(p);
                break;
            }
            q=p;
            p=p->next;
        }
    }
}
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 53);
    insertbeginning(&head, 52);
    insertbeginning(&head, 51);
   // insertbeginning(&head, 54);
    struct ll *head2=NULL;
    insertbeginning(&head, 50);
    insertbeginning(&head, 49);
    insertbeginning(&head, 48);

    display(head);
    deletenode(head,head);
    display(head);

    return 0;
}
