#include "push.h"

void push(char c) {
  if (top < MAX) store[top++] = c;
}