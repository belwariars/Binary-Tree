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

int height(struct node *root)
{
	if(root == NULL)
	return 0;
	
	int lheight = height(root->left);
	int rheight = height(root->right);
	
	if(lheight > rheight)
	return lheight+1;
	else
	return rheight+1;
}

bool flag = true;
bool flag1 = true;
void printGivenLevel(struct node *, int);
int counti = 0;
void BFS(struct node *root)
{
	int h = height(root);
	int i;
	for(i=1; i<h; i++)
	{
		printGivenLevel(root, i);
		if(counti == pow(2, i-1))
		{
			counti = 0;
		}
		else
		{
			flag = false;
			return;
		}
	}
	flag1 = true;
	printGivenLevel(root, h-1);
}
bool flagrt = true;
void printGivenLevel(struct node *root, int level)
{
	if(root == NULL)
	return;
	
	if(level == 1)
	{
		printf("%d ", root->data);
		counti++;
		if(root->left!=NULL && flag1 == false)
		{
			flag=false;
		}
		if(root->left==NULL)
		{
			flag1=false;
		}
		if(root->right!=NULL && flag1 == false)
		{
			flag=false;
		}
		if(root->right==NULL)
		{
			flag1=false;
		}
	}
	else
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

int main()
{
	struct node *root  = createnode(1);
  	root->left         = createnode(2);
  	root->right         = createnode(3);
	root->left->left        = createnode(4);
	root->left->right        = createnode(5);
	root->right->left        = createnode(8);
 // 	root->left->left        = createnode(3);
//  	root->left->left->left   = createnode(4);
  //	root->left->left->left->left  = createnode(5);
  	//root->left->left->left->left->left = createnode(6); 
  	
  	BFS(root);
  //	printf("%d", flag1);
  	if(flag)
  	{
  		printf("Yes\n");
	  }
	else
	{
		printf("No\n");
	}
  	
	return 0;
}
