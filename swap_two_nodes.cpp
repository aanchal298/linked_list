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
void swapnodes(struct ll **head,int x,int y)
{
    struct ll *temp,*prevx=NULL,*curx=(*head),*prevy=NULL,*cury=(*head);
    while(curx!=NULL)
    {
        if(curx->data==x)
            break;
        prevx=curx;
        curx=curx->next;
    }
    while(cury!=NULL)
    {
        if(cury->data==y)
            break;
        prevy=cury;
        cury=cury->next;
    }
    //cout<<curx->data<<" "<<cury->data<<endl;
    if(curx==cury)
        return;
    else if(cury==NULL || prevy==NULL)
        return;
    else if(curx==(*head))
    {
        prevy->next=curx;
        temp=cury->next;
        cury->next=curx->next;
        curx->next=temp;
        (*head)=cury;

    }
    else if(cury==(*head))
    {
        prevx->next=cury;
        temp=curx->next;
        curx->next=cury->next;
        cury->next=temp;
        (*head)=(curx);

    }
    else {
            prevx->next=cury;
            prevy->next=curx;
            temp=curx->next;
            curx->next=cury->next;
            cury->next=temp;

    }
}
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 7);
    insertbeginning(&head, 6);
    insertbeginning(&head, 5);
    insertbeginning(&head, 4);
    insertbeginning(&head, 3);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);


    display(head);
    swapnodes(&head,3,7);
    display(head);
    return 0;
}

