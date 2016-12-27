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

int height(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int lheight = height(root->left);
	int rheight = height(root->right);
	
	if(lheight > rheight)
	{
		return lheight+1;
	}
	else
	{
		return rheight+1;
	}
}
bool flag = false;
stack<struct node*> st;

bool ancestors(struct node *root, int target)
{
	if(root == NULL)
	{
		return false;
	}
	
	if(root->data == target)
	{
		return true;
	}
	if(ancestors(root->left, target) || ancestors(root->right, target))
	{
		printf("%d ", root->data);
	}
	else
	{
		return false;
	}
}

int main()
{
/*	struct node *root = createnode(1);
    root->left        = createnode(2);
    root->right       = createnode(3);
    root->left->left  = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(8);    
    root->right->right->left  = createnode(6);    
    root->right->right->right  = createnode(7);	
    root->left->left->left = createnode(9);    
    root->left->left->right = createnode(10); */
	
	struct node *root = createnode(1);
  root->left        = createnode(2);
  root->right       = createnode(3);
  root->left->left  = createnode(4);
  root->left->right = createnode(5);
  root->right->left = createnode(8);	
 
 	ancestors(root, 8);
	
	
	return 0;
}
