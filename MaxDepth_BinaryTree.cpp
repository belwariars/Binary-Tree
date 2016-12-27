#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

int maxDepth(struct node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int ldepth = maxDepth(root->left);
	int rdepth = maxDepth(root->right);
	
	if(ldepth > rdepth)
	{
		return ldepth + 1;
	}
	else
		return rdepth + 1;
}

struct node *createnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

int main()
{
	struct node *root = createnode(1);
	root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    
    int Depth = maxDepth(root);
    printf("Depth:  %d", Depth);
	return 0;
}
