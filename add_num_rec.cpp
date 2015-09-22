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
int count(struct ll *head)
{
    if(head==NULL)
        return 0;
    else
    {
        struct ll *p=head;
        int c=1;
        while(p->next!=NULL)
        {
            p=p->next;
            c++;
        }
        return c;
    }
}
void swap(struct ll **head1,struct ll **head2)
{
    struct ll *temp=(*head1);
    (*head1)=(*head2);
    (*head2)=temp;
}
struct ll * addremain(struct ll *head,int *carry)
{
    if(head==NULL)
        return NULL;
    struct ll *result=(ll*)malloc(sizeof(ll));
    result->next=addremain(head->next,carry);
    int tt=head->data+ (*carry);
    result->data=tt%10;
    (*carry)=tt/10;
    return result;
};
void addtwo(struct ll *head1,struct ll *head2)
{
    if(head1==NULL)
        return;
    if(head2==NULL)
        return;
    struct ll *result=NULL;;
    int s1=count(head1);
    int s2=count(head2);
    int carry=0;
    if(s1==s2)
        result=addsame(head1,head2,&carry);
    if(s2>s1)
        swap(&head1,&head2);
    int diff=abs(s1-s2);
    int c=1;
    struct ll *p=head1;
    while(c<diff)
        p=p->next;
    result=addsame(p,head2,&carry);
    result=addremain(head1,&carry);
    display(result);


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
    insertbeginning(&head1, 7);
    insertbeginning(&head1, 8);
    display(head1);
    //reverse(&head1);
    insertbeginning(&head2, 9);
    insertbeginning(&head2, 9);
    insertbeginning(&head2, 9);
 //   insertbeginning(&head2, 4);
  //  insertbeginning(&head2, 6);
    display(head2);
    //reverse(&head2);
    int carry=0;
   // insertbeginning(&head2, 54);

    addtwo(head1,head2);
    //reverse(&yy);
    //display(yy);

    return 0;
}


