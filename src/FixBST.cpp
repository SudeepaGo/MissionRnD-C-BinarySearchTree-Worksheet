/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>

void fixBSTHelper(struct node*, struct node**, struct node**, struct node**, struct node**);
void swap(int *, int *);

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fix_bst(struct node *root){
	// Initialize pointers needed for fixBSTHelper()
	struct node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;

	//Call the function to find out the misplaced two nodes
	fixBSTHelper(root, &first, &middle, &last, &prev);

	// Fix the tree if misplaced nodes exist
	if (first && last)   //Non adjacent nodes misplaced
		swap(&(first->data), &(last->data));
	else if (first && middle) // Adjacent nodes misplaced
		swap(&(first->data), &(middle->data));

}

void fixBSTHelper(struct node* root, struct node** first, struct node** middle, struct node** last,  struct node** prev)
{
	if (root)
	{
		// Recur for the left subtree
		fixBSTHelper(root->left, first, middle, last, prev);

		// If this node is smaller than the previous node, it's violating the BST rule.
		if (*prev && root->data < (*prev)->data)
		{
			// If this is first violation, mark these two nodes as 'first' and 'middle'
			if (!*first)
			{
				*first = *prev;
				*middle = root;
			}

			// If this is second violation, mark this node as last
			else
				*last = root;
		}

		// Mark this node as previous
		*prev = root;

		// Recur for the right subtree
		fixBSTHelper(root->right, first, middle, last, prev);
	}
}

//Function to swap the misplaced nodes
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}