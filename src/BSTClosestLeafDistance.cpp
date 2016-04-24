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

int get_distance(struct node*);

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root==NULL || temp==NULL)
       return -1;
	int d = get_distance(temp);
	return d-1;
}

int get_distance(struct node *root){
	int lcount = 0, rcount = 0;

	if (root == NULL)
		return 0;
	else
	{
		/* compute the depth of left and right subtrees */
		lcount = get_distance(root->left);
		rcount = get_distance(root->right);

		/* return the greater depth */
		if (lcount >= rcount)
			return(lcount + 1);
		else return(rcount + 1);
	}
}