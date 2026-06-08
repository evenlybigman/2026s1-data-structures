# 자료구조 11주차

## 트리

자료들을 계층 구조로 나타낸 자료형

### 트리의 용어

루트, 서브트리

- 부모 노드가 없는 노드를 루트라고 하고 나머지 노드들을 서브트리라고 부른다.

부모, 형제, 자손 노드

- 인간의 관계와 동일

단말 노드, 비단말 노드

- 자식 노드가 없는 노드를 단말 노드, 있는 노드를 비단말 노드라고 한다.

레벨, 높이

- 루트가 레벨이 1이고, 아래로 갈수록 1씩 높아진다. 
- 제일 높은 레벨이 트리의 높이이다.

### 트리의 종류

트리는 일반 트리와 이진트리로 나눌 수 있다.

이 강의에서는 이진 트리만을 다룬다.

## 이진 트리

모든 노드가 2개의 서브트리를 가진 트리를 이진 트리라고 한다.

모든 이진 트리는 공집합도 포함한다.

### 이진 트리의 성질

1. 노드가 n개일 때 이진 트리의 간선의 개수는 n - 1개이다.
2. 높이가 n일때 노드는 최소 log 2 (n+1)개, 최대 2^n - 1개의 노드를 가질 수 있다.

### 이진 트리의 종류

이진 트리는 3가지로 나뉜다.

1. 포화 이진 트리
2. 완전 이진 트리
3. 기타 이진 트리

### 포화 이진 트리

포화 이진 트리는 말 그대로 모든 노드 꽉 차있는 이진 트리를 말한다. 모든 노드가 들어있기 때문에 노드의 개수는 이진 트리의 최대 노드 개수인 2^n - 1개이다. 포화 이진 트리는 번호를 붙일 수 있다. 위에서부터 붙이고 왼쪽부터 붙인다. 

### 완전 이진 트리

완전 이진 트리는 순서대로 번호를 붙일 때 중간에 빠지는 것 없이 번호를 붙일 수 있는 트리이다.  포화 이진 트리는 항상 완전 이진 트리이고 역은 성립하지 않는다.

### 기타 이진 트리

포화 이진 트리와 완전 이진 트리를 제외한 트리를 기타 이진 트리라고 한다.

### 이진 트리 구현

C언어에서 이진 트리는 배열과 링크를 이용해 구현할 수 있다.

### 배열 표현법

포화 이진 트리나 완전 이진 트리에서 많이 쓰인다.

나머지 이진 트리는 구현은 가능하나 메모리 낭비가 크다.

트리에 각각의 번호를 붙인 뒤 인덱스를 번호에 맞춰서 저장한다. 따라서 0번 인덱스는 사용하지 않는다.

부모와 자식 노드에서는 다음의 공식이 성립한다.

노드 i의 부모 인덱스 : i / 2

노드 i의 왼쪽 자식 노드 인덱스 : 2i

노드 i의 오른쪽 자식 노드 인덱스 : 2i + 1

배열 표현법에서는 노드의 인덱스만 알면 부모와 자식의 관계를 쉽게 알 수 있다.

### 링크 표현법

노드를 구조체로 표현하고 포인터로 노드와 노드를 연결하는 방법이다.

노드 구조체는 데이터 필드와 자식 노드를 가리키는 left와 right 필드가 있다.

실수 한 것 

​	struct TreeNode* left, right 

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left,* right;
}TreeNode;

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

	free(n1);
	free(n2);
	free(n3);
}
```

### 이진 트리의 순회

순회란 트리의 노드들을 체계적으로 방문하는 것을 말한다.

### 순회 방법

순회는 필요에 따라 다양한 방문 순서가 있다.

먼저 3가지는 루트를 방문하는 순서에 대한 방법이다.

### 전위 순회

루트를 제일 먼저 방문하는 방법이다.

루트 -> 왼쪽 서브 트리 -> 오른쪽 서브 트리

### 전위 순회 응용

구조화된 문서 출력

### 중위 순회

루트를 중간으로 방문하는 방법이다.

왼쪽 서브 트리 -> 루트 -> 오른쪽 서브 트리

### 중위 순회 응용

수식 트리

### 후위 순회

루트를 가장 마지막에 방문하는 방법이다.

왼쪽 서브 트리 -> 오른쪽 서브 트리 -> 루트

### 후위 순회 응용

디렉토리 용량 계산

### 트리 순회 구현

C언어로 순회를 구현하는 방법이다.

첫 번째는 재귀 호출을 이용하는 방법이 있다.

### 재귀 호출 / 전위 순회

```c
void preorder(TreeNode* root) {
	if (root) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
```

### 재귀 호출 / 중위 순회

```c
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}
```

### 재귀 호출 / 후위 순회

```c
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}
```

### 반복적인 순회

반복을 이용해서도 순회를 구현할 수 있다.

다음은 스택을 이용해 중위 순회를 구현한 것이다.

```c
#include <stdio.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct treeNode* left, * right;
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
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

TreeNode* pop() {
	if (top > -1) {
		return stack[top--];
	}
}

void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {
			push(root);
		}
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

int main() {
	printf("중위 순회= ");
	inorder_iter(root);
	printf("\n");
}
```

### 레벨 순회

레벨 순회는 레벨 순서대로 순회하는 것이다.

왼쪽에서 오른쪽을 순회한다. 큐를 이용해서 구현할 수 있다.

```c
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
```







