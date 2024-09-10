#include<stdio.h>
int tailRecursive(int n, int res){
    if(n==0){
        return res;
    }
    return tailRecursive(n-1, res+n);
    // return n+recursive(n-1)  普通递归
}
int main(){
    printf("%d\n", tailRecursive(3,0));
    return 0;
}

//普通递归在归的时候做运算，尾递归在递的时候做运算，尾递归会被编译器优化，使之空间效率与迭代相当