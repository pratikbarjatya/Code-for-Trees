#include <stdio.h>
#include <stdlib.h>

struct bin_node
{
	int data;
	struct bin_node *left;
	struct bin_node *right;
};

struct node
{
	struct bin_node *data;
	struct node *link;
}*front=NULL,*rear=NULL;

struct node* newNode1(struct bin_node *x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->link=NULL;	
	return newnode;
}	

struct bin_node* newNode(int data)
{
	struct bin_node *newnode;
	newnode=(struct bin_node *)malloc(sizeof(struct bin_node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;	
	return newnode;
}	

void enqueue(struct bin_node *x)
{
	struct node *temp;
	temp=newNode1(x);
	if (rear==NULL)
		front=rear=temp;
	else
	{
		rear->link=temp;
		rear=temp;
	}	
}

void dequeue()
{
	struct node *temp;
	temp=front;
	if (front==NULL)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->link;
		free(temp);
	}
}

int check_empty()
{
	if (front==NULL)
		return 1;
	return 0;
}

void level_order(struct bin_node *newnode)
{	
	if (newnode->left!=NULL)
		enqueue(newnode->left);
	if (newnode->right!=NULL)
		enqueue(newnode->right);
	printf("%d ",newnode->data);
	dequeue();
	if (check_empty()==0)
		level_order(front->data);
}

int main()
{
	struct bin_node *root, *newnode6, *newnode5, *newnode4, *newnode3, *newnode2, *newnode1;
	newnode6=newNode(16);
	newnode5=newNode(50);
	newnode4=newNode(16);
	newnode3=newNode(25);
	newnode2=newNode(254);
	newnode1=newNode(10);
	root=newNode(14);
	root->left=newnode1;
	root->right=newnode2;
	newnode1->left=newnode3;
	newnode1->right=newnode4;
	newnode2->right=newnode5;
	newnode4->left=newnode6;
	enqueue(root);
	level_order(root);
	return 0;
}
