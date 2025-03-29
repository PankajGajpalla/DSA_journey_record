#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;


int main(){

    //creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("pankaj", 1); //1 way
    m.insert(p);

    pair<string, int> p2("Gajpalla", 2); // 2 way
    m.insert(p2);

    m["Luffy"] = 1;
    m["Luffy"] = 3;


    //search
    cout<<m["Luffy"]<<endl;

    cout<<m.at("Gajpalla")<<endl;

    // cout<<m.at("unknown")  error

    //but
    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;


    //size
    cout<<m.size()<<endl;

    // to check presences 
    cout<<m.count("bro")<<endl;  //0 if not present

    cout<<m.count("Luffy")<<endl; //1 if present 

    //to delete
    m.erase("Luffy");
    cout<<m.size()<<endl;


    // to print
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<< it->first << " " << it->second <<endl;
        it++;
    }
    return 0;



}