#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct ArrayStack{
    int size;  //大小
    int* data;  //数组数据 数组第一个元素地址
}ArrayStack;

ArrayStack* createStack(){
    ArrayStack* stack = (ArrayStack* )malloc(sizeof(ArrayStack));
    stack->size = 0;
    stack->data = (int*)malloc(MAX_SIZE*sizeof(int));
    return stack;
}

void deleteStack(ArrayStack* stack){
    free(stack->data);
    free(stack);
}

//获取栈长度
int getSize(ArrayStack* stack){
    return stack->size;
}

//判断栈是否为空
bool isEmpty(ArrayStack* stack){
    return stack->size==0;
}

//入栈
void push(ArrayStack* stack, int value){
    if(stack->size>=MAX_SIZE){
        printf("stack is full!\n");
        return;
    }
    stack->data[stack->size]=value;
    stack->size++;
}
//出栈
int pop(ArrayStack* stack){
    if(stack->size==0){
        printf("stack is empty!\n");
        return -1;
    }
    int top = stack->data[stack->size-1];
    stack->size--;
    return top;
}
//获取栈顶元素
int getTop(ArrayStack* stack){
    if(stack->size==0){
        printf("stack is empty!\n");
        return -1;
    }
    return stack->data[stack->size-1];
}

// 示例
int main(){
    ArrayStack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("size:%d\n",getSize(stack));  //3
    printf("top:%d\n",getTop(stack));  //3
    printf("pop:%d\n",pop(stack)); //3
    printf("top:%d\n",getTop(stack)); //2
    printf("pop:%d\n",pop(stack));  //2
    printf("top:%d\n",getTop(stack)); //1
    printf("pop:%d\n",pop(stack)); //1
    printf("size:%d\n",getSize(stack));  //0
    printf("pop:%d\n",pop(stack)); //-1
    deleteStack(stack); //释放内存
    return 0;
}