#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
struct stack{
        int top;
        struct  node* items[101];
};

void push(struct stack* ms, struct node* item){
	ms->items[++ms->top]=item;
}
struct node* pop(struct stack* ms){
	if (ms->top>-1)
	{
		return ms->items[(ms->top)--];
	}
}
struct node* peek(struct stack ms){
	if(ms.top < 0){
      //printf("Stack empty\n");
      return 0;
   }
   return ms.items[ms.top];
}
int isempty(struct stack ms){
	if (ms.top<0)
	{
		return 1;
	}
	return 0;
}

void post_order(struct node* root){
	struct node* temp=root;
	struct node* current=root;
	struct stack first;
	struct stack second;
	first.top=second.top=-1;
	push(&first,current);
	while(!(isempty(first))){
		temp=pop(&first);
		push(&second,temp);
		if(temp->left){
			push(&first,temp->left);
		}
		if (temp->right)
		{
			push(&first,temp->right);
		}		
		
	}

	int i=second.top;
	while(i>=0){
		printf("%d ",second.items[i]->data );
		i--;
	}
}

int main()
{
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root=NULL;
	root=insert(root,100);	
	root=insert(root,110);
	root=insert(root,90);
	root=insert(root,50);
	root=insert(root,200);
	root=insert(root,60);
	post_order(root);
	return 0;
}