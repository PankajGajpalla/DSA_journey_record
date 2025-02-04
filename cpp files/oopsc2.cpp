#include<iostream>
using namespace std;

// class Student{

//     // encapsulation: data hide/ information hide :
//     //  wrapping of data members and funcionts
//     private:
//     string name;
//     int age;
//     int height;

//     public:
//     int getAge(){
//         return age;
//     }
// };

class Human {

    // private:
    public:
    int height;
    public:
    int weight;
    // private:
    int age;

    public: 
    int getAge(){
        return this->age;
    }
    
    void print(){
        cout<< this->height;
    }
    void setWeight(int W){
        this->weight = W;
    }
};

class Male: protected Human {
    
    public:
    string color;
    void setColor(string c){
        this->color = c;
    }
    public:
    void setHeight(int h){
        this-> height = h;
    }
    int getHeight(){
        return this->height;
    }

    // int getHeight(){
    //     return this->height;
    // }
    void sleep(){
        cout<< "Male sleeping" << endl;
    }
};

class A{
    public:
    void func(){
        cout<<"inside class A"<< endl;
    }
};

class B{
    public:
    void func(){
        cout<<"inside class B"<<endl;
    }
};

class C: public A, public B{

};
// operator overloading polymorphism meaning many + forms manyforms  
// two types 
// compile time polymorphism
// runtime polymorphism  (dynamic polymorphism)
class M{
    public:
    int a;
    int b;

    void operator+ (M &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<< value2 - value1 <<endl;
        cout<< "add kardiya" <<endl;
    }
    void operator() (){
        cout<< "yohohoo " << this->a <<endl;
    }
};

int main(){  

    M obj1, obj2;
    
    obj1.a = 4;
    obj2.a = 7;

    obj2 + obj1;
    // obj1();




    // C obj;
    // obj.A::func();
    // obj.B::func();


    // Male m1;
    // // cout << m1.getHeight() << endl;
    // Human h1;
    // m1.setHeight(22);
    // cout<<m1.getHeight()<<endl;
    // h1.print();


    // Student first;
    
    // cout << " sab sahi chal ra hai"<<endl;
    

    /*
    Male object1;
    cout << object1.age <<endl;
    cout << object1.weight <<endl;
    cout << object1.height <<endl;

    object1.setColor("yellow");
    cout << object1.color <<endl;
    object1.setWeight(84);
    cout << object1.weight <<endl;
    object1.sleep(); */



    return 0;
}


// note :

// void operator+(M &obj) {
//     // Use the second operand (obj) to define the operation
//     int value1 = this->a;
//     int value2 = obj.a;
//     cout << value2 - value1 << endl;
//     cout << "add kardiya" << endl;
// }
// Now, obj1 + obj2 works because:

// this represents obj1.
// obj explicitly represents obj2.