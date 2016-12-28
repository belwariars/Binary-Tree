#include <bits/stdc++.h>
using namespace std;

// http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/

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

void mirror(struct node *root)
{
	if(root == NULL)
	return;
	
	mirror(root->left);
	mirror(root->right);
	
	struct node *temp = root->left;
	root->left = root->right;
	root->right = temp;
}
bool flag = true;
void foldable(struct node *root1, struct node *root2)
{
	if(root1 == NULL && root2 == NULL)
	return;
	
	if((root1->left == NULL && root2->left != NULL) || (root1->left != NULL && root2->left == NULL))
	{
		flag = false;
		return;
	}
	if((root1->right == NULL && root2->right != NULL) || (root1->right != NULL && root2->right == NULL))
	{
		flag = false;
		return;
	}
	foldable(root1->left, root1->left);
	foldable(root1->right, root2->right);
	
}

int main()
{
	struct node *root = createnode(1);
  	root->left        = createnode(2);
  	root->left->left       = createnode(3);
  	root->left->left->left  = createnode(4);
  	root->left->left->left->left = createnode(5);
  	root->right        = createnode(2);
  	root->right->right       = createnode(3);
  	root->right->right->right  = createnode(4);
  	root->right->right->right->right = createnode(5);
  	
  	struct node *root1 = createnode(1);
  	root1->left        = createnode(2);
  	root1->left->left       = createnode(3);
  	root1->left->left->left  = createnode(4);
  	root1->left->left->left->left = createnode(5);
  	root1->right        = createnode(2);
  	root1->right->right       = createnode(3);
  	root1->right->right->right  = createnode(4);
  	root1->right->right->right->right = createnode(5);
  
  	inorder(root);
    mirror(root);
    printf("\n");
	inorder(root);
	printf("\n\n");
	foldable(root, root1);
	
	if(flag)
	{
		printf("Foldable\n");
	}
	else
	{
		printf("Not-Foldable");
	}
    
    
	return 0;
}
