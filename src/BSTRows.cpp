/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order here is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

int find_depth(struct node*);
int storeGivenRow(struct node*, int);

struct node{
	struct node * left;
	int data;
	struct node *right;
};



int* BSTRighttoLeftRows(struct node* root)
{
	
	if (root==NULL)
    return NULL;
	int depth = find_depth(root);

	int *arr = (int *)malloc(sizeof(int)*50);
	int k = 0;

	for (int i = 1; i <= depth; i++)   //Going to each level in the tree
	{
		arr[k++]=storeGivenRow(root, i); //Storing the elements of each level
		
	}
	return arr;
}

int storeGivenRow(struct node *root, int d)
{
	if (root == NULL)
		return -1;
	if (d == 1)               //Return the value of root if level equal to 1
		return root->data;
	else
	{
		if (root->right!=NULL)    //Traverse through right node in the given level
		storeGivenRow(root->right, d - 1);
		if (root->left!=NULL)      //Traverse through left node in the given level
		storeGivenRow(root->left, d - 1); 
	}
}

//Function to find depth/height of the binary search tree
int find_depth(struct node *root){
	int ldepth, rdepth;
	if (root == NULL)
		return 0;
	else
	{
		/* compute the depth of left and right subtrees */
	    ldepth = find_depth(root->left);
	    rdepth = find_depth(root->right);

		/* return the greater depth */
		if (ldepth >= rdepth)
			return(ldepth + 1);
		else return(rdepth + 1);
	}
}