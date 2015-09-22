#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *newnode(int num)
{
    struct node *p=(node*)malloc(sizeof(node));
    p->data=num;
    p->next=NULL;
    return p;
};

void insertbeginning(struct node **head,int n)
{
    struct node *nod;
    nod=(node*)malloc(sizeof(node));
    nod->data=n;
    nod->next=NULL;
    if((*head)==NULL)
        (*head)=nod;
    else
    {
        struct node *p=(*head);
        nod->next=p;
        (*head)=nod;
    }

}

void display(struct node *head)
{
    if(head==NULL)
        return ;
    else
    {
        struct node *p=head;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
int getsize(struct node *head)
{
    int n;
    struct node *crawl=head;
    while(crawl!=NULL)
    {
        n++;
        crawl=crawl->next;
    }
    return n;
}
int carry=0;
struct node *addsamelength(struct node *a,struct node *b)
{
    if(a==NULL && carry==0)
        return NULL;
    struct node *result=(node*)malloc(sizeof(node));
    result->next=addsamelength(a->next,b->next);
    int sum=a->data+b->data+carry;
    carry=sum/10;
    sum=sum%10;
    result->data=sum;

    return result;

};

void swapnodes(struct node **a,struct node **b)
{
    struct node *temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}
struct node *addcarrytoremain(struct node *head)
{
    if(head==NULL && carry==0)
        return NULL;

    if(head==NULL && carry!=0)
    {
        struct node *result=newnode(carry);
        return result;
    }
    struct node *result=(node*)malloc(sizeof(node));
    result->next=addcarrytoremain(head->next);
    int sum=head->data+carry;
    carry=sum/10;
    sum=sum%10;
    result->data=sum;
    return result;

};
void add(struct node *a,struct node *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    int c1=getsize(a);
    int c2=getsize(b);
    if(c2>c1)
        swapnodes(&a,&b);
    int y=1;
    int k=abs(c1-c2);
    struct node *ha=a;
    while(ha!=NULL && y!=k)
    {
        ha=ha->next;
        y++;
    }
    addsamelength(ha->next,b);
    return addcarrytoremain(ha);
}
int main()
{
    struct node *h1=NULL,*h2=NULL;
    insertbeginning(&h1,1);
    insertbeginning(&h1,2);
    insertbeginning(&h1,3);
    insertbeginning(&h2,4);
    insertbeginning(&h2,5);
    insertbeginning(&h2,7);
    display(h1);
    display(h2);
    struct node *result=addSameSize(h1,h2,0);
    display(result);
    return 0;
}
