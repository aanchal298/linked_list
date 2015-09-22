#include<bits/stdc++.h>
using namespace std;
struct ll{
    int data;
    struct ll *next;
    struct ll *arbit;
};


struct ll * mergell(struct ll *a,struct ll *b)
{
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    struct ll *temp;
    if(a->data > b->data)
    {
        temp=(ll*)malloc(sizeof(ll));
        temp->data=b->data;
        temp->next=mergell(a,b->next);
    }
    else if(b->data > a->data)
    {
        temp=(ll*)malloc(sizeof(ll));
        temp->data=a->data;
        temp->next=mergell(a->next,b);
    }
    else if(a->data==b->data)
    {
        temp=(ll*)malloc(sizeof(ll));
        temp->data=a->data;
        temp->next=mergell(a->next,b->next);
    }

    return temp;
};
void split(struct ll *head,struct ll **a,struct ll **b)
{
    if(head==NULL || head->next==NULL)
    {
        (*a)=head;
        (*b)==NULL;
    }
    struct ll *s=head,*f=head,*p=NULL;
    while(s && f && f->next)
    {
        p=s;
        f=f->next->next;
        s=s->next;
        if(f==NULL || f->next==NULL)
            break;
    }
    p->next=NULL;
    (*a)=head;
    (*b)=s;

}

void mergesort(struct ll **head)
{

    struct ll *h=(*head);
    if(h==NULL || h->next==NULL)
        return;
    struct ll *a,*b;
    split(h,&a,&b);
    mergesort(&a);
    mergesort(&b);
    (*head)=mergell(a,b);

}


void push(struct ll** head_ref, int new_data)
{
    /* allocate ll */
    struct ll* new_ll =
        (struct ll*) malloc(sizeof(struct ll));

    /* put in the data  */
    new_ll->data  = new_data;

    /* link the old list off the new ll */
    new_ll->next = (*head_ref);

    new_ll->arbit = NULL;

    /* move the head to point to the new ll */
    (*head_ref)    = new_ll;
}

// Utility function to print result linked list
void printListafter(struct ll **h)
{
    struct ll *head=(*h),*all=(*h);
    printf("Traversal using Next Pointer\n");
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
 cout<<endl;
  /*  printf("\nTraversal using Arbit Pointer\n");
    */while (all!=NULL)
    {
        printf("%d, ", all->data);
        all = all->arbit;
    }
}

void populate(struct ll *head)
{
    struct ll *p=head;
    while(p->next!=NULL)
    {
        p->arbit=p->next;
        p=p->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct ll *head = NULL;

    /* Let us create the list shown above */
    push(&head, 3);
    push(&head, 2);
    push(&head, 10);
    push(&head, 5);

    /* Sort the above created Linked List */
   // struct node *ahead = populateArbit(head);

    //printf("\nResult Linked List is: \n");
    cout<<"kjsfb"<<endl;
    mergesort(&head);
    populate(head);
    printListafter(&head);
    return 0;
}
