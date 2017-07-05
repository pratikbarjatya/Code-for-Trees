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
struct queue
{
	struct node* queues;
	struct queue* link;
}*front=NULL,*rear=NULL;

struct queue* newNode1(struct node* root)
{
	struct queue *newnode;
	newnode=(struct queue *)malloc(sizeof(struct queue));
	newnode->queues=root;
	newnode->link=NULL;	
	return newnode;
}	

void enqueue(struct node* x)
{
	struct queue *temp;
	temp=newNode1(x);
	if (rear==NULL){
		front=rear=temp;
		front->link=NULL;
		rear->link=NULL;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}	
}

void dequeue()
{
	struct node *temp;
	temp=front->queues;
	if (front==NULL)
	{
		printf("Queue is empty\n");
		front=rear=NULL;
	}
	else
	{
		if(front==rear){
			front=NULL;
			rear=NULL;
		}
		else
			front=front->link;

		free(temp);

	}
}

int sizeofqueue(){
	struct queue* back=front;
	int count=0;
	while(back!=NULL){
		count++;
		back=back->link;
	}
	return count;
}

int height(struct node* root){
	int h=0;
	enqueue(root);
	while(1){
		int count=sizeofqueue();
		if (count==0)
		{
			return h;
		}
		else{
			h++;
		}
		while(count>0){
			struct node* cur;
			cur=front->queues;
			dequeue();			
			if (cur->right!=NULL)
			{
				enqueue(cur->right);	
			}
			if (cur->left!=NULL)
			{
				enqueue(cur->left);
			}
			count--;
		}

	}
	return h;
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
	int h=height(root);
	printf("%d\n",h );
	return 0;
}