#include<iostream>
#include<stack>
using namespace std;

// class stack{
//     public:
//     int *arr;
//     int size;
//     int top;

//     stack(int size){
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }

//     void push(int a){
//         if(size-top>1){
//             top++;
//             arr[top] = a;
//         }else{
//             cout<<"stack overflow"<<endl;
//         }
//     }

//     void pop(){
//         if(top>=0){
//             arr[top] = 0;
//             top--;
//         }else{
//             cout<<"empty stack"<<endl;
//         }
//     }

//     bool isempty(){
//         if(top>=0){
//             return false;
//         }else{
//             return true;
//         }
//     }
    
//     int peek(){
//         if(top>=0){
//             return arr[top];
//         }else{
//             return -1;
//         }
//     }
// };

int main(){

    stack<char> st;
    string ch = "hello_world";

    for(int i=0; i<ch.length(); i++){
        st.push(ch[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    cout<< ans<<endl;
    // stack s(5);

    // s.push(2);
    // s.push(3);
    // cout<< s.peek()<<endl;
    // s.pop();
    // cout<< s.peek() <<endl;
    // s.pop();
    // if(s.isempty()){
    //     cout<< "empty" << endl;
    // }else{
    //     cout<< "not empty" <<endl;
    // }
    // s.push(10);
    // cout<<s.peek()<<endl;
    // s.push(11);
    // cout<<s.peek()<<endl;
    // s.push(12);
    // cout<<s.peek()<<endl;
    // s.push(13);
    // cout<<s.peek()<<endl;
    // s.push(14);
    // cout<<s.peek()<<endl;
    // s.push(10);
    // cout<<s.peek()<<endl;


    return 0;
}