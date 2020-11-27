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
  int n,num;
  printf("Enter no. of term: \n");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Enter your Number: \n");
    scanf("%d",&num);
    Insert(num);
    Print();
    print(head);
  }
  Reverse();
  Print();
  return 0;
}