#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
    struct ll *down;
};
void insertbeginning(struct ll **head,int n)
{
    struct ll *node;
    node=(ll*)malloc(sizeof(ll));
    node->data=n;
    node->next=NULL;
    node->down=NULL;
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
            p=p->down;
        }
        cout<<endl;
    }
}
struct ll *newnode(int d)
{
    struct ll *tem=(ll*)malloc(sizeof(ll));
    tem->data=d;
    tem->next=NULL;
    tem->down=NULL;
    return tem;
};
struct ll * merge(struct ll *a ,struct ll *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    struct ll *temp;

    if(a->data<b->data)
    {
        temp=a;
        temp->down=merge(a->down,b);
    }
    if(a->data>b->data)
    {
        temp=b;
        temp->down=merge(a,b->down);
    }
    return temp;
};
struct ll *flatten(struct ll *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    else return merge(head,flatten(head->next));
};
int main()
{
    struct ll *head=NULL;
    insertbeginning(&head,28);
    insertbeginning(&head,19);
    insertbeginning(&head,10);
    insertbeginning(&head,5);
    struct ll *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*head5=NULL,*head6=NULL,*head7=NULL,*head8=NULL,*head9=NULL;
    head1=newnode(7);
    head2=newnode(8);
    head3=newnode(30);
    head4=newnode(20);
    head5=newnode(22);
    head6=newnode(50);
    head7=newnode(35);
    head8=newnode(40);
    head9=newnode(45);
    head->down=head1;
    head1->down=head2;
    head2->down=head3;
    head->next->down=head4;
    head->next->next->down=head5;
    head5->down=head6;
    head->next->next->next->next->down=head7;
    head7->down=head8;
    head8->down=head9;
    head=flatten(head);
    display(head);
    return 0;
}
