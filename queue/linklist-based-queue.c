#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

typedef struct Queue
{
    int size;
    ListNode* front; //队头
    ListNode* rear;  //队尾
}Queue;

// 创建队列
Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 删除队列
void deleteQueue(Queue* queue){
    while(queue->front){
        ListNode* temp = queue->front->next;
        free(queue->front);
        queue->front = temp;
    }
    free(queue);
}

// 获取队列长度
int getSize(Queue* queue){
    return queue->size;
}

// 判断队列是否为空
bool isEmpty(Queue* queue){
    return queue->size==0;
}

// 入队
void insertQueue(Queue* queue, int value){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;
    node->next = NULL;
    //  插入队列时队列为空，则头尾节点都指向新节点
    if(queue->size==0){
        queue->front = node;
        queue->rear = node;
    }
    else{
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// 获取队首元素
int getFront(Queue* queue){
    if(queue->size==0){
        printf("queue is empty!\n");
        return -1;
    }
    return queue->front->val;
}

// 获取队尾元素
int getRear(Queue* queue){
    if(queue->size==0){
        printf("queue is empty!\n");
        return -1;
    }
    return queue->rear->val;
}

// 出队
int pop(Queue* queue){
    if(queue->size==0){
        printf("queue is empty!\n");
        return -1;
    }
    int tempVal = queue->front->val;
    ListNode* temp = queue->front;
    queue->front = queue->front->next;
    if(!queue->front){
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return tempVal;

    // ！错误写法，先释放了queue->front所指向的空间, 此时queue->front=NULL, 则访问不了queue->front->next
    // int tempVal = queue->front->val;
    // free(queue->front);  //free后queue->front是NULL
    // queue->front = queue->front->next;
    // queue->size--;
    // return tempVal;
}

// 打印队列
void printQueue(Queue* queue){
    ListNode* current = queue->front;
    while(current){
        printf("%d\n", current->val);
        current = current->next;
    }
}

//示例
int main(){
    Queue* queue = createQueue();
    insertQueue(queue, 1);
    insertQueue(queue, 2);
    insertQueue(queue, 3);
    insertQueue(queue, 4);
    insertQueue(queue, 5);
    printQueue(queue);
    printf("front: %d\n", getFront(queue));
    printf("rear: %d\n", getRear(queue));
    printf("pop: %d\n", pop(queue));
    printQueue(queue);
    printf("front: %d\n", getFront(queue));
    printf("rear: %d\n", getRear(queue));
    deleteQueue(queue);
    return 0;   
}