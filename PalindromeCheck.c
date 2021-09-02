#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char pop(char* stack, int* top);
int push(char* stack, int* top, char ToPush, int size);
int check_palindrome(char* stack, int top, char* word);
int main(void) {
  int top = -1, status;
  char* stack, word[20];
  printf("\n\t\tEnter word to check: ");
  scanf("%s", word);
  stack = (char*)calloc(strlen(word), sizeof(char));
  status = check_palindrome(stack, top, word);
  if(status == 1)
    printf("\n\t%s is a palindrome word!\n", word);
  else
    printf("\n\t%s is not a palindrome word!\n", word);
  return 0;
}
char pop(char* stack, int* top) {
  if(*top==-1)
    return ('-');
  else
    return stack[(*top)--];
}
int push(char* stack, int* top, char ToPush, int size) {
  if(*top == size - 1)
    return 0;
  else {
    stack[++(*top)] = ToPush;
    return 1;
  }
}
int check_palindrome(char* stack, int top, char* word) {
  int i = 0, flag = 1;
  char popped;
  while(push(stack, &top, word[i], strlen(word))) {
    i++;
  }
  i = 0;
  while(flag) {
    popped = pop(stack, &top);
    if(popped == '-')
      break;
    else if(popped != word[i]) {
      flag = 0;
      break;
    }
    i++;
  }
  if(flag)
    return 1;
  else
    return 0;
}
