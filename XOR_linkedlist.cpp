#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *npx;
};
struct ll * XOR(struct ll *a,struct ll *b)
{
    return (struct ll*) ((unsigned int) (a) ^ (unsigned int) (b));
};
void insertbeginning(struct ll **head,int n)
{
    struct ll *newnode=(ll*)malloc(sizeof(ll));
    newnode->data=n;
    newnode->npx=XOR(NULL,(*head));

    if((*head)==NULL)
        (*head)=newnode;
    else
    {
        struct ll *p;
        p=XOR(NULL,(*head)->npx);
        (*head)->npx=XOR(p,newnode);
        (*head)=newnode;
    }

}
void display(struct ll *head)
{
    if(head==NULL)
        return ;
    else
    {
        struct ll *p=NULL,*n,*c=head;
        while(c)
        {
            cout<<c->data<<" ";
            n=XOR(c->npx,p);
            p=c;
            c=n;
        }
    }
}
void insertafter(struct ll *head,int nn,int pp)
{
    struct ll *p=NULL,*nnext,*c=head,*n;
    struct ll *newnode=(ll*)malloc(sizeof(ll));
    newnode->data=pp;
    while(c)
    {
        n=XOR(c->npx,p);
        if(c->data==nn)
        {
            newnode->npx=XOR(c,n);
            c->npx=XOR(p,newnode);
            nnext=XOR(c,n->npx);
            n->npx=XOR(newnode,nnext);

            return;
        }
        p=c;
        c=n;
    }
}

int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,1);
    insertbeginning(&head,2);
    insertbeginning(&head,3);
    insertbeginning(&head,4);
    insertbeginning(&head,5);
    display(head);
    cout<<endl;
    insertafter(head,2,9);
    display(head);
    cout<<endl;
    return 0;
}
