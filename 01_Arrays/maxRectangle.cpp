#include <bits/stdc++.h>
using namespace std;

int main(){
    vector < vector < char >> matrix {{'1','0','1','1','1'},{'0','1','0','1','0'},{'1','1','0','1','1'},{'1','1','0','1','1'},{'0','1','1','1','1'}};
    int n = matrix.size();
        int m = matrix[0].size();
        vector <int> v(m,0);
        stack <int> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0){
                    if(matrix[i][j]-'0'== 0){
                        v[j] = 0;
                    } else {
                        v[j]+=matrix[i][j]-'0';
                    }
                } else {
                        v[j]+=matrix[i][j]-'0';
                }
            }
        }
        for(auto i: v){
            cout << i << ' ';
        }
        int area =0, ans = 0, ht, wd;
        for(int i=0;i<=m;i++){
            while(!st.empty() && (i == m || v[st.top()] >= v[i])){
                ht = v[st.top()];
                st.pop();
                wd = st.empty()?i:(i-st.top()-1);
                area = ht*wd;
                ans = max(ans, area);
            }
            st.push(i);
        }
        cout << ans << endl;
}