#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
struct Node* head = NULL;

void Insert(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head==NULL){
    head = newNode;
  } else {
    struct Node* temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    } 
    temp->next = newNode;
  }
}

void Reverse() { //using iteration
  struct Node *current,*prev,*next;
  current = head;
  prev = NULL;
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

void reverse(struct Node *temp) { //using recursion
  if(temp->next==NULL) {
    head = temp;
    return;
  }
  reverse(temp->next);
  struct Node* q = temp->next;
  q->next = temp;
  temp->next = NULL;
}

void Print() { //using iteration
  struct Node* temp = head;
  while(temp != NULL) {
     printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void print(struct Node* temp) { //using recursion
  if(temp == NULL) {
    printf("\n");
    return;
  }
  printf("%d ",temp->data);
  print(temp->next);
}

int main(void) {
  Insert(1);
  Insert(2);  
  Insert(3);  
  Insert(4);  
  Insert(5);  
  Insert(6);  
  Insert(7);
  Insert(8);      
  Print();
  // Reverse();
  reverse(head);
  print(head);
  return 0;
}