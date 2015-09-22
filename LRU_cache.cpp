#include<bits/stdc++.h>
using namespace std;

struct node
{
    int page_num;
    struct node *next,*prev;
};
map<int,struct node *> m;

struct queue_cache
{
    int num_of_pages;
    int num_of_frames;
    struct node *head,*tail;
};
struct queue_cache * createqueue(int frames)
{
    struct queue_cache *q=(queue_cache*)malloc(sizeof(queue_cache));
    q->num_of_pages=0;
    q->num_of_frames=frames;
    q->head=NULL;
    q->tail=NULL;
    return q;
};
struct node * newnode(int p)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->page_num=p;
    temp->prev=temp->next=NULL;
    return temp;
};
void removerear(struct queue_cache *q)
{
    if(q->head==NULL)
        return;
    if(q->head==q->tail)
        q->head=q->tail=NULL;
    else
    {
        struct node *h=q->head,*t=q->tail;
        while(h->next!=t)
            h=h->next;
        h->next=NULL;
        q->tail=h;
    }
    q->num_of_pages--;
}
void addfront(struct queue_cache *q,int page)
{
    if(q->num_of_pages == q->num_of_frames)
    {
        m[q->tail->page_num]=NULL;
        removerear(q);
        q->num_of_pages--;
    }
    struct node *add=newnode(page);
    if(q->head==NULL)
        q->head=q->tail=add;
    else
    {
        struct node *h=q->head;
        h->prev=add;
        add->next=h;
        q->head=add;
    }
    m[page]=add;
    q->num_of_pages++;
}


void pageref(struct queue_cache *q,int page)
{
    if(m[page]==NULL)
        addfront(q,page);
    else if(m[page]!=q->head)
    {
        struct node *prev=NULL,*curr=q->head;
        while(curr!=NULL && curr->page_num!=page)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next->prev=prev;
        curr->next=q->head;
        q->head=curr;
    }
}

int main()
{
    struct queue_cache *q=createqueue(4);
    pageref( q, 1);
    pageref( q, 2);
    pageref( q, 3);
    pageref( q, 1);
    pageref( q, 4);
    pageref( q, 5);

    // Let us print cache frames after the above referenced pages
    printf ("%d ", q->head->page_num);
    printf ("%d ", q->head->next->page_num);
    printf ("%d ", q->head->next->next->page_num);
    printf ("%d ", q->head->next->next->next->page_num);

    return 0;
}
