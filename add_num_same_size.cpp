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

struct ll * addsame(struct ll *head1,struct ll *head2,int *carry)
{
    struct ll *result;
    if(head1==NULL)
        return NULL;
    result=(ll*)malloc(sizeof(ll));

    result->next=addsame(head1->next,head2->next,carry);
    int dd=(*carry)+head1->data+head2->data;
    (result)->data=dd%10;
    (*carry)=dd/10;
    return result;

}
void reverse(struct ll **head)
{
    if((*head)==NULL)
        return;
    struct ll *first,*rest;
    first=(*head);

    rest=(*head)->next;
    if(rest==NULL)
        return;
    reverse(&rest);
    first->next->next=first;
    first->next=NULL;
    (*head)=rest;
}


int main()
{
    struct ll *head1=NULL;
    struct ll *head2=NULL;
    struct ll *result=NULL;
    int carry=0;
    insertbeginning(&head1, 1);
    insertbeginning(&head1, 3);
    insertbeginning(&head1, 2);
    display(head1);
    insertbeginning(&head2, 6);
    insertbeginning(&head2, 9);
    insertbeginning(&head2, 9);
  //  insertbeginning(&head2, 6);
    display(head2);

    result=addsame(head1,head2,&carry);

    if(carry!=0)
        insertbeginning(&result,carry);
     display(result);
    return 0;
}


