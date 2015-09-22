#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int n)
{
    struct node *tem=(node*)malloc(sizeof(node));
    tem->data=n;
    tem->left=NULL;
    tem->right=NULL;
    return tem;
};
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    else return max(height(root->left),height(root->right))+1;
}
void insertrec(struct node *root,int n)
{
    struct node *temp;
    temp=newnode(n);
    if(root==NULL)
    {
        root=temp;
        return;
    }
    if(root->data > n)
    {
        if(root->left==NULL)
        {
            root->left=temp;
            return;
        }
        insertrec(root->left,n);
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return;
        }
        insertrec(root->right,n);
    }
}


void levelorder(struct node *root)
{
    if(root==NULL)
        return;
    struct node *temp=root;
    queue<struct node *> q;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        if(!q.empty())
        {
            temp=q.front();
            q.pop();
        }
        else break;
    }
    cout<<endl;
}
void preorder(struct node *root,char pre[],int &i)
{
    if(root==NULL)
        pre[i++]='&';
    if(root)
    {
        pre[i++]=root->data;
        preorder(root->left,pre,i);
        preorder(root->right,pre,i);
    }
}

void inorder(struct node *root,char in[],int &i)
{
    if(root==NULL)
        in[i++]='&';
    if(root)
    {
        inorder(root->left,in,i);
        in[i++]=root->data;
        inorder(root->right,in,i);
    }
}
int issubtree(struct node *root,struct node *bacha)
{
    if(bacha==NULL)
        return 1;
    if(root==NULL)
        return 0;
    char preb[10]={0},prep[10]={0},inb[10]={0},inp[10]={0};
    int i=0;
    inorder(root,inp,i);
    i=0;
    inorder(bacha,inb,i);
    if(strstr(inp,inb)!=NULL)
    {
        i=0;
        preorder(root,prep,i);
        i=0;
        preorder(bacha,preb,i);
        if(strstr(prep,preb)!=NULL)
            return 1;
        else
            return 0;
    }
    else return 0;


}
int main()
{
    struct node *root=NULL,*p1,*p2,*p3,*p4,*p5,*p6;
    root=newnode(50);
    p1=newnode(7);
    p2=newnode(2);
    p3=newnode(3);
    p4=newnode(5);
    p5=newnode(1);
    p6=newnode(30);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;
    levelorder(root);
    struct node *root2=NULL,*a1,*a2;
    root2=newnode(7);
    a1=newnode(3);
    a2=newnode(5);
    root2->left=a1;
    root2->right=a2;
    levelorder(root2);
    int t=issubtree(root,root2);
    cout<<t<<endl;
    return 0;

}


