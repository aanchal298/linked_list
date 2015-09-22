#include<bits/stdc++.h>
using namespace std;

struct ll{
    int flag;
    int data;
    struct ll *next;
};

int palin(struct ll *head)
{
    struct ll *p=head;
    stack<int> s;
    while(p!=NULL)
    {
         s.push(p->data);
         p=p->next;
    }
    p=head;
    while(!s.empty())
    {
        if(s.top()==p->data)
        {
            s.pop();
            p=p->next;
        }
        else
        {
            cout<<"not palin"<<endl;
            return 0;
        }
    }
    return 1;
}
void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
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
int compare(struct ll *h1,struct ll *h2)
{
    if(h1==NULL && h2!=NULL || h1!=NULL && h2==NULL)
        return 0;
    else
    {
        struct ll *p=h1,*q=h2;
        while(p && q)
        {
            if(p->data==q->data)
            {
                p=p->next;
                q=q->next;
            }
            else
                return 0;
        }
        if(p || q)
            return 0;
        else
            return 1;
    }
}
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head, 51);
    insertbeginning(&head, 52);
    insertbeginning(&head, 53);
    insertbeginning(&head, 54);
    struct ll *head2=NULL;
    insertbeginning(&head2, 53);
    insertbeginning(&head2, 52);
    insertbeginning(&head2, 51);
   // insertbeginning(&head2, 54);

    int yy=compare(head,head2);
    cout<<yy<<endl;
    return 0;
}

