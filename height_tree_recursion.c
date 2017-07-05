#include "stdio.h"
#include "stdlib.h"

struct bstnode
{
	int data;
	struct bstnode* right;
	struct bstnode* left;
};

struct bstnode* get_newnode(int data){
	struct bstnode* newnode=(struct bstnode*)malloc(sizeof(struct bstnode));
	newnode->data=data;
	newnode->right=newnode->left=NULL;
	return newnode;
}

struct bstnode* insert(struct bstnode* root, int data){
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

int find_height(struct bstnode* root){
	if (root==NULL)
	{
		return -1;
	}
	return max(find_height(root->left), find_height(root->right))+1;
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
	int h=find_height(root);
	printf("%d\n",h );
	
	return 0;
}