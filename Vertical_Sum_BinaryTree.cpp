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

unordered_map<int, int> container;

void verticalSum(struct node *root, int ver)
{
	if(root == NULL)
	return;
	
	if(container.find(ver) != container.end())
	{
		container.find(ver)->second += root->data;
	}
	else
	{
		container.insert(make_pair(ver, root->data));
	}
	verticalSum(root->left, ver-1);
	verticalSum(root->right, ver+1);
}

int main()
{
	struct node *root = createnode(1);
  	root->left = createnode(2);
  	root->right = createnode(3);
  	root->left->left = createnode(4);
  	root->left->right = createnode(5);
  	root->right->left = createnode(6);
  	root->right->right = createnode(7);
 	
 	
    verticalSum(root, 0);
    
    unordered_map<int, int>:: iterator it;
    for(it = container.begin(); it!=container.end(); it++)
    {
    	printf("%d - %d\n", it->first, it->second);
	}
    
   
	return 0;
}
