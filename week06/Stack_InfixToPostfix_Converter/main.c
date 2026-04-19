// 5 * (10 + 2) % 2 를  스택을 이용해서 후위 연산자로 바꿀려면?  결과값 5 10 2 + * 2 %
// 5			출력 5 
// * [*]	    출력 5
// ( [*] [(]    출력 5
// 10 [*] [(]   출력 5 10
// + [*] [(] [+]출력 5 10
// 2 [*] [(] [+]출력 5 10 2
// ) [*]        출력 5 10 2 +  (를 만날 때 까지 pop 한뒤 () 같이 pop
// % [%]		출력 5 10 2 + * 안에 같은 우선순위가 있으면 pop한뒤 push 낮다면 그냥 push
// 2            출력 5 10 2 + * 2 % 식이 끝났다면 스택에 있는거 전부 pop

//1. 피연산자가 나온다면 바로 출력한다. 구현 완료
//2. )가 나온다면 (가 나올때까지 pop 한뒤 (를 팝한다. 구현 완료
//3. 연산자가 push 됐을때 이전에 있던 아이템이 우선순위가 같거나 높다면 pop을 한뒤 푸쉬한다. 구현 완료
//4. 모든 식이 끝나면 남은 스택을 모두 pop 한다. 구현 완료

#include <stdio.h>
char expression[100] = "5*(10+2)%2"; //바꿀 식
char stack[100] = "0"; //스택 초기화
int top = -1; //탑 초기화

int is_full(int top) { //스택 full 확인
	if (top == 99) return 1;
	else return 0;
}

int is_empty(int top) { //스택 empty 확인
	if (top == -1) return 1;
	else return 0;
}

char peek() { //탑 내용물 확인
	if (is_empty(top) == 1) { printf("not found"); return 0; }
	else return stack[top];
}

void push(char exp) { //스택에 푸쉬
	if (is_full(top) == 1) printf("overflow");
	else {
		++top;
		stack[top] = exp;
	}
}

char pop() { //팝
	if (is_empty(top) == 1) printf("underflow");
	else {
		top--;
		return stack[top + 1];
	}
}

int priority(char op) { //우선순위
	if (op == '*' || op == '%' || op == '/') return 2; //1순위
	else if (op == '+' || op == '-') return 1; //2순위
	else if (op == '(') return 0; // ( 팝되면 안되기에 우선순위가 낮아야함
	else return -1; //나머지 미구현
}

int is_op(char expression) { //연산자인지 확인
	if (expression == '+' || expression == '-' || expression == '*'
		|| expression == '%' || expression == '(' || expression == ')')
		return 1;
	else return 0;
}

int main() {
	for (int i = 0; expression[i] != '\0'; i++) { //NULL이 나올 때 까지 반복
		if (is_op(expression[i]) == 0) { //피연산자라면
			//식이 끝나거나 연산자가 나올때까지 숫자 출력
			while (expression[i] != '\0' && is_op(expression[i]) == 0) {
				printf("%c", expression[i]); //숫자 출력
				i++; //연산자가 나올때까지 i값 증가
			}
			printf(" "); //숫자마다 띄어쓰기
			i--; //다른 것 읽는거 방지용
		}
		else if (expression[i] == '(') { // (이면 바로 푸쉬
			push(expression[i]);
		}
		else if (expression[i] == ')') { //닫는 괄호라면
			while (peek() != '(') { //(가 나올때까지
				printf("%c ", pop()); //팝
			}
			pop(); //이후 ( 팝
		}
		else if (is_op(expression[i]) == 1) { //연산자라면
			//스택이 비어있는게 아니고 우선순위가 같거나 큰게 있으면 팝
			while (is_empty(top) == 0 && priority(peek()) >= priority(expression[i])) {
				printf("%c ", pop());  // 조건 만족하는 동안 계속 pop
			}
			push(expression[i]); //연산자 푸쉬한다
		}
		else printf("Error"); //나머지는 미구현
	}
	//식이 끝난 후 스택에 남은 것들 모두 팝
	while (is_empty(top) == 0) {
		printf("%c ", pop());
	}

	return 0;
}