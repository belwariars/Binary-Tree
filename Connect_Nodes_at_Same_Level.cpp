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

void connectNodes(struct node *root)
{
	list<struct node*> queue;
	struct node *temp = root;
	queue.push_back(temp);
	
	while(queue.size() > 0)
	{
		bool flag = false;
		int count = queue.size();
		struct node *prev = NULL;
		while(count--)
		{
			temp = queue.front();
			queue.pop_front();
			if(temp->left != NULL)
			{
				if(!flag)
				{
					queue.push_back(temp->left);
					prev = temp->left;
					flag = true;
				}
				else
				{
					prev->rightnext = temp->left;
					prev = temp->left;
					queue.push_back(temp->left);
				}
			}
			if(temp->right != NULL)
			{
				if(!flag)
				{
					queue.push_back(temp->right);
					prev = temp->right;
					flag = true;
				}
				else
				{
					queue.push_back(temp->right);
					prev->rightnext = temp->right;
					prev = temp->right;
				}
			}
			
		//	prev->rightnext = NULL;
		}
	}
}

int main()
{
	struct node *root = createnode(10);
  	root->left        = createnode(8);
  	root->right       = createnode(2);
  	root->left->left  = createnode(3);
  	root->right->left  = createnode(4);
  	root->right->right  = createnode(6);
  	
  	connectNodes(root);
  	
  	printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  	printf("nextRight of %d is %d \n", root->data,
         root->rightnext? root->rightnext->data: -1);
  	printf("nextRight of %d is %d \n", root->left->data,
        root->left->rightnext? root->left->rightnext->data: -1);
  	printf("nextRight of %d is %d \n", root->right->data,
        root->right->rightnext? root->right->rightnext->data: -1);
  	printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->rightnext? root->left->left->rightnext->data: -1); 
	printf("nextRight of %d is %d \n", root->right->left->data,
        root->right->left->rightnext? root->right->left->rightnext->data: -1); 
	return 0;
}
