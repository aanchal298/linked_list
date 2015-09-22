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
    node->data=n;
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
void insertend(struct ll **head,int n)
{
    struct ll *node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=NULL;
    if((*head)==NULL)
    {
        (*head)=node;
    }
    else
    {
        struct ll *p=(*head);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=node;
    }
}
void deletebeginning(struct ll **head)
{
    if((*head)==NULL)
        return;
    else
    {
        struct ll *p=(*head)->next;
        (*head)=p;
    }
}

void deleteend(struct ll **head)
{
    if((*head)==NULL)
        return;
    else if((*head)->next==NULL)
        (*head)=NULL;
    else
    {
        struct ll *p=(*head);
        while(p->next->next!=NULL)
            p=p->next;
        p->next=NULL;
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
int main()
{
    struct ll *head=NULL;
    int p;

    do
    {
        cout<<"1.insertbeginning "<<"2.insertend "<<"3.deletebeginning "<<"4.deleteend "<<"5.display "<<"6.count "<<endl;
        cin>>p;
        switch(p)
        {
            case 1:
            {
                int n;
                cin>>n;
                insertbeginning(&head,n);
                break;
            }
            case 2:
            {
                int n;
                cin>>n;
                insertend(&head,n);
                break;
            }
            case 3:
            {
                deletebeginning(&head);
                break;
            }
            case 4:
            {
                deleteend(&head);
                break;
            }
            case 5:
            {
                display(head);
                break;
            }
            case 6:
            {
                int pp=count(head);
                cout<<pp<<endl;
                break;
            }
        }
    }while(p!=0);
    return 0;
}
