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
int count(struct ll *head)
{
    if(head==NULL)
        return 0;
    int c=1;
    struct ll *p=(head);
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}
void swapkth(struct ll **head,int k)
{
    struct ll *hh=(*head);
    int n=count(hh);
    struct ll *prevx,*curx,*prevy,*cury,*c=(*head),*p=NULL;
    if((*head==NULL))
        return;
    if(k>n)
        return;
    if(k==n-k)
        return;
    if(k==1)
    {
        while(c->next!=NULL)
        {
            p=c;
            c=c->next;
        }
        prevy=(*head);
        p->next=prevy;
        c->next=prevy->next;
        prevy->next=NULL;
        (*head)=c;
    }
    else
    {
        p=NULL,c=(*head);
        int cc=1;
        while(c&&cc<n)
        {
            if(cc==k)
            {
                prevx=p;
                curx=c;
            }
            if(cc==n-k)
            {
                prevy=p;
                cury=c;
                //break;
            }
            p=c;
            c=c->next;
            cc++;
        }
        struct ll *temp=curx->next;
        prevy->next=curx;
        prevx->next=cury;
        curx->next=cury->next;
        cury->next=temp;


    }



}
int main()
{
    struct ll *head=NULL,*pp;

    insertbeginning(&head, 9);

    insertbeginning(&head, 8);
    insertbeginning(&head, 7);
    insertbeginning(&head, 6);
    insertbeginning(&head, 5);
    insertbeginning(&head, 4);
    insertbeginning(&head, 3);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);

    display(head);
    swapkth(&head,1);
    display(head);
    return 0;
}

