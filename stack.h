#define MAX_SIZE 1000


typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;



void initStack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);