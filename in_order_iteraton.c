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

void in_order(struct node* root){
	struct stack st;
	st.top=-1;
	struct node* current=root;
	struct node* pre=root;
	struct node* temp=NULL; 
	if (root==NULL)
	{
		return;
	}
	push(&st,current);
	//pre=current;
	while(!(isempty(st))){
		while(current!=NULL){
			push(&st,current);
			current=current->left;			
		}
		temp=pop(&st);
		current=temp->right;
		if (!(isempty(st)))
			printf("%d ",temp->data );
	}
}

int main(int argc, char const *argv[])
{
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root=NULL;
	root=insert(root,50);	
	root=insert(root,49);
	root=insert(root,25);
	root=insert(root,20);
	root=insert(root,3);
	root=insert(root,99);
	in_order(root);
	//int h=find_height(root);
	//printf("%d\n",h );
	return 0;
}