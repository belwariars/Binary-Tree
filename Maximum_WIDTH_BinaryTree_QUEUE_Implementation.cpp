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

int counti = 0;
int maxi = 0;

void BFSqueue(struct node *root)
{
	list<struct node*> queue;
	struct node *temp = root;
	queue.push_back(temp);	
	while(queue.size() > 0)
	{
		counti = queue.size();
		//printf("counti =  %d", counti);
		if(counti > maxi)
		{
			maxi = counti;
		}
		
		while(counti--)
		{
			temp = queue.front();
			queue.pop_front();
			
			if(temp->left != NULL)
			{
				queue.push_back(temp->left);
			}
			if(temp->right != NULL)
			{
				queue.push_back(temp->right);
			}
		}
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
 
 	BFSqueue(root);
	printf("Maximum Width:  %d", maxi);
	
	
	return 0;
}
