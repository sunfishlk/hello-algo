#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 基于链表实现的栈数据结构，所以要有ListNode节点类型
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
// 定义栈数据结构
typedef struct LinkedListStack{
    ListNode* top;  //栈顶指针
    int size;  //栈大小
}LinkedListStack;

// 构造函数
LinkedListStack* createStack(){
    LinkedListStack* stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    stack->size=0;
    stack->top=NULL;
    return stack;
}

// 析构函数
void deleteStack(LinkedListStack* stack){
    while(stack->top){
        ListNode* n = stack->top->next;
        // 释放栈顶指针所指向的空间，栈顶指针不会被删除
        free(stack->top);
        stack->top = n;
    }
    free(stack);
}

// 获取栈长度
int getSize(LinkedListStack* stack){
    return stack->size;
}
// 入栈  栈顶指针会往上移，新元素会变成栈顶
void push(LinkedListStack* stack, int value){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val=value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// 出栈
int pop(LinkedListStack* stack){
    // 出栈时注意栈为空情况
    if(!stack->top){
        return -1;
    }
    int value = stack->top->val;
    ListNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return value;
}

// 返回栈顶元素
int getTop(LinkedListStack* stack){
    if(!stack->top){
        return -1;
    }
    return stack->top->val;
}

// 判断栈是否为空
bool isEmpty(LinkedListStack* stack){
    return stack->size==0;
}

// 输出栈元素
void printStack(LinkedListStack* stack){
    ListNode* current = stack->top;
    while(current){
        printf("%d ",current->val);
        current=current->next;
    }
    printf("\n");
}

int main(){
    LinkedListStack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);
    pop(stack);
    printStack(stack);
    printf("isEmpty: %d\n", isEmpty(stack));
    printf("getTop: %d\n", getTop(stack));
}