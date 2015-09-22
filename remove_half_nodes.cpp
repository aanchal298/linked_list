#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int n)
{
    struct node *tem=(node*)malloc(sizeof(node));
    tem->data=n;
    tem->left=NULL;
    tem->right=NULL;
    return tem;
};
void insertrec(struct node *root,int n)
{
    struct node *temp;
    temp=newNode(n);
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
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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

void print(struct node *root,int l,int h)
{
    if(root==NULL)
        return ;
    struct node *dinku=NULL;
    queue<pair<int,struct node *> > q;
    q.push(make_pair(1,root));
    q.push(make_pair(0,dinku));
    while(!q.empty())
    {
        pair< int,struct node * > p;
        p=q.front();
        q.pop();
        int i=p.first;
        struct node *temp=p.second;
        if(i>=l && i<=h)
            cout<<temp->data<<" ";
        if(temp==NULL)
            q.push(make_pair(0,dinku));
        else
        {
            if(temp->left)
                q.push(make_pair(i+1,temp->left));
            if(temp->right)
                q.push(make_pair(i+1,temp->right));

        }
    }
    cout<<endl;
}

struct node * construct(struct node *root)
{
    if(root==NULL)
        return NULL;
    root->right=construct(root->left);
    root->left=construct(root->right);
    if(root->left==NULL && root->right==NULL)
        return root;
    else if(root->left==NULL)
    {
        struct node *new_root=root->right;
        free(root);
        return new_root;
    }
    else if(root->right==NULL)
    {
        struct node *new_root=root->left;
        free(root);
        return new_root;
    }

    return root;
};

int main()
{
    struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
    inorder(root);
    cout<<endl;
    struct node *n=construct(root);
    inorder(n);
    cout<<endl;
    return 0;

}



