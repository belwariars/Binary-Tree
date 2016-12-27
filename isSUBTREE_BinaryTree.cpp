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

bool isSame(struct node *root1, struct node *root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
	{
		return false;
	}
	if(root1->data != root2->data)
	{
		return false;
	}
	if(isSame(root1->left, root2->left) && isSame(root1->right, root2->right))
	{
		return true;
	}
	else
	{
		return false;
	}
//	isSame(root1->left, root2->left);
//	isSame(root1->right, root2->right);
	
//	return true;
	
//	return true;
}

bool subtree = false;
void isSubtree(struct node *root1, struct node *root2)
{
	if(root2 == NULL)
	{
		return;
	}
//	printf("root2= %d\n", root2->data);
	if(isSame(root1, root2))
	{
		subtree = true;
		return;
	}
	isSubtree(root1, root2->left);
	isSubtree(root1, root2->right);
}

int main()
{
/*	struct node *root = createnode(1);
    root->left        = createnode(2);
    root->right       = createnode(3);
    root->left->left  = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(8);    
    root->right->right->left  = createnode(6);    
    root->right->right->right  = createnode(7);	
    root->left->left->left = createnode(9);    
    root->left->left->right = createnode(10); */
	
  struct node *T        = createnode(26);
    T->right              = createnode(3);
    T->right->right       = createnode(3);
    T->left               = createnode(10);
    T->left->left         = createnode(4);
    T->left->left->right  = createnode(30);
    T->left->right        = createnode(6);
  
  struct node *S    = createnode(10);
    S->right          = createnode(6);
    S->left           = createnode(4);
    S->left->right    = createnode(30);	
 
 	isSubtree(S, T);
 	
 	if(subtree)
 	{
 		printf("YES\n");
	 }
	 else
	 {
	 	printf("NO\n");
	 }
	
	
	return 0;
}
