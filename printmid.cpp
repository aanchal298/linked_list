#include<bits/stdc++.h>
using namespace std;
struct ll{
    struct ll *next;
    int data;
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

void printmid(struct ll *head)
{
     struct ll *i=head,*j=head;
     while(j->next!=NULL&&j->next->next!=NULL)
     {
         i=i->next;
         j=j->next->next;
     }
    cout<<i->data<<endl;
}
void insertbeginning(struct ll **head,int n)
{
    struct ll *ll;
    ll=(ll*)malloc(sizeof(ll));
    ll->data=n;
    ll->next=NULL;
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
    printmid(head);
//    cout<<yy<<endl;
    //deletegiven(head->next);
    //display(head);
    return 0;
}
