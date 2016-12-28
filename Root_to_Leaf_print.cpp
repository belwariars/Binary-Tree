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

void printRoute(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void rootToLeaf(struct node *root, int arr[], int i)
{	
	if(root == NULL)
	{
		//int n = sizeof(arr)/sizeof(arr[0]);
		//printRoute(arr, i);
		return ;
	}
	
	arr[i++] = root->data;
	if(root->left == NULL && root->right == NULL)
	{
		printRoute(arr, i);
		return;
	}
	
		rootToLeaf(root->left, arr, i);
		rootToLeaf(root->right, arr, i);

	
//	return root;
}

int main()
{
	struct node *root = createnode(1);
  	root->left        = createnode(2);
  	root->right       = createnode(3);
  	root->left->left  = createnode(4);
  	root->left->right = createnode(5);
  	
  //	inorder(root);
  //	printf("\n");
  	
  	int arr[100];
  	rootToLeaf(root, arr, 0);
  	
  	

	return 0;
}
