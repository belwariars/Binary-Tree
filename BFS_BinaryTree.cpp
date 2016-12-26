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

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}

void preorder(struct node* root)
{
	if(root == NULL)
		return;
		
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	
}

void postorder(struct node* root)
{
	if(root == NULL)
		return;

		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	
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

void printGivenLevel(struct node *, int);

void printBFS(struct node *root)
{
	int h = height(root);
	int i;
	
	for(i=1; i<=h; i++)
	{
		printGivenLevel(root, i);
	}
}

void printGivenLevel(struct node *root, int level)
{
	if(root == NULL)
	{
		return;
	}
	else if(level == 1)
	{
		printf("%d ", root->data);
	}
	else
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

int main()
{
	struct node *root = createnode(10);
	root->left = createnode(20);
	root->right = createnode(30);
	root->left->left = createnode(40);
	root->left->right = createnode(50);
	
	printf("Inorder:  ");
	inorder(root);
	printf("\n");
	
	printf("Preorder:  ");
	preorder(root);
	printf("\n");
	
	printf("Postorder:  ");
	postorder(root);
	printf("\n\n");
	
	printf("Level Order (BFS):  ");
	printBFS(root);
	printf("\n");
	return 0;
}
