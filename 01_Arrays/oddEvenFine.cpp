#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    vector <string> s {"amazon","facebook", "amazon", "google", "facebook", "facebook"};
    map <string, int> mp;
    vector <int> v(4);
    for(auto i: s){
        mp[i]++;
    }
    
    for(auto i: mp){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;



}