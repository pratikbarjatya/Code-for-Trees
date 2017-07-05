
#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* get_newnode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    return newnode;
}

struct node* insert(struct node* root, int data){
    if (root==NULL)
    {
        root=get_newnode(data);
    }
    else if(root->data>=data){
        root->left=insert(root->left,data);
    }
    else {
        root->right = insert(root->right,data);
    }
    return root;
}

int max(int a,int b){
    if (a>b)
    {
        return a;
    }
    return b;
}

int find_height(struct node* root){
    if (root==NULL)
    {
        return 0;
    }
    return max(find_height(root->left), find_height(root->right))+1;
}

 
void level_order(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        level_order(root->left, level-1);
        level_order(root->right, level-1);
    }
}
 
int main(int argc, char const *argv[])
{

    struct node* root=(struct node*)malloc(sizeof(struct node));
    root=NULL;
    root=insert(root,50);   
    root=insert(root,59);
    root=insert(root,75);
    root=insert(root,100);
    root=insert(root,3);
    root=insert(root,99);
    int h = find_height(root);
    int i;
    for (i=1; i<=h; i++)
        level_order(root, i);
    
    return 0;
}