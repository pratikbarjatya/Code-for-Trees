#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
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


void inorder(struct bstnode* root){
	if (root==NULL)
	{
		return;
	}	
	inorder(root->left);
	printf("%d ",root->data );
	inorder(root->root);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}