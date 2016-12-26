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

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}

int height(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	int lheight = height(root->left);
	int rheight = height(root->left);
	
	if(lheight > rheight)
	{
		return lheight+1;
	}
	else
	{
		return rheight+1;
	}
}

int diameter(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int lheight = height(root->left);
	int rheight = height(root->right);
	
	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);
	
	return max((lheight+rheight+1), max(ldiameter, rdiameter));
}

int main()
{
	struct node *root = createnode(10);
	root->left        = createnode(2);
  	root->right       = createnode(3);
  	root->left->left  = createnode(4);
 	root->left->right = createnode(5);
	
	
	printf("inorder:  ");
	inorder(root);
	printf("\n");
	
	printf("Diameter:  ");
	int dia = diameter(root);
	printf("%d", dia);
	printf("\n");
	
	return 0;
}
