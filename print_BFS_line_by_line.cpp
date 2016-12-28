#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *rightnext;	
};

struct node *createnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->rightnext = NULL;
	
	return newnode;
}

void BFSlinebyline(struct node *root)
{
	list<struct node*> queue;
	struct node *temp = root;
	queue.push_back(temp);
	
	while(queue.size() > 0)
	{
		int count = queue.size();
		
		while(count--)
		{
			temp = queue.front();
			queue.pop_front();
			printf("%d ", temp->data);
			if(temp->left != NULL)
			{
				queue.push_back(temp->left);
			}
			if(temp->right != NULL)
			{
				queue.push_back(temp->right);
			}
		}
		printf("\n");
	}
}

int main()
{
	node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->right = createnode(6);
  	
  	BFSlinebyline(root);
  	

	return 0;
}
