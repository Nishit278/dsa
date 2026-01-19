#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> temp;
void solve(int count, vector<int> v)
{
   if(v.size()==count){
       ans.push_back(v);
       return;
   }
   for (int i = count; i < v.size();i++){
    //    temp.push_back(v[i]);
    swap(v[i], v[count]);
    cout << count+1 << " " << i+1 << endl;
    solve(count + 1, v);
    swap(v[i], v[count]);
    // temp.pop_back();
   }
   return;
}
int main(){
    vector<int> v{1, 2, 3};
    
    solve(0, v);
    cout << "[";
    for (auto i : ans)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}