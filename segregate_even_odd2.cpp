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

void segregate(struct ll **head)
{
   struct ll *e,*eh=NULL,*o,*oh=NULL,*p,*newnode;
   p=(*head);
   while(p!=NULL)
   {
       newnode=(ll*)malloc(sizeof(ll));
       newnode->data=p->data;
       newnode->next=NULL;
       if(p->data%2==0)
       {
           if(eh==NULL)
           {
               e=newnode;
               eh=e;
           }
           else
           {
               e->next=newnode;
               e=e->next;
           }
       }
       else
       {
           if(oh==NULL)
           {
               o=newnode;
               oh=o;
           }
           else
           {
               o->next=newnode;
               o=o->next;
           }
       }
       p=p->next;
   }
   if(eh==NULL)
    (*head)=oh;
   else{
        e->next=oh;
        (*head)=eh;
   }


}



int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 11);
    insertbeginning(&head, 10);
    insertbeginning(&head, 9);
   insertbeginning(&head, 6);
    struct ll *head2=NULL;
    insertbeginning(&head, 4);
insertbeginning(&head, 3);
    insertbeginning(&head, 1);
    insertbeginning(&head, 54);

    display(head);
    segregate(&head);
    display(head);
    return 0;
}

