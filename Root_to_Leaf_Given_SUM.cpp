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

bool flag = false; // GLOBAL
void checkSum(int arr[], int n, int sum)
{
	int i =0;
	int sumcurr = 0;
	for(i=0; i<n; i++)
	{
		sumcurr = sumcurr +arr[i];
		//printf("%d ", arr[i]);
	}
	if(sumcurr == sum)
	{
		flag = true;
		for(i=0; i<n; i++)
		{
			sumcurr = sumcurr +arr[i];
			printf("%d ", arr[i]);
		}
	}
}
void rootToLeafSum(struct node *root, int arr[], int i, int sum)
{
	if(root == NULL)
	return;
	
	
	arr[i++] = root->data;
	if(root->left == NULL && root->right == NULL)
	{
		checkSum(arr, i, sum);
		return;
	}
	
	rootToLeafSum(root->left, arr, i, sum);
	rootToLeafSum(root->right, arr, i, sum);
}

int main()
{
	struct node *root = createnode(10);
  	root->left        = createnode(8);
  	root->right       = createnode(2);
  	root->left->left  = createnode(3);
  	root->left->right = createnode(5);
  	root->right->left = createnode(2);
  
  	int arr[100];
    rootToLeafSum(root, arr, 0, 23);
    
    if(flag)
    {
    	printf("\nyes\n");
	}
	else
	{
		printf("\nNo");
	}
    
    
	return 0;
}
