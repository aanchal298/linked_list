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

int identical(struct ll *h1,struct ll *h2)
{
    if(h1==NULL && h2==NULL)
        return 1;
    if(h1==NULL && h2!=NULL)
        return 0;
    if(h1!=NULL && h2==NULL)
        return 0;
    if(h1->data!=h2->data)
        return 0;
    struct ll *a=h1,*b=h2;
    while(a&&b)
    {
        if(h1->data!=h2->data)
            return 0;
        a=a->next;
        b=b->next;
    }
    if(a||b)
        return 0;
    return 1;
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
    struct ll *head2=NULL;
    insertbeginning(&head2, 52);
    insertbeginning(&head2, 52);
    insertbeginning(&head2, 53);
    insertbeginning(&head2, 15);
    insertbeginning(&head2, 10);
    insertbeginning(&head2, 7);
    insertbeginning(&head2, 5);
    insertbeginning(&head2, 2);
    display(head2);
    int yy=identical(head,head2);
    cout<<yy<<endl;
    return 0;
}


