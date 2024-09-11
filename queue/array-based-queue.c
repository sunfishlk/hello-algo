#include<stdio.h>
#include<stdlib.h>

typedef struct ArrayQueue{
    int* nums;
    int front;  //头指针
    int rear;  //尾指针
    int capacity;  //大小
    // 实际有效数据大小为rear-front
}ArrayQueue;

ArrayQueue* createQueue(int capacity){
    ArrayQueue* queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->nums = (int*)malloc(sizeof(int)*capacity);
    return queue;
}

void deleteQueue(ArrayQueue* queue){
    free(queue->nums);
    free(queue);
}

void insertQueue(ArrayQueue* queue, int value){
    queue->nums[queue->rear]=value;
    queue->rear++;
    if(queue->rear >= queue->capacity){
        queue->rear = queue->rear % queue->capacity;
    }
}

int pop(ArrayQueue* queue){
    int temp = queue->nums[queue->front];
    queue->front++;
    // 头尾指针
    if(queue->front >= queue->capacity){
        queue->front = queue->front % queue->capacity;
    }
    return temp;
}
