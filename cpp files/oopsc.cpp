#include<iostream>
#include<cstring>
using namespace std;

class Hero {

    private: 
    int health;
    
    public:
    char *name;
    char level;
    // char name;
    
    //static member
    static int timeToComplete;
    // syntax  datatype classname :: fildName = value;

    // when you create a constructor the default constructed die 
    Hero() {
        cout<< "simple constructor called"<<endl;
        name = new char[100];
    }

    // parameterised constructor 
    Hero(int health) {
        cout<<"this ->" << this <<endl; 
        //this is a pointer u can check by printing the address of this and the address of ramesh
        this -> health = health;
    }

    Hero(int health, char level){
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp){ // dont do pass by value like "Hero temp " do pass by refrence "Hero &temp" because ohterwise it will stuck in a infinite loop calling the copy function again and again
        cout<< "copy constructor called" <<endl;
        char *ch = new char[strlen(temp.name)+1]; //for deepl copy
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health; //temp statically hai isiliye dot.
        this->level = temp.level;
    }
    void print(){
        cout<< "Name: "<< this->name<<endl;
        cout<<"level: "<<this->level<<endl;
        cout<<"health: "<<this->health<<endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }
    
    // void setLevel(char ch, char name){
    //     if(name == 'B'){
    //         level = ch;
    //     }else{
    //         cout<<"invalid user change" <<endl;
    //     }
    // }

    static int random(){
        return timeToComplete; 
    }

    // destructor 
    ~Hero() {
        cout << "Destructor bhai called" << endl;
    }

};

int Hero::timeToComplete = 5;

int main(){

    // cout << Hero::timeToComplete<<endl;
    cout<< Hero::random()<<endl;



    // Hero a; //for statically allocated destruction call automatically
    
    // Hero *b = new Hero();
    // // for dynamically distructor is called manually
    // delete b;





/*
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Pankaj";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor
    Hero hero2(hero1);
    // Hero hero2 = hero1;

    hero2.print();

    hero1.name[0] = 'B';
    hero1.print();

    hero2.print();// changes also done in hero2 on changing hero1 
    // this is called shallow copy that default constructor do
    //same memory ko alag alag name se copy kar rahe hai 

    // lets see deep copy 
*/





/*
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Pankaj";
    hero1.setName(name);

    hero1.print();

*/







/*
Hero s(70, 'C');
s.print();

//copy consturctor inbuilt or can also make
Hero R(s);
R.print();

*/





/*
//object created statically
cout<<"hi"<<endl;
Hero ramesh;
cout<<"hello"<<endl;

//dynamically 
Hero *h = new Hero;
// Hero *h = new Hero();  both are same 
*/

/*
// statically
Hero ramesh( 70);
// cout<<&ramesh<<endl;
ramesh.print();

//dynamically
Hero *h = new Hero(11);
h->print();

Hero raelilblack(80, 'R');
raelilblack.print();
*/






/*
    // static allocation 
    Hero a;
    a.level = 'C';
    a.setHealth(80);
    cout<< "level : " << a.level <<endl;
    cout<< "health: " << a.getHealth() <<endl;

    // dynamic allocation
    Hero *b = new Hero;
    b->setLevel('A');
    b->setHealth(70);
    cout<< "level: " << (*b).level <<endl;
    cout<< "health: " << (*b).getHealth() <<endl;

    // alternate implementation
    cout<< "level: " << b->level <<endl;
    cout<< "health: " << b->getHealth() <<endl;
*/
     
    // Hero ramesh;

    // cout<<"health: "<< ramesh.getHealth() <<endl;
    // ramesh.setHealth(90);
    // cout<<"health: "<< ramesh.getHealth() <<endl;
        
    // ramesh.setLevel('A', 'B');
    // // cout<<"health: "<<ramesh.health<<endl;
    // cout<<"level: "<< ramesh.getLevel() << endl;
    // cout<<"size: "<< sizeof(ramesh) <<endl;
    return 0;
}