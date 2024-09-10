#include<stdio.h>
#include<stdlib.h>

// 指定位置插入数组元素  指定位置之后的所有元素后移（只能从最后开始从后往前移动，否则后面元素会变成完全一样），留出空位以供插入，最后一个数组元素会溢出丢失，因为数组长度固定
void insert(int *nums, int size, int num, int index){
    for(int i = size-1; i > index; i--){
        nums[i] = nums[i-1];
    }
    nums[index] = num;
}

// 指定位置删除元素  指定位置之后的所有元素前移一位（只能从指定位置开始从前往后移动，不能从最后开始移动），最后一个元素不变
void removeNum(int *nums, int size, int index){
    // 错误写法 从后往前把所有元素都变成一样了
    // for(int i = size-1; i > index; i--){
    //     nums[i-1] = nums[i];
    // }
    // 正确写法 从index开始所有元素前移
    for(int i = index; i < size-1; i++){
        nums[i]=nums[i+1];
    }
}

// 查找指定位置元素  找的是符合条件的第一个元素
int search(int *nums, int size, int target){
    for(int i = 0; i < size; i++){
        if(target == nums[i]){
            return i;
        }
    }
    return -1;
}

// 修改指定位置元素
void change(int *nums, int size, int index, int val){
    nums[index]=val;
}

// 扩容数组
int *extend(int *nums, int size, int enlarge){
    int *result = (int *)malloc((size+enlarge)*sizeof(int));
    // 赋值原数组到新数组
    for(int i=0;i<size;i++){
        result[i]=nums[i];
    }
    //新数组剩下的空间初始化为0
    for(int i=size;i<size+enlarge;i++){
        result[i]=0;
    }
    return result;
}

int main(){
    int array[5]={1,2,3,4,1};
    // removeNum(array, 5, 0);
    // for(int i=0;i<5;i++){
    //     printf("%d ", array[i]);
    // }
    printf("%d\n", search(array, 5, 1));
    return 0;
}