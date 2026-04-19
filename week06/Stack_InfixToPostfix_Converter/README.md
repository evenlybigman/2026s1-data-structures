# 중위 표기식 → 후위 표기식 변환기

스택을 이용해 중위 수식을 후위 수식으로 변환하는 C 프로그램입니다.

## 예시

```
입력:  5*(10+2)%2
출력:  5 10 2 + * 2 %
```

---

## 알고리즘 원리

### 표기법 차이

| 표기법 | 설명 | 예시 |
|--------|------|------|
| 중위(Infix) | 연산자가 피연산자 사이 | `5 * (10 + 2)` |
| 후위(Postfix) | 연산자가 피연산자 뒤 | `5 10 2 + *` |

### 변환 규칙

1. **피연산자(숫자)** → 바로 출력
2. **`(`** → 스택에 push
3. **`)`** → `(`가 나올 때까지 pop하여 출력, `(`는 버림
4. **연산자** → 스택 top의 우선순위가 같거나 높으면 pop 후 출력, 그 다음 push
5. **수식 끝** → 스택에 남은 연산자 전부 pop하여 출력

### 연산자 우선순위

| 우선순위 | 연산자 |
|----------|--------|
| 높음 (2) | `*`, `/`, `%` |
| 낮음 (1) | `+`, `-` |
| 최저 (0) | `(` |

> `(`는 스택에 들어간 뒤 일반 연산자에 의해 pop되면 안 되므로 우선순위를 가장 낮게 설정합니다.

---

## 변환 과정 추적 (`5*(10+2)%2`)

| 읽은 문자 | 스택 상태 | 출력 |
|-----------|-----------|------|
| `5` | `[]` | `5` |
| `*` | `[*]` | `5` |
| `(` | `[*, (]` | `5` |
| `10` | `[*, (]` | `5 10` |
| `+` | `[*, (, +]` | `5 10` |
| `2` | `[*, (, +]` | `5 10 2` |
| `)` | `[*]` | `5 10 2 +` |
| `%` | `[%]` | `5 10 2 + *` |
| `2` | `[%]` | `5 10 2 + * 2` |
| 끝 | `[]` | `5 10 2 + * 2 %` |

---

## 코드 구조

```
main()
├── is_op()      - 연산자 여부 확인
├── priority()   - 연산자 우선순위 반환
├── push()       - 스택에 삽입
├── pop()        - 스택에서 제거 및 반환
├── peek()       - 스택 top 확인 (제거 없음)
├── is_full()    - 스택 포화 확인
└── is_empty()   - 스택 공백 확인
```

---

## 전체 코드

```c
#include <stdio.h>
char expression[100] = "5*(10+2)%2";
char stack[100] = "0";
int top = -1;

int is_full(int top) {
    if (top == 99) return 1;
    else return 0;
}

int is_empty(int top) {
    if (top == -1) return 1;
    else return 0;
}

char peek() {
    if (is_empty(top) == 1) { printf("not found"); return 0; }
    else return stack[top];
}

void push(char exp) {
    if (is_full(top) == 1) printf("overflow");
    else {
        ++top;
        stack[top] = exp;
    }
}

char pop() {
    if (is_empty(top) == 1) { printf("underflow"); return 0; }
    else {
        top--;
        return stack[top + 1];
    }
}

int priority(char op) {
    if (op == '*' || op == '%' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else if (op == '(') return 0;
    else return -1;
}

int is_op(char expression) {
    if (expression == '+' || expression == '-' || expression == '*'
        || expression == '%' || expression == '(' || expression == ')')
        return 1;
    else return 0;
}

int main() {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (is_op(expression[i]) == 0) {           // 피연산자
            while (expression[i] != '\0' && is_op(expression[i]) == 0) {
                printf("%c", expression[i]);
                i++;
            }
            printf(" ");
            i--;
        }
        else if (expression[i] == '(') {            // 여는 괄호
            push(expression[i]);
        }
        else if (expression[i] == ')') {            // 닫는 괄호
            while (peek() != '(') {
                printf("%c ", pop());
            }
            pop();
        }
        else if (is_op(expression[i]) == 1) {       // 일반 연산자
            while (is_empty(top) == 0 && priority(peek()) >= priority(expression[i])) {
                printf("%c ", pop());
            }
            push(expression[i]);
        }
    }
    while (is_empty(top) == 0) {                    // 남은 연산자 전부 출력
        printf("%c ", pop());
    }
    return 0;
}
```

---

## 개발 과정 & 어려웠던 점

### 1. 알고리즘 방향을 잘못 잡음
**문제:** 처음에 모든 문자를 스택에 push하려 했음. 숫자(피연산자)까지 스택에 넣는 방향으로 설계했었음.

**해결:** 역할을 명확히 분리
- 피연산자 → 스택 사용 없이 바로 출력
- 연산자 → 스택에 보관했다가 나중에 출력

---

### 2. push / pop 중괄호 누락
**문제:** else 뒤에 중괄호 없이 여러 줄을 작성해서 의도와 다르게 동작함

```c
// 잘못된 코드
void push(char exp) {
    if (is_full(top) == 1) printf("overflow");
    else          // 중괄호 없음
    ++top;
    stack[top] = exp;  // 항상 실행됨
}
```

**해결:** else 블록에 중괄호 추가
```c
void push(char exp) {
    if (is_full(top) == 1) printf("overflow");
    else {
        ++top;
        stack[top] = exp;
    }
}
```

---

### 3. isFull / isEmpty 반환값이 반대였음
**문제:** 가득 찼을 때 0, 비었을 때 1을 반환해서 조건이 반대로 동작함

**해결:** 직관적으로 수정
- 가득 찼으면 `return 1` (true)
- 비어있으면 `return 1` (true)

---

### 4. pop() 반환값 오류
**문제:** `top--` 이후 `stack[top]`을 반환해서 꺼낸 값이 아닌 그 아래 값이 반환됨

```c
// 잘못된 코드
top--;
return stack[top];  // top-- 했으니 꺼낸 값이 아님
```

**해결:** `top+1`로 수정
```c
top--;
return stack[top + 1];  // 꺼낸 값은 top+1
```

---

### 5. `(` 처리 순서 문제
**문제:** `is_op()`이 `(` `)` 도 연산자로 포함해서, `)` 처리 코드가 절대 실행되지 않았음

```c
// 잘못된 코드
if (is_op(expression[i]) == 0)      // 피연산자
else if (is_op(expression[i]) == 1) // ( ) 포함, 여기서 걸림
else if (expression[i] == ')')      // 절대 실행 안 됨
```

**해결:** `(` `)` 를 먼저 체크하도록 순서 변경
```c
if (is_op(expression[i]) == 0)      // 피연산자
else if (expression[i] == '(')      // 먼저 체크
else if (expression[i] == ')')      // 먼저 체크
else if (is_op(expression[i]) == 1) // 일반 연산자
```

---

### 6. `(` 우선순위 설정
**문제:** `(` 우선순위를 높게 설정했더니, 스택에 들어간 `(` 가 일반 연산자에 의해 pop되어버림

**해결:** `(` 우선순위를 0(최저)으로 설정

```c
if (op == '(') return 0;  // 일반 연산자한테 절대 밀리지 않도록
```

---

### 7. `)` 처리 루프가 잘못됨
**문제:** `expression` 배열을 기준으로 루프를 돌아서 스택이 아닌 입력 수식을 검사했음

```c
// 잘못된 코드
for (int j = top; expression[j] != '('; j--) {  // expression을 보면 안 됨
    printf("%c", pop());
}
```

**해결:** 스택 top을 확인하는 `peek()` 사용
```c
while (peek() != '(') {
    printf("%c ", pop());
}
pop();  // ( 제거
```

---

### 8. 두 자리 숫자 처리 안 됨
**문제:** 한 글자씩만 읽어서 `10`이 `1`, `0`으로 분리 출력됨

**해결:** 숫자가 연속되는 동안 while로 계속 읽기

```c
while (expression[i] != '\0' && is_op(expression[i]) == 0) {
    printf("%c", expression[i]);
    i++;
}
printf(" ");
i--;  // for문의 i++을 상쇄
```

---

## 실행 결과

```
5 10 2 + * 2 %
```
