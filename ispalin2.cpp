#include<bits/stdc++.h>
using namespace std;

struct ll{
int data;
struct ll *next;
};

void reverse(struct ll **head)
{
    if((*head)==NULL)
        return;
    struct ll *first=(*head),*rest;
    rest=(*head)->next;
    if(rest==NULL)
        return;
    reverse(&rest);
    first->next->next=first;
    (*head)=rest;
}
int compare(struct ll *h1,struct ll *h2)
{
    if(h1==NULL && h2!=NULL || h1!=NULL && h2==NULL)
        return 0;
    else
    {
        struct ll *p=h1,*q=h2;
        while(p && q)
        {
            if(p->data==q->data)
            {
                p=p->next;
                q=q->next;
            }
            else
                return 0;
        }
        if(p || q)
            return 0;
        else
            return 1;
    }
}
int ispalin(struct ll *head)
{
    int pal=0;
    struct ll *k,*f=head,*ps,*s=head,*m=NULL,*r;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        ps=s;
        s=s->next;


    }
    if(f==NULL)
    {
        r=s;
        ps->next=NULL;
    }
    else
    {
        m=s;
        ps=s;
        s=s->next;
        ps->next=NULL;
    }
    reverse(&s);
    int t=compare(head,s);
    if(t==1)
        pal=1;
    else
        pal=0;
    cout<<pal<<endl;
  /*  reverse(&r);
    if(m!=NULL)
    {
        m->next=r;
    }
    else
        ps->next=r;

    if(pal==1)
        return 1;
    else
        return 0;*/


}
void insertbeginning(struct ll **head,int n)
{
    struct ll *ll;
    ll=(ll*)malloc(sizeof(ll));
    ll->data=n;
    ll->next=NULL;
//    ll->flag=0;
    if((*head)==NULL)
        (*head)=ll;
    else
    {
        struct ll *p=(*head);
        ll->next=p;
        (*head)=ll;
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
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 53);
    insertbeginning(&head, 52);
    insertbeginning(&head, 51);
    insertbeginning(&head, 54);
    //insertbeginning(&head, 54);
    insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);

    display(head);
    cout<<endl;
    int yy=ispalin(head);
    cout<<yy<<endl;
    struct ll *head2=NULL;
    insertbeginning(&head2, 53);
    insertbeginning(&head2, 52);
    insertbeginning(&head2, 51);
    insertbeginning(&head2, 54);
    insertbeginning(&head2, 54);
    insertbeginning(&head2, 51);
    insertbeginning(&head2, 52);
    insertbeginning(&head2, 53);
    display(head2);
    cout<<endl;
    int zz=ispalin(head2);
    //cout<<zz<<endl;
    return 0;
}
