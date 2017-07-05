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


void preorder(struct bstnode* root){
	if (root==NULL)
	{
		return;
	}
	printf("%d ",root->data );
	preorder(root->left);
	preorder(root->right);
}
int main(int argc, char const *argv[])
{
	struct bstnode* root=(struct bstnode*)malloc(sizeof(struct bstnode));
	root=NULL;
	root=insert(root,50);	
	root=insert(root,49);
	root=insert(root,51);
	root=insert(root,20);
	root=insert(root,3);
	root=insert(root,99);
	//int h=find_height(root);
	//printf("%d\n",h );
	preorder(root);
	
	return 0;
}