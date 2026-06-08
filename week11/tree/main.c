#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode{
	element data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

int min = INT_MAX;
int max = INT_MIN;
element tree_min(TreeNode* root) {
	if (root != NULL) {
		tree_min(root->left);
		tree_min(root->right);
		if (root->data < min) min = root->data;
	}
	return min;
}

element tree_max(TreeNode* root) {
	if (root != NULL) {
		tree_max(root->left);
		tree_max(root->right);
		if (root->data > max) max = root->data;
	}
	return max;
}

int main() {
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;

	printf("최소값 = %d\n", tree_min(n1));
	printf("최대값 = %d\n", tree_max(n1));
}