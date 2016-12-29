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
}

void inorder(struct node *root)
{
	if(root == NULL)
	return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int sum =0;

int sumofchildren(struct node *root)
{
	if(root == NULL)
	return 0;
	
	sumofchildren(root->left);
	sum = sum + root->data;
	sumofchildren(root->right);
	
	return sum - root->data;
}

void sumTree(struct node *root)
{
	if(root == NULL)
	return;
	
	int newsum = sumofchildren(root);
	root->data = newsum;
	sum = 0;
	sumTree(root->left);
	sumTree(root->right);
}

int main()
{
	struct node *root = createnode(10);
  	root->left = createnode(-2);
 // 	root->right = createnode(6);
  	root->left->left = createnode(8);
  //	root->left->right = createnode(-4);
  	root->left->left->left = createnode(7);
 // 	root->right->right = createnode(5);
 	root->left->left->left->left = createnode(8);
 	
    // Populates nextRight pointer in all nodes
    inorder(root);
    printf("\n");
	sumTree(root);
	inorder(root);
   
	return 0;
}
