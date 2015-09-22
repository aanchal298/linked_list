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

void maxsumpath(struct ll *head1,struct ll *head2)
{
    struct ll *rhead=NULL,*result;
    struct ll *p;
    int sum1=0,sum2=0;
    struct ll *currone=head1,*currtwo=head2,*one=head1,*two=head2;
    while(currone || currtwo)
    {
        if(currone==NULL)
        {
            result->next=two;
            break;
        }
        else if(currtwo==NULL)
        {
            result->next=one;
            break;
        }
        if(currone->data > currtwo->data)
        {
            sum2+=currtwo->data;
            currtwo=currtwo->next;
        }
        else if(currone->data < currtwo->data)
        {
            sum1+=currone->data;
            currone=currone->next;
        }
        else if(currone->data == currtwo->data)
        {
            if(sum1>sum2)
            {
                if(rhead==NULL)
                {
                    p=one;
                    struct ll *newnode=(ll*)malloc(sizeof(ll));
                    newnode->data=p->data;
                    newnode->next=NULL;
                    result=newnode;
                    rhead=result;
                    p=p->next;
                    while(p!=currone)
                    {
                        struct ll *newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                        p=p->next;
                    }
                    newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                }
                else
                {
                    p=one;
                    while(p!=currone)
                    {
                        struct ll *newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                        p=p->next;
                    }
                    struct ll *newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                }


            }
            else if(sum1<sum2)
            {
                if(rhead==NULL)
                {
                    struct ll *p=two;
                    struct ll *newnode=(ll*)malloc(sizeof(ll));
                    newnode->data=p->data;
                    newnode->next=NULL;
                    result=newnode;
                    rhead=result;
                    p=p->next;
                    while(p!=currtwo)
                    {
                        struct ll *newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                        p=p->next;
                    }
                    newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                }
                else
                {
                    p=two;
                    while(p!=currtwo)
                    {
                        struct ll *newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                        p=p->next;
                    }
                    struct ll *newnode=(ll*)malloc(sizeof(ll));
                        newnode->data=p->data;
                        newnode->next=NULL;
                        result->next=newnode;
                        result=result->next;
                }

            }
            sum1=0;
            sum2=0;
            one=currone->next;
            two=currtwo->next;
            currone=currone->next;
            currtwo=currtwo->next;
        }
    }
    display(rhead);
}








int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,120);
    insertbeginning(&head,110);
    insertbeginning(&head,90);
    insertbeginning(&head,30);
    insertbeginning(&head,3);
    insertbeginning(&head,1);

    display(head);
    struct ll *head2=NULL;
    insertbeginning(&head2,130);
    insertbeginning(&head2,120);
    insertbeginning(&head2,100);
    insertbeginning(&head2,90);
    insertbeginning(&head2,32);
    insertbeginning(&head2,12);
    insertbeginning(&head2,3);
    insertbeginning(&head2,0);

    display(head2);
    maxsumpath(head,head2);
    return 0;
}
