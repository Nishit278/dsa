#include <bits/stdc++.h>
using namespace std;
vector<int> insert(vector<int> &v, int x){
    if(v.empty() || v[v.size()-1] <= x){
        v.push_back(x);
        return v;
    }
    int temp = v[v.size() - 1];
    // cout << "Temp is: " << temp << endl;
    v.pop_back();
    insert(v, x);
    v.push_back(temp);
    return v;
}

vector<int> vecSort(vector<int> &v){
    if(v.size()==1)
        return v;
    int temp = v[v.size() - 1];
    // cout << "last element " << temp << endl;
    v.pop_back();
    vecSort(v);
    insert(v, temp);
    return v;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(auto &i: v){
        cin >> i;
    }
    vecSort(v);
    // cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}