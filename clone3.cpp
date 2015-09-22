#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *random;
};

struct node * newnode(int y)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=y;
    temp->next=NULL;
    temp->random=NULL;
    return temp;
};

void insertbegin(struct node **head,int y)
{
    struct node *p=newnode(y);
    if((*head)==NULL)
    {
        (*head)=p;
        return;
    }
    p->next=(*head);
    (*head)=p;
    return;
}
void printlist(struct node *head) {
	while(head != NULL) {
		cout << "Node data = " << head->data << "  random Data = " << head->random->data << endl;
		head = head->next;
	}
	cout << endl;
}


void clone(struct node *head,struct node **head2)
{
    map<struct node *,struct node*> m;
    struct node *curr=head;
    struct node * clonenode;
    while(curr)
    {
        clonenode = newnode(curr->data);
        m[curr] = clonenode;
        curr=curr->next;
    }
    curr=head;
    (*head2)=m[curr];
    while(curr)
    {
        clonenode=m[curr];
        clonenode->next=m[curr->next];
        clonenode->random=m[curr->random];
        curr=curr->next;
    }
}

int main()
{
    struct node *head2=NULL;
    struct node *head = newnode(1);
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
