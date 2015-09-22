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

int triplet(struct ll *head1,struct ll *head2,struct ll *head3,int sum)
{
    if(head1==NULL || head2==NULL || head3==NULL )
        return 0;
    struct ll *a=head1,*b,*c;
    while(a)
    {
        b=head2;
        c=head3;
        while(b&&c)
        {
            int s=a->data+b->data+c->data;
            if(s==sum)
            {
                cout<<a->data<<" "<<b->data<<" "<<c->data<<endl;
                return 1;
            }
            else if(s>sum)
                c=c->next;
            else
                b=b->next;
        }
        a=a->next;
    }
    return 0;
}

int main()
{
    struct ll *head=NULL,*pp,*head1=NULL,*head2=NULL;
    insertbeginning(&head, 12);
    insertbeginning(&head, 6);
    insertbeginning(&head, 29);
    insertbeginning(&head1, 23);
    insertbeginning(&head1, 8);
    insertbeginning(&head1, 5);
    insertbeginning(&head2, 50);
    insertbeginning(&head2, 20);
    insertbeginning(&head2, 90);
    display(head);
    display(head1);
    display(head2);
    int p=triplet(head,head1,head2,101);
    cout<<p<<endl;
    return 0;
}
