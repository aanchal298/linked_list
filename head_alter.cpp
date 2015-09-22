#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
};
struct ll *head=NULL;
void insertbeginning(int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=NULL;
    if((head)==NULL)
        (head)=node;
    else
    {
        struct ll *p=(head);
        node->next=p;
        (head)=node;
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

    insertbeginning(53);
    insertbeginning(52);

 /*   insertbeginning(&head, 51);
   // insertbeginning(&head, 54);
    struct ll *head2=NULL;
    insertbeginning(&head, 50);
    insertbeginning(&head, 49);
    insertbeginning(&head, 48);*/

    display(head);
  //  deletenode(head,head);
   // display(head);

    return 0;
}
