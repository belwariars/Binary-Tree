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

void  printGivenLevel(struct node*, int, bool);

void BFS(struct node *root)
{
	int h = height(root);
	int i;
	bool flag = true;
	for(i=0; i<=h; i++)
	{
		printGivenLevel(root, i, flag);
		flag = !flag;
		printf("\n");
	}
}

void printGivenLevel(struct node* root, int level, bool flag)
{
	if(root == NULL)
	{
		return;
	}
	if(level == 1)
	{
		printf("%d ", root->data);
	}
	else
	{
		if(!flag)
		{
			printGivenLevel(root->left, level-1, flag);
			printGivenLevel(root->right, level-1, flag);
		}
		else
		{
			printGivenLevel(root->right, level-1, flag);
			printGivenLevel(root->left, level-1, flag);
		}
	}
}

int main()
{
	struct node *root = createnode(1);
    root->left        = createnode(2);
    root->right       = createnode(3);
    root->left->left  = createnode(7);
    root->left->right = createnode(6);
    root->right->left  = createnode(5);
    root->right->right = createnode(4);
    printf("Spiral Order traversal of binary tree is \n");
    BFS(root);
  	
  //	inorder(root);
  //	printf("\n");

  	
  	

	return 0;
}
