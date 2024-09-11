#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    int front = queue.front();
    cout<<"front: "<<front<<endl;
    bool empty = queue.empty();
    cout<<"isEmpty: "<<empty<<endl;
    queue.pop();
    int size = queue.size();
    cout<<"size: "<<size<<endl;
}