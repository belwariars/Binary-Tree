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

void inorderStack(struct node *root)
{
	struct node *curr = root;
	stack<struct node*> stack;
	HERE:
	while(curr != NULL)
	{
		stack.push(curr);
		curr = curr->left;
	}
	
	if(curr == NULL && stack.size()>0)
	{
		printf("%d ", (stack.top())->data);
		struct node *prev = stack.top();
		curr = prev->right;
		stack.pop();
		goto HERE;
	}
}

int main()
{
	struct node *root = createnode(10);
	root->right        = createnode(2);
//  	root->right       = createnode(3);
  	root->right->right  = createnode(4);
 	root->right->right->right = createnode(5);
	root->right->right->right->right = createnode(6); 
	
	printf("inorder:  ");
	inorderStack(root);
	printf("\n");
	

	
	return 0;
}
