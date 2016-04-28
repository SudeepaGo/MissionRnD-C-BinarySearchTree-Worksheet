/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

void findClosestLeaf(struct node *, int, int *);
int findThroughParent(struct node *, struct node *, int *);

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root==NULL || temp==NULL)
       return -1;
	// Initialize result (minimum distance from a leaf)
	int minDist = INT_MAX;

	// Find closest leaf to temp
	findClosestLeaf(temp, 0, &minDist);

	// Find closest leaf through parent
	findThroughParent(root, temp, &minDist);

	return minDist;

}

//Function to find closest leaf to temp
void findClosestLeaf(struct node *root, int level, int *minDist)
{
	// base case
	if (root == NULL)
		return;

	// If this is a leaf node, then check if it is closer than the closest so far
	if (root->left == NULL && root->right == NULL)
	{
		if (level < (*minDist))
			*minDist = level;
		return;
	}

	// Recur for left and right subtrees
	findClosestLeaf(root->left, level + 1, minDist);
	findClosestLeaf(root->right, level + 1, minDist);
}

// Function to find if there is closer leaf to temp through parent node.
int findThroughParent(struct node * root,struct node *temp, int *minDist)
{
	// Base cases
	if (root == NULL) return -1;
	if (root == temp) return 0;

	// Search temp in left subtree of root
	int l = findThroughParent(root->left, temp, minDist);

	// If left subtree has temp
	if (l != -1)
	{
		// Find closest leaf in right subtree
		findClosestLeaf(root->right, l + 2, minDist);
		return l + 1;
	}

	// Search temp in right subtree of root
	int r = findThroughParent(root->right, temp, minDist);

	// If right subtree has temp
	if (r != -1)
	{
		// Find closest leaf in left subtree
		findClosestLeaf(root->left, r + 2, minDist);
		return r + 1;
	}

	return -1;
}