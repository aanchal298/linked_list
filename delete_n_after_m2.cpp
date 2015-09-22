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
void deleten(struct ll *head,int n,int m)
{
    struct ll *p=head,*q;
    int b=0;
    int i,j;
    while(p)
    {

            for(i=1;i<m&&p!=NULL;i++)
            {
                p=p->next;
            }
        //    b=1;
            if(p==NULL)
                return;


            q=p->next;
            for(i=1;i<=n&&q!=NULL;i++)
            {
                q=q->next;
            }
            p->next=q->next;
            p=q->next;
          //  b=0;

    }

}
int main()
{
    struct ll *head=NULL,*pp;
    insertbeginning(&head, 10);
    insertbeginning(&head, 9);
    insertbeginning(&head, 8);
    insertbeginning(&head, 7);
    insertbeginning(&head, 6);
    insertbeginning(&head, 5);
    insertbeginning(&head, 4);
    insertbeginning(&head, 3);
    insertbeginning(&head, 2);
    insertbeginning(&head, 1);
  /*  insertbeginning(&head, 20);
    insertbeginning(&head, 30);
    insertbeginning(&head, 40);
    insertbeginning(&head, 50);
    insertbeginning(&head, 60);
    insertbeginning(&head, 70);*/

    display(head);
    deleten(head,2,2);
    display(head);

    return 0;
}


