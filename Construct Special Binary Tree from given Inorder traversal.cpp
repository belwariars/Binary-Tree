#include <bits/stdc++.h>
using namespace std;

// Time Complexity :  O(n^2)... as fron recursion and if skewed tree then, .find() anothe n so n*n = n^2
// Space Complexity : O(n+n) = O(2n) = O(n)

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

int maxelem(int arr[], int start, int end)
{
	int i;
	int max = INT_MIN;
	int maxindex = INT_MIN;
	for(i=start; i<=end; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			maxindex = i;
		}
	}
	
	return maxindex;
}

struct node* constructInorder(int arr[], int start, int end)
{
	if(start > end)
	return NULL;
	
	int n = maxelem(arr, start, end);
	struct node* root = createnode(arr[n]);
	
	if(start == end)
	{
		return root;
	}
	root->left = constructInorder(arr, start, n-1);
	root->right = constructInorder(arr, n+1, end);
	
	return root;
}

int main()
{
	int inorderarr[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorderarr)/sizeof(inorderarr[0]);
    
    
 	struct node *root = constructInorder(inorderarr, 0, len-1);
 	inorder(root);
 	
 	
    
    
   
	return 0;
}
