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

struct ll * mergell(struct ll *h1,struct ll *h2)
{
    struct ll *temp=(ll*)malloc(sizeof(ll));
    if(h1==NULL)
    {
        temp=h2;
        return temp;
    }
    else if(h2==NULL)
    {
        temp=h1;
        return temp;
    }
    if(h1->data >= h2->data)
    {
        temp->data=h2->data;
        temp->next=mergell(h1,h2->next);
    }
    if(h2->data > h1->data)
    {
        temp->data=h1->data;
        temp->next=mergell(h1->next,h2);
    }
    return temp;
};
int main()
{
    struct ll *head=NULL,*head1=NULL;
    insertbeginning(&head, 15);
    insertbeginning(&head, 10);
    insertbeginning(&head, 5);
    insertbeginning(&head1, 20);
    insertbeginning(&head1, 3);
    insertbeginning(&head1, 2);

    display(head);
    display(head1);
    struct ll *t=mergell(head1,head);
    display(t);
    return 0;
}


