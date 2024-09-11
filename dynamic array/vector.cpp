#include<iostream>
#include<vector>  // 包含vector的头文件
#include<algorithm> // 包含sort的头文件
using namespace std;

void print(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums={1,2,3,4,5};
    //输出
    print(nums);
    //追加
    nums.push_back(6);
    nums.push_back(7);
    print(nums);
    // 在索引位置前插入元素
    nums.insert(nums.begin()+2, 10);
    print(nums);
    // 删除索引位置的元素
    nums.erase(nums.begin()+2);
    print(nums);
    // pop弹出最后一个元素
    nums.pop_back();
    print(nums);
    // 拼接两个列表
    vector<int> nums2={8,9};
    nums.insert(nums.end(), nums2.begin(), nums2.end());
    print(nums);
    cout<<"size: "<<nums.size()<<endl;
    cout<<"nums.begin: "<<*nums.begin()<<endl;
    cout<<"nums.end: "<<*(nums.end()-1)<<endl;
    // nums.begin()和nums.end()是迭代器，不能直接返回值，返回的是迭代器的地址
    // 排序 从小到大
    vector<int> newNums = {3, 2, 1, 4, 5};
    sort(newNums.begin(), newNums.end());
    print(newNums);
}