#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* prev;
    struct ListNode* next;
}ListNode;

ListNode* createListNode(int value){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;
    node->prev = NULL;
    node->next = NULL;
}

// p节点之后插入q节点
void insertNode(ListNode* p, ListNode* q){
    if(!q){
        return;
    }
    p->next = q;
    q->prev = p;
}

