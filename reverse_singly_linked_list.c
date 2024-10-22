#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head;
struct Node* newNode;
struct Node* temp;

void add(int data) {
  newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;
  
  // if SLL is empty
  if (head == NULL) {
    head = newNode;
    return;
  }
  // if SLL is not empty,
  // traverse till last node of the SLL
  for (temp = head; temp -> next != NULL; temp = temp -> next);
  // temp points to last node of the SLL
  // & append new node to it
  temp -> next = newNode;
}

void displaySLL() {
  for (temp = head; temp != NULL; temp = temp -> next) {
    printf("%d -> ", temp -> data);
  }
  printf("NULL\n");
}

void reverseSLL() {
  // null
  // 1 -> null
  // 1 -> 2 -> null
  if (head == NULL || head -> next == NULL) return;
  struct Node *prev = NULL, *curr = head, *next = head -> next;
  while(curr != NULL) {
    curr -> next = prev;
    prev = curr;
    curr = next;
    if (next != NULL) next = next -> next;
  }
  head = prev;
}

int main() {
  // create a SLL
  int count;
  int data;
  printf("\nEnter nodes count for SLL: ");
  scanf(" %d", &count);
  printf("\nEnter nodes values: ");
  for (int i = 0; i < count; i++) {
    scanf(" %d", &data);
    add(data);
  }

  printf("\nSLL is: \n");
  displaySLL();

  reverseSLL();
  printf("\nReversed SLL is: \n");
  displaySLL();
  
  return 0;
}