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

int max1 = 0;
int count1;

void printGivenLevel(struct node *, int level);

void BFS(struct node *root)
{
	int h = height(root);
	int i;
	for(i=1; i<=h; i++)
	{
		count1 = 0;
		printGivenLevel(root, i);
	}
}

void printGivenLevel(struct node *root, int level)
{
	if(root == NULL)
	{
		return;
	}
	if(level == 1)
	{
		count1++;
		if(count1 > max1)
		{
			max1 = count1;
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
	struct node *root = createnode(1);
    root->left        = createnode(2);
    root->right       = createnode(3);
    root->left->left  = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(8);    
    root->right->right->left  = createnode(6);    
    root->right->right->right  = createnode(7);	
    root->left->left->left = createnode(9);    
    root->left->left->right = createnode(10);	
 
 	printf("Level Order (BFS):  ");
	BFS(root);
	printf("\n");
	printf("\nMaximum Width:  %d", max1);
	
	
	return 0;
}
