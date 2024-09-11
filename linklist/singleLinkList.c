#include<stdio.h>
#include<stdlib.h>

// 值和指向下一个节点的指针
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

// 创建链表节点
ListNode* newListNode(int value){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next=NULL;
    node->val=value;
    return node;
}

// 插入节点 在p节点后插入节点q
void insertNode(ListNode* p, ListNode* q){
    q->next = p->next;
    p->next = q;
}
// 删除节点 删除p节点后的节点
void deleteNode(ListNode* p){
    // 如果p节点后没有节点则返回
    if(!p->next){
        return;
    }
    ListNode* q = p->next; //前面做检查，防止p->next==NULL
    p->next=q->next;  //写成p->next = p->next->next也可以，但是free的时候不好free，所以定义临时变量q来用于释放内存
    free(q);
}
// 访问节点 根据索引查找节点 只能从前往后遍历，数组则是O(1)，链表是O(n)，访问元素效率低
ListNode* accessNode(ListNode* head, int index){
    for(int i=0;i<index;i++){
        head = head->next;
    }
    return head;
}

// 查找节点 输出第一个target的链表索引
int searchNode(ListNode* head, int target){
    int index = 0;
    // 不知道链表多长，所以用while
    while(head){
        if(target==head->val){
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}


// int* nums和int *nums没有区别，写法风格问题
int main(){
    int total = 10;
    ListNode* head = newListNode(1);
    ListNode* tail = head;
    for(int i=2;i<=total;i++){
        tail->next = newListNode(i);
        tail=tail->next;
    }
    // 不使用head来遍历，因为遍历之后head会指向末尾，不好回正，所以用临时变量current来变量
    ListNode* current = head;
    while(current){
        printf("%d\n", current->val);
        current=current->next;
    }
    // ListNode *p1 = newListNode(1);
    // ListNode *p2 = newListNode(2);
    // ListNode *p3 = newListNode(3);
    // p1->next = p2;
    // p2->next = p3;
    // while(p1){
    //     printf("%d\n",p1->val);
    //     // p1++;  不能写p1++，因为链表在内存中是不连续的，p1++访问不了正确的位置，如果是结构体数组或者单纯的数组可以这么写
    //     p1=p1->next;
    // }
    return 0;
}