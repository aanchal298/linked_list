#include<bits/stdc++.h>
using namespace std;

struct ll{
    int data;
    struct ll *prev,*next;
};
struct mystack{
    int count;
    struct ll *mid,*head;
};


struct mystack * createstack()
{
    struct mystack * ms=(mystack*)malloc(sizeof(mystack));
    ms->count=0;
    return ms;
};


void push(struct mystack *ms,int n)
{
    struct ll *newnode=(ll*)malloc(sizeof(ll));
    newnode->data=n;
    newnode->next=ms->head;
    newnode->prev=NULL;
    ms->count+=1;
    if(ms->count==1)
    {
        ms->mid=newnode;

    }
    else
    {
        ms->head->prev=newnode;
        if(ms->count%2==0)
            ms->mid=ms->mid->prev;
    }
    ms->head=newnode;
}
int getmid(struct mystack *ms)
{
    if(ms->count==0)
        return -1;
    else return ms->mid->data;
}
void pop(struct mystack *ms)
{
    if(ms->count==0)
        return;
    else
    {
        struct ll *p;
        p=ms->head->next;
        p->prev=NULL;
        ms->head=p;
        ms->count-=1;
        if(ms->count==1)
            ms->mid=ms->head;
        else if(ms->count%2==0)
            ms->mid=ms->mid->prev;
    }
}
int main()
{
    struct mystack *ms=createstack();
    push(ms,1);
    push(ms,2);
    push(ms,3);
    push(ms,4);
    push(ms,5);

    int yy=getmid(ms);
    pop(ms);
    int zz=getmid(ms);
    cout<<zz<<endl;
    cout<<yy<<endl;
}
