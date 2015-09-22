#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct ll *next;
    int val;
};
int count(struct ll *head)
{
    if(head==NULL)
        return 0;
    struct ll *p=head;
    int c=1;
    while(p->next!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}


void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->val=n;
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
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
void nthfromend(struct ll *head,int n)
{
    int c=0;
    struct ll *p=head,*q=head;
    while(c<n)
    {
        p=p->next;
        c++;
    }
    while(p!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    cout<<q->val<<endl;
}
void nthfromend2(struct ll *head,int n)
{
    struct ll *j=head;
    int yy=count(head);
    int c=1;
    while(c!=yy-n+1)
    {
        j=j->next;
        c++;
    }
    cout<<j->val<<endl;
}

int main()
{
    struct ll *head=NULL;
    //insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 54);
    insertbeginning(&head, 55);
    insertbeginning(&head, 56);
    insertbeginning(&head, 57);
    insertbeginning(&head, 58);
    display(head);

    cout<<endl;
    nthfromend2(head,3);
//    cout<<yy<<endl;
    //deletegiven(head->next);
    //display(head);
    return 0;
}
