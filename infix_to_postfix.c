#include <stdio.h>
#include <string.h>

// custom stack code =======================>
#define MAX 20
char stack[MAX];
int tos = -1;

int isEmpty() {
  return tos < 0;
}

int isFull() {
  return tos >= MAX - 1;
}

// invoke func peek()
// only if the stack is not empty
char peek() {
  if (isEmpty()) {
    printf("Can't perform 'peek' operation as stack is empty!\n");
    return -1;
  }
  return stack[tos];
}

void push(char ch) {
  if (isFull()) {
    printf("Can't perform 'push' operation as stack is full!\n");
    return;
  }
  stack[++tos] = ch;
}

char pop() {
  if (isEmpty()) {
    printf("Can't perform 'pop' operation as stack is empty!\n");
    return -1;
  }
  return stack[tos--];
}

// ======================================>

int isInfixExpChOfHigherOrEqualPrecedence(char ch) {
  char operators[] = {'/', '*', '+', '-'};
  int precedences[] = {6, 5, 4, 4}; // precedence values
  int len = strlen(operators);

  char tosCh = peek();
  int chPrec = -1;
  int tosChPrec = -1;

  for (int i = 0; i < len; i++) {
    if (operators[i] == ch) {
      chPrec = precedences[i];
    }
    if (operators[i] == tosCh) {
      tosChPrec = precedences[i];
    }
    if (chPrec != -1 && tosChPrec != -1) break;
  }

  return chPrec >= tosChPrec;
}

int main() {
  char infixExp[MAX];
  char postfixExp[MAX] = {0}; // Initialize with 0 to avoid garbage values
  int pIdx = 0;

  printf("Enter infix expression: ");
  scanf(" %s", infixExp);
  int infixExpnLen = strlen(infixExp);
  char ch;

  for (int i = 0; i < infixExpnLen; i++) {
    ch = infixExp[i];
    if (ch >= 'a' && ch <= 'z') {
      // Operand
      postfixExp[pIdx++] = ch;
    } else {
      // Operator
      switch (ch) {
        case '(':
          push(ch);
          break;
        case ')':
          while (peek() != '(') {
            postfixExp[pIdx++] = pop();
          }
          pop(); // Remove '(' from stack
          break;
        default:
          // /, *, +, -
          while (!isEmpty() && peek() != '(' && !isInfixExpChOfHigherOrEqualPrecedence(ch)) {
            postfixExp[pIdx++] = pop();
          }
          push(ch);
      }
    }
  }

  // Append remaining operators in the stack to postfix expression
  while (!isEmpty()) {
    postfixExp[pIdx++] = pop();
  }

  postfixExp[pIdx] = '\0'; // Null char to terminate the postfix expression

  printf("Postfix expression: %s\n", postfixExp);

  return 0;
}