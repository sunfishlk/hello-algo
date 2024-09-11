#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ArrayQueue{
    int* nums;
    int front;  //头指针
    int rear;  //尾指针
    int capacity;  //大小
    int size;  // 当前队列中的元素数量
}ArrayQueue;

ArrayQueue* createQueue(int capacity){
    ArrayQueue* queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if (!queue) return NULL;
    queue->capacity = capacity;
    queue->front = queue->rear = queue->size = 0;
    queue->nums = (int*)malloc(sizeof(int) * capacity);
    if (!queue->nums) {
        free(queue);
        return NULL;
    }
    return queue;
}

void deleteQueue(ArrayQueue* queue){
    if (queue) {
        free(queue->nums);
        free(queue);
    }
}

bool isFull(ArrayQueue* queue) {
    return queue->size == queue->capacity;
}

bool isEmpty(ArrayQueue* queue) {
    return queue->size == 0;
}

bool insertQueue(ArrayQueue* queue, int value){
    if (isFull(queue)) return false;
    queue->nums[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
    return true;
}

int pop(ArrayQueue* queue){
    if (isEmpty(queue)) return -1; // 或者其他错误值
    int temp = queue->nums[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return temp;
}