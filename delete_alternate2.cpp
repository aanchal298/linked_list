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

void delalt(struct ll *head)
{
    struct ll *p=head;
    while(1)
    {
        if(p==NULL)
        return;
        if(p->next==NULL)
            return;
        p->next=p->next->next;
        p=p->next;
    }
}
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 52);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 15);
    insertbeginning(&head, 10);
    insertbeginning(&head, 7);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    display(head);
    delalt(head);
    display(head);
    return 0;
}


