#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define MAXSTR 1000

typedef struct line {
  char character;
  int line, posinline;
} Line;

void printLine(void *);

int main(){
  Line *actual, *top;
  Stack *s = Stack_create(MAXSTR);
  FILE *fpointer;
  char stringOutput[MAXSTR];
  int line, posinline, i;
  
  if ((fpointer = fopen("testing.c", "r")) == NULL) {
    printf("Something went wrong.\n");
  }
  else {
    line = 0;
    while((fgets(stringOutput, MAXSTR, fpointer)) != NULL){
      ++line;

      for (i = 0; stringOutput[i] != '\0'; ++i) {
        ++posinline;
        if (stringOutput[i] == '\n') 
          posinline = 0;

        actual = malloc(sizeof(Line));
        actual->character = stringOutput[i];
        actual->line = line;
        actual->posinline = posinline;
        //printf("%c", stringOutput[i]);

        switch (stringOutput[i]){
          case '(':
            Stack_push(s, actual);
          break;
          
          case '{':
            Stack_push(s, actual);
          break;
          
          case '[':
            Stack_push(s, actual);
          break;
          
          case ')':
            top = (Line*) Stack_top(s);
            if (Stack_isEmpty(s)){
              printf("Program:%d:%d: unopened bracket.\n", actual->line, actual->posinline);
              return;
            } else {
              if (top->character == '(')
                Stack_pop(s);
              else {
                printf("Program:%d:%d: unclosed bracket.\n", top->line, top->posinline);
                return;
              }
            }
          break;
          
          case '}':          
            top = (Line*) Stack_top(s);
            if (Stack_isEmpty(s)){
              printf("Program:%d:%d: unopened bracket.\n", actual->line, actual->posinline);
              return;
            } else {
              if (top->character == '{')
                Stack_pop(s);
              else {
                printf("Program:%d:%d: unclosed bracket.\n", top->line, top->posinline);
                return;
              }
            }
          break;

          case ']':
            top = (Line*) Stack_top(s);
            if (Stack_isEmpty(s)){
              printf("Program:%d:%d: unopened bracket.\n", actual->line, actual->posinline);
              return;
            } else {
              if (top->character == '[')
                Stack_pop(s);
              else {
                printf("Program:%d:%d: unclosed bracket.\n", top->line, top->posinline);
                return;
              }
            }
          break;
        
          default:
          break;
        }
      }
    }
    while (!Stack_isEmpty(s)){
      top = (Line*) Stack_pop(s);
      switch (top->character)
      {
      case '(':
        printf("Program:%d:%d: unclosed bracket.\n", actual->line, actual->posinline);
        break;
      case '{':
        printf("Program:%d:%d: unclosed bracket.\n", actual->line, actual->posinline);
        break;
      case '[':
        printf("Program:%d:%d: unclosed bracket.\n", actual->line, actual->posinline);
        break;
      
      default:
        break;
      }
    }
  }
  
  if (Stack_isEmpty(s))
    printf("There is no unbalaced brackets here.\n");

  free(actual);
  free(top);
  Stack_destroy(s);
  fclose(fpointer);
  return 0;
}

void printLine(void *line){
  Line *l = (Line*) line;
  printf("\n%d %c\n", l->line, l->character);
};
