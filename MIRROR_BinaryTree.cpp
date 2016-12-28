#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
//	struct node *rightnext;	
};

struct node *createnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
//	newnode->rightnext = NULL;
	
	return newnode;
}

void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

struct node *mirror(struct node *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	
	mirror(root->left);
	mirror(root->right);
	
	struct node *temp = root->left;
	root->left = root->right;
	root->right = temp;
	return root;
	
	
}

int main()
{
	struct node *root = createnode(1);
  	root->left        = createnode(2);
  	root->right       = createnode(3);
  	root->left->left  = createnode(4);
  	root->left->right = createnode(5);
  	
  	inorder(root);
  	printf("\n");
  	
  	mirror(root);
  	inorder(root);
  	

	return 0;
}
