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
void swap012(struct ll *head)
{
    int n1=0,n2=0,n3=0;
    struct ll *pp=head;
    while(pp!=NULL)
    {
        if(pp->data==0)
            n1++;
        else if(pp->data==1)
            n2++;
        else if(pp->data==2)
            n3++;

        pp=pp->next;
    }
    //cout<<n1<<" "<<n2<<" "<<n3<<endl;
    pp=head;
    int cc=1;
    int i;
    while(pp!=NULL)
    {
        while(n1!=0)
        {
            pp->data=0;
            pp=pp->next;
            n1--;
        }
        //pp=pp->next;
        while(n2!=0)
        {
           // cout<<pp->data;
            pp->data=1;
            pp=pp->next;
            n2--;
        }
        while(n3!=0)
        {
            pp->data=2;
            pp=pp->next;
            n3--;
        }
    }

}
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 0);
    insertbeginning(&head, 1);
    insertbeginning(&head, 0);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);
    insertbeginning(&head, 1);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);
    insertbeginning(&head, 2);
    display(head);
    swap012(head);
    display(head);
    return 0;
}
