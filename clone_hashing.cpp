#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *next;
    struct ll *random;
};

struct ll * newnode(int y)
{
    struct ll *temp=(ll*)malloc(sizeof(ll));
    temp->data=y;
    temp->next=NULL;
    temp->random=NULL;
    return temp;
};

void insertbegin(struct ll **head,int y)
{
    struct ll *p=newnode(y);
    if((*head)==NULL)
    {
        (*head)=p;
        return;
    }
    p->next=(*head);
    (*head)=p;
    return;
}
void clone(struct ll *head,struct ll **head2)
{
    map<struct ll *,struct ll *> v;
    struct ll *o=head;
    while(o!=NULL)
    {
        struct ll *n=newnode(o->data);
        v[o]=n;
        o=o->next;
    }
    (*head2)=v[head];
    map<struct ll *,struct ll *>:: iterator it;
    int i=1;

    cout<<(*head2)->data<<endl;
    for(it=v.begin();it!=v.end();it++)
    {
        it->second->next=v[it->first->next];
        it->second->random=v[it->first->random];
    }

}
void printlist(struct ll *head) {
	while(head != NULL) {
		cout << "Node data = " << head->data << "  random Data = " << head->random->data << endl;
		head = head->next;
	}
	cout << endl;
}
int main()
{
    struct ll *head2=NULL;
    struct ll *head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = NULL;
// Assign Arbitary Pointers
	head->random = head->next->next;
	head->next->random = head->next->next->next;
	head->next->next->random = head;
	head->next->next->next->random = head->next;
	head->next->next->next->next->random = head->next->next->next->next;
    printlist(head);
    clone(head,&head2);
    printlist(head2);
}
