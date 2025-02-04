#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(11);
    cout<< "front of q is "<<q.front() <<endl;

    q.push(15);
    cout<<"front of q is "<<q.front()<<endl;

    q.push(16);
    cout<<"front of q is "<<q.front()<<endl;

    cout<<"size of q is "<<q.size()<<endl;

    q.pop();
    cout<<"front of q is "<<q.front()<<endl;
    q.pop();
    cout<<"front of q is "<<q.front()<<endl;
    q.pop();
    // cout<<"front of q is "<<q.front()<<endl;
    
    cout<<"size of q is "<<q.size()<<endl;

    if(q.empty()){
        cout<<"queue is empty "<<endl;
    }else{
        cout<<"queue is not empty"<<endl;
    }

}
