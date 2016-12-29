#include <bits/stdc++.h>
using namespace std;

// Time Complexity :  O(n^2)... as fron recursion and if skewed tree then, .find() anothe n so n*n = n^2
// Space Complexity : O(n+n) = O(2n) = O(n)

struct nodeT
{
	int data;
	struct nodeT *left;
	struct nodeT *right;	
};

struct nodeL
{
	int data;
	struct nodeL *next;
};

struct nodeT* createnodeT(int data)
{
	struct nodeT *newnodeT = (struct nodeT*)malloc(sizeof(struct nodeT));
	newnodeT->data = data;
	newnodeT->left = NULL;
	newnodeT->right = NULL;
	
	return newnodeT;
}

struct nodeL* createnodeL(int data)
{
	struct nodeL *newnodeL = (struct nodeL*)malloc(sizeof(struct nodeL));
	newnodeL->data = data;
	newnodeL->next = NULL;
	
	return newnodeL;
}

void inorder(struct nodeT *root)
{
	if(root == NULL)
	return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

struct nodeT* BFS(struct nodeL *head)
{
	list<struct nodeT*> queue;
	struct nodeT *temp = createnodeT(head->data);
	struct nodeT *root = temp;
	head = head->next;
	queue.push_back(temp);
	bool flag = true;
	while(queue.size() > 0)
	{
		int count = queue.size();
		
		
		while(count--)
		{
			temp = queue.front();
			queue.pop_front();
			temp->left = createnodeT(head->data);
			head = head->next;
			if(head == NULL)
			{
				flag=false;
				break;
			}
			//goto HERE;
			temp->right = createnodeT(head->data);
			head = head->next;
			if(head == NULL)
			{
				flag=false;
				break;
			}
			//goto HERE;
			if(temp->left != NULL)
			{
				queue.push_back(temp->left);
			}
			if(temp->right != NULL)
			{
				queue.push_back(temp->right);
			}
		}
		if(flag==false)
			break;
	}
	if(flag==false)
	return root;
}

int main()
{
	struct nodeL *head =  createnodeL(10);
  	head->next = createnodeL(12);
  	head->next->next = createnodeL(15);
  	head->next->next->next = createnodeL(25);
  	head->next->next->next->next = createnodeL(30);
  	head->next->next->next->next->next = createnodeL(36);
  	struct nodeT *root = BFS(head);
  	printf("\n\n");
  	inorder(root);
  	
	return 0;
}
