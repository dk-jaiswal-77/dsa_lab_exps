#include <stdio.h>
#include <string.h>

#define MAX 20

// custom stack code =======================>
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


int main() {
  char exp[MAX];
  printf("Enter expression: ");
  scanf(" %s", exp);
  int len = strlen(exp);
  char ch;
  for (int i = 0; i < len; i++) {
    ch = exp[i];
    if (ch == '(') {
      push(ch);
    } else {
      if (isEmpty()) {
        printf("Invalid!");
        return 0;
      }
      pop();
    }
  }

  if (!isEmpty()) {
    printf("Invalid!");
  } else {
    printf("Valid!");
  }

  return 0;
}