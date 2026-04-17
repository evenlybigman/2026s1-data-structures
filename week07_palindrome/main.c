#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAX_QUEUE_SIZE 100

//원형 큐 구현
typedef char element;
typedef struct Queue {
	int rear;
	int front;
	element data[MAX_QUEUE_SIZE];
}Queue;

void init_queue(Queue* q) { //큐 초기화
	q->rear = q->front = 0; 
}

int is_empty(Queue* q) { //rear값과 front값이 같으면 공백
	if (q->rear == q->front) return 1;
	return 0;
}

int is_full(Queue* q) { // 포화 상태
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) { //rear 바로 앞에 front가 있다면
		return 1;
	}
	return 0;
}

void add_rear(Queue* q, element item) { //rear에 item추가 하고 rear값 증가 하는 인큐
	if (is_full(q) == 1) {
		printf("포화 상태");
		return;
	}
	q->data[q->rear] = item;
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
}

void add_front(Queue* q, element item) {
	if (is_full(q) == 1) {
		printf("포화 상태");
		return;
	}
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	q->data[q->front] = item;
}

element delete_rear(Queue* q) { //rear값을 반환하고 rear 값 1 감소 근데? 0일때는 99가 되야함
	if (is_empty(q) == 1) { // rear - 1 / rear + 1값을 반환
		printf("공백 상태");
		return -1;
	} // 
	q->rear = (q->rear-1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[q->rear];
}

element delete_front(Queue* q) { // front + 1 되야하는데? 99 => 0 
	element ch;
	if (is_empty(q) == 1) {
		printf("공백 상태");
		return -1;
	}
	ch = q->data[q->front];
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return ch;
}

element get_rear(Queue* q) {
	if (is_empty(q) == 1) {
		printf("공백 상태");
		return -1;
	}
	return q->data[(q->rear -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE];
}

element get_front(Queue* q) {
	if (is_empty(q) == 1) {
		printf("공백 상태");
		return -1;
	}
	return q->data[q->front % MAX_QUEUE_SIZE];
}

int main() {
	Queue q;
	int wordcount = 0; //단어 개수
	int result = 1; //1이면 회문 아니면 아님
	init_queue(&q);
	char str[100];
	printf("회문인지 검사할 단어를 입력하세요 : ");
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) { //단어 인큐  
		if (isalpha(str[i] == 1)) { //알파벳이면

			add_rear(&q, tolower(str[i])); //소문자로 저장
			wordcount++; //단어 갯수 세기
		}
	}
	for (int i = 0; i < (wordcount / 2); i++) { //글자 수 검사
		if (delete_rear(&q) != delete_front(&q)) { //맨 앞글자랑 맨 뒷글자랑 같다면
			result = 0; 
			break;
		}
	}
	if (result)
		printf("회문입니다.");
	else printf("회문이 아닙니다.");
	
	return 0;
}
