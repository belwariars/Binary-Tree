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

void distanceKnodes(struct node *root, int Kdist)
{
	list<struct node*> queue;
	struct node *temp = root;
	queue.push_back(temp);
	list<struct node*>:: iterator it;
	int k = 0;
	
	while(queue.size() > 0)
	{
		int count = queue.size();
		if(k == Kdist)
		{
			for(it=queue.begin(); it!=queue.end(); it++)
			{
				printf("%d ", (*it)->data);
			}
			break;
		}
		k++;
		while(count--)
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
	
	struct node *root = createnode(1);
  root->left        = createnode(2);
  root->right       = createnode(3);
  root->left->left  = createnode(4);
  root->left->right = createnode(5);
  root->right->left = createnode(8);	
 
 	distanceKnodes(root, 0);
	
	
	return 0;
}
