#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *prev;
    struct ll *next;
};
void insertbeginning(struct ll **head,int n)
{
    struct ll *newnode=(ll*)malloc(sizeof(ll));
    newnode->data=n;
    newnode->next=NULL;
    newnode->prev=NULL;
    if((*head)==NULL)
    {
        (*head)=newnode;
    }
    else
    {
        struct ll *p=(*head);
        p->prev=newnode;
        newnode->next=p;
        (*head)=newnode;
    }
}

void display(struct ll *head)
{
    if((head) == NULL)
        return;
    struct ll *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
struct ll *lastnode(struct ll *head)
{
    if(head==NULL)
        return NULL;
    struct ll *p=head;
    while(p->next!=NULL)
        p=p->next;
    return p;
};
int swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b=temp;
}
int count(struct ll *l,struct ll *r)
{
     int c=1;
    if(l==NULL || r==NULL)
        return 0;

    else
    {
        struct ll *p=l;

        while(p!=r)
        {
            p=p->next;
            c++;
        }
    }
    return c;
}
struct ll * part(struct ll *l,struct ll *r)
{
    int pivot=r->data;
    int cc=count(l,r);
    struct ll *i=l;
    struct ll *j=r;

    int ii=0,jj=count(l,r);
    int o=jj;
    while(ii<jj)
    {
       // cout<<i->data<<" "<<j->data<<endl;
        while(i->data <= pivot)
        {
            i=i->next;
            ii++;
        }
        while(j->data > pivot)
        {
            j=j->prev;
            jj--;
        }
        if(ii<jj )
            swap(&(i->data),&(j->data));

        else return j;
    }
};
void quicksorts(struct ll *l,struct ll *r)
{
    if(r!=NULL && r!=l && r!=l->next)
    {
        struct ll *pivot;
        pivot=part(l,r);
        cout<<pivot->data<<endl;
        quicksorts(l,pivot);
        quicksorts(pivot->next,r);
    }
    else if(r==l->next)
    {
        if(r->data < l->data )
            swap(&(l->data),&(r->data));
    }
}
void quicksort(struct ll *head)
{
    struct ll *l=head,*r=lastnode(head);
    quicksorts(l,r);
}




int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,11);
    insertbeginning(&head,13);
    insertbeginning(&head,3);
    insertbeginning(&head,40);
    insertbeginning(&head,5);
    display(head);
    quicksort(head);
    display(head);
   // int y=count(head,head->next->next);
    //cout<<y<<endl;
    return 0;
}
