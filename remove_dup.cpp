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
void removedup(struct ll *head)
{
    struct ll *p=head,*n,*nn;
    while(p->next!=NULL)
    {
        if(p->data == p->next->data)
        {
            n=p->next;
            nn=p->next->next;
            free(n);
            p->next=nn;
        }
        else
            p=p->next;
    }

}

int main()
{
    struct ll *head=NULL;
    //insertbeginning(&head, 51);
    //insertbeginning(&head, 52);
   // insertbeginning(&head, 53);
    insertbeginning(&head, 11);
    insertbeginning(&head, 11);
    insertbeginning(&head, 11);
    insertbeginning(&head, 13);
    insertbeginning(&head, 13);
    insertbeginning(&head, 20);
    display(head);
    removedup(head);
    display(head);
    return 0;
}

