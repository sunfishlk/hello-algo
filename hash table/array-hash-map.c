// 基于数组实现哈希表
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
// 定义键值对(桶 buckets)
typedef struct Pair{
    int key;
    char* value;
}Pair;

// 定义哈希表
typedef struct hashMap{
    Pair* buckets[MAX_SIZE];  //指向键值对的一组指针
}hashMap;

// 创建哈希表
hashMap* createHashMap(){
    // map是结构体指针，指向哈希表
    hashMap* map = (hashMap*)malloc(sizeof(hashMap));
    for(int i=0;i<MAX_SIZE;i++){
        map->buckets[i]=NULL;
    }
    return map;
}

// 删除哈希表
void deleteHashMap(hashMap* map){
    for(int i=0;i<MAX_SIZE;i++){
        if(map->buckets[i]){
            free(map->buckets[i]->value);
            free(map->buckets[i]);
        }
    }
    free(map);
}

// 插入哈希表
void insertHashMap(hashMap* map, const int key, const char* value){
    Pair* bucket = (Pair*)malloc(sizeof(Pair));
    bucket->key = key;
    // bucket->value = value;  //错误写法，value是char* 类型，字符串，不能直接赋值
    // char* newValue = (char*)malloc(strlen(value) + 1);
    // strcpy(bucket->value, newValue);
    strcpy(bucket->value, value);
    int index = hash(bucket->key);
    map->buckets[index] = bucket;
}

// 删除哈希表元素
void removeHashMapItem(hashMap* map, const int key){
    int index = hash(key);
    if(map->buckets[index]!=NULL){
        free(map->buckets[index]->value);
        free(map->buckets[index]);
        //调用free函数释放指针指向的内存后，该指针本身的值不会自动变为NULL。
        //它仍然会指向原来的地址，但该地址的内容已经被释放，成为悬空指针（dangling pointer）。
        //为了避免悬空指针的问题，通常会在free之后将指针显式设置为NULL。
        //理论上这样最安全，free之前检查，free之后置空，但实际上有时可以不写这么复杂
        map->buckets[index]=NULL;
    }
}

// 某种hash算法函数
int hash(int key){
    return key;
}