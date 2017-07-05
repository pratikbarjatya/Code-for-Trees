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


void postorder(struct bstnode* root){
	if (root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data );
}
int main(int argc, char const *argv[])
{
	struct bstnode* root=(struct bstnode*)malloc(sizeof(struct bstnode));
	root=NULL;
	root=insert(root,100);	
	root=insert(root,110);
	root=insert(root,90);
	root=insert(root,50);
	root=insert(root,200);
	root=insert(root,60);
	postorder(root);
	return 0;
}