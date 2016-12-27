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

bool isSame(struct node *root1, struct node *root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
	{
		return false;
	}
	if(root1->data != root2->data)
	{
		return false;
	}
	if(isSame(root1->left, root2->left) && isSame(root1->right, root2->right))
	{
		return true;
	}
	else
	{
		return false;
	}
//	isSame(root1->left, root2->left);
//	isSame(root1->right, root2->right);
	
//	return true;
	
//	return true;
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
	
  struct node *root1 = createnode(1);
  root1->left        = createnode(2);
  root1->right       = createnode(3);
  root1->left->left  = createnode(4);
  root1->left->right = createnode(5);
  root1->right->left = createnode(8);
  
  struct node *root2 = createnode(1);
  root2->left        = createnode(2);
  root2->right       = createnode(3);
  root2->left->left  = createnode(4);
  root2->left->right = createnode(5);
  root2->right->left = createnode(8);	
 
 	if(isSame(root1, root2))
 	{
 		printf("YES\n");
	 }
	 else
	 {
	 	printf("NO\n");
	 }
	
	
	return 0;
}
