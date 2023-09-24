typedef struct stack {
    int top;
    int stack[10000];
} MinStack;

MinStack* minStackCreate() {
    MinStack *new = (MinStack*)malloc(sizeof(MinStack));
    new->top = -1;
    return new;
}

void minStackPush(MinStack* obj, int val) {
  obj->stack[++(obj->top)] = val;
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    else
    {
        (obj->top)--;
    }
}

int minStackTop(MinStack* obj) {
  return obj->stack[obj->top];
}


int minStackGetMin(MinStack* obj) {
  if (obj->top == -1) return NULL;
  else
  { 
      int min = obj->stack[0];
      for (int i = 1; i <= obj->top; i++){
          if (obj->stack[i] < min) min = obj->stack[i];
      }
      return min;
  }
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/