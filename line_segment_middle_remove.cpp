#include<bits/stdc++.h>
using namespace std;
struct ll{
    int x;
    int y;
    struct ll *next;
};

void insertbeginning(struct ll **head,int n,int m)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->x=n;
    node->y=m;
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
            cout<<"("<<p->x<<","<<p->y<<")"<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}

void function(struct ll *head)
{
    struct ll *p=head,*q,*r,*jj,*pp;
    while(p->next && p->next->next)
    {
        q=p->next;
        r=q->next;

        if(p->x==r->x)
        {
         //   cout<<p->x<<endl;
            jj=r;
            pp=NULL;
            while(p->x==jj->x)
            {
                if(jj==NULL)
                    break;
                pp=jj;
                jj=jj->next;
            }
            cout<<pp->y<<endl;
            p->next=pp;
            p=p->next;
        }
        else if(p->y==r->y)
        {
            jj=r;
            pp=NULL;
            while(p->y==jj->y)
            {
                if(jj==NULL)
                    break;
                pp=jj;
                jj=jj->next;
            }
            cout<<pp->x<<endl;
            p->next=pp;
        }
        if(p->next!=NULL)
            p=p->next;
        else
            break;
    }

}

int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,40,5);
    insertbeginning(&head,20,5);
    insertbeginning(&head,10,5);
    insertbeginning(&head,10,8);
    insertbeginning(&head,10,10);
    insertbeginning(&head,3,10);
    insertbeginning(&head,1,10);
    insertbeginning(&head,0,10);
    display(head);
    function(head);
    display(head);
    return 0;
}

