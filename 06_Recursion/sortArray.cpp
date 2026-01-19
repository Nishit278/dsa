#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &v, int x){
    if(v.empty() || v[v.size()-1] <= x){
        v.push_back(x);
        return ;
    }
    int temp = v[v.size() - 1];
    cout << "Temp is: " << temp << endl;
    v.pop_back();
    insert(v, x);
    v.push_back(temp);
}

void vecSort(vector<int> &v){
    if(v.size()==1)
        return;
    int temp = v[v.size() - 1];
    cout << "last element " << temp << endl;
    v.pop_back();
    vecSort(v);
    insert(v, temp);
}
int main(){
    // int n;
    // cin >> n;
    int n = 6;
    // vector<int> v(n, 0);
    vector<int> v = {5,3,4,2,1,6};
    // for(auto &i: v){
    //     cin >> i;
    // }

    vecSort(v);
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
}