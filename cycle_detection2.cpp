#include<bits/stdc++.h>
using namespace std;

struct ll{
    int flag;
    int val;
    struct ll *next;
};

int cycle(struct ll *head)
{
    struct ll *p=head;
    while(p!=NULL)
    {
        if(p->flag==0)
        {
            p->flag=1;
            p=p->next;
        }
        else if(p->flag==1)
        {
            cout<<"found loop"<<endl;
            return 1;
        }
    }
    return 0;
}

void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->val=n;
    node->next=NULL;
    node->flag=0;
    if((*head)==NULL)
        (*head)=node;
    else
    {
        struct ll *p=(*head);
        node->next=p;
        (*head)=node;
    }

}
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 54);
    insertbeginning(&head, 52);
    insertbeginning(&head, 56);
    insertbeginning(&head, 57);
    insertbeginning(&head, 52);
    //head->next->next->next=head->next;
    int yy=cycle(head);
    cout<<yy<<endl;

    return 0;
}
