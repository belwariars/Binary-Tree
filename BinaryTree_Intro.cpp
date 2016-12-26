#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

struct node* createnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

void inorder(struct node* head)
{
	if(head!=NULL)
	{
		inorder(head->left);
		printf("%d ", head->data);
		inorder(head->right);
	}	
}

void preorder(struct node* head)
{
	if(head!=NULL)
	{
		printf("%d ", head->data);
		preorder(head->left);
		preorder(head->right);
	}	
}

void postorder(struct node* head)
{
	if(head!=NULL)
	{
		postorder(head->left);
		postorder(head->right);
		printf("%d ", head->data);
	}	
}

int main()
{
	struct node *head = createnode(10);
	head->left = createnode(20);
	head->right = createnode(30);
	head->left->left = createnode(40);
	head->left->right = createnode(50);
	
	printf("Inorder:  ");
	inorder(head);
	printf("\n");
	
	printf("Preorder:  ");
	preorder(head);
	printf("\n");
	
	printf("Postorder:  ");
	postorder(head);
	printf("\n");
	return 0;
}
