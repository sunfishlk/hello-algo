#include<iostream>
#include<unordered_map>
using namespace std;

// hashMap 哈希表 key和value绑定，映射   散列

int main(){
    unordered_map<int, string> map;
    map[123] = "哈喽";
    map[234] = "你好";
    map[345] = "你是谁";
    map[33224324] = "算法";
    map[2204313382] = "hash Map";
    cout<<map[2204313382]<<endl;
    map.erase(2204313382);
    cout<<map[2204313382]<<endl;
}