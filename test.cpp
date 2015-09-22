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

int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 10);
    insertbeginning(&head, 5);
    insertbeginning(&head, 2);
    insertbeginning(&head, 54);
insertbeginning(&head, 54);

    display(head);
    pp=split(head);
    cout<<pp->data<<endl;;
    return 0;
}
