#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* head) {
    head->llink= head;
    head->rlink = head;
}

void printDlist(DlistNode* head) {
    DlistNode* current;
    for (current = head->rlink; current != head; current = current->rlink) {
        printf("<-| |%d| |->",current->data);
    }
    printf("\n");
}

void dinsert (DlistNode* before, element item) {
    // 새 노드를 before 노드 뒤에 삽입 하는 함수
    // before -> A   ->>>   before -> newNode -> A
    DlistNode* newNode = (DlistNode*)malloc(sizeof(DlistNode));
    newNode->data = item;
    newNode->llink = before;
    newNode->rlink = before->rlink;
    before->rlink->llink = newNode;
    before->rlink = newNode;
}

void ddelete(DlistNode* head, DlistNode* removed) {
    if (removed == head) return;
    // A <- -> removed <- -> C
    removed->llink->rlink = removed->rlink; // A -> C
    removed->rlink->llink = removed->llink; // A <- C
    free(removed);
}

DlistNode* dsearch(DlistNode* head, element data) {
    DlistNode* current;
    for (current = head->rlink; current != head; current = current->rlink) {
        if (current->data == data) return current;
    }
    return NULL;
}

int main() {
    DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
    init(head);
    dinsert(head,1);
    printDlist(head);
    dinsert(head, 2);
    printDlist(head);
    dinsert(head, 3);
    printDlist(head);

    element data;
    while (1) {
        printf("탐색할 값: ");
        scanf("%d", &data);
        if (dsearch(head, data) != NULL) printf("값이 있습니다.\n");
        else printf("값이 없습니다.\n");
    }
}

