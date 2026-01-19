#include <bits/stdc++.h>
using namespace std;

int main(){
    set <int> s;
    s.insert(3);
    s.insert(3);
    s.insert(1);
    s.insert(2);
    for(auto i: s){
        cout << i << " ";
    }
    cout << endl;
    set <int> s2 (s.begin(), s.find(3));
    for(auto i: s2 ){
        cout << i << " ";
    }
    cout << endl;
    s.erase(s.begin(), s.find(3));
    for(auto i: s){
        cout << i << " ";
    }
    cout << endl;
    // unordered_set
    unordered_set <int> us;
    us.insert(1);
    us.insert(1);
    us.insert(3);
    us.insert(5);
    us.insert(2);
    us.insert(8);
    us.insert(1);
    us.insert(1);
    for(auto o: us){
        cout << o << " ";
    }
    cout << endl;
    if(us.find(10) == us.end()){
        cout << "not found";
    }
    else {
        cout << 9;
    }
   

}