#include <bits/stdc++.h>
using namespace std;
#define pb push_back

// void solve(vector<int> candidates, vector<vector<int>>&ans, vector<int> temp, int target, int index){
//         if(index==candidates.size()){
//             if(target == 0){
//                 ans.push_back(temp);
//             }
//             return;
//         }
        
        
//         if(candidates[index]<=target){
//             temp.pb(candidates[index]);
//             solve(candidates, ans, temp, target-candidates[index], index);
//             temp.pop_back();
//         }
//         solve(candidates, ans, temp, target, index+1);
        
//     }
void solve(vector<int> candidates, vector<vector<int>>&ans, vector<int> temp, int target, int index){
        if(index == candidates.size()){
            if(target == 0){
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[index]<=target){
          
                temp.push_back(candidates[index]);
                solve(candidates, ans, temp, target-candidates[index], index+1);
                temp.pop_back();
            
        }
        solve(candidates, ans, temp, target, index+1);
    }
int main(){
    vector<int> candidates = {1,1,2,5,6,7,10};
    int target = 8;
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, ans, temp, target, 0);
    return 0;
}