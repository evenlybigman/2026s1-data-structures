#include <stdio.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

//       15
//     4  20
//   1  16  25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4,  &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20,  &n3,  &n4 };
TreeNode n6 = { 15,  &n2,  &n5 };
TreeNode* root = &n6;

#define SIZE 100

typedef struct {
	TreeNode* data[SIZE];
	int front, rear;
}QueueType;

void init(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % SIZE == q->front);
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void enqueue(QueueType* q,TreeNode* root) {
	if (is_full(q)) return;
	q->rear = (q->rear + 1) % SIZE;
	q->data[q->rear] = root;
}

TreeNode* dequeue(QueueType* q) {
	if (is_empty(q)) return;
	q->front = (q->front + 1) % SIZE;
	return q->data[q->front];
}

level_order(TreeNode* root) {
	QueueType q;

	init(&q);

	if (root == NULL) return;
	enqueue(&q, root);

	while (!is_empty(&q)) {
		root = dequeue(&q);
		printf("[%d] ", root->data);
		if (root->left)
			enqueue(&q, root->left);
		if (root->right)
			enqueue(&q, root->right);
	}
}

int main() {
	printf("레벨 순회= ");
	level_order(root);
	printf("\n");
}