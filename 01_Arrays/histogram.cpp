#include <bits/stdc++.h>
using namespace std;

int nsr(vector<int> & heights, int current ){
        int n = heights.size()-1;
        stack <int> st;
        for(int i = heights.size()-1;i>current;i--){
            if(current == n ){
                return 0;
            } else {
                st.push(heights[i]);
            }

        }
        int count = 0;
        while(!st.empty() && st.top() >= heights[current]){
            st.pop();
            count++;
        }
        return count;
    }
    int nsl(vector<int> & heights, int current){
        int n = heights.size()-1;
        stack <int> st;
        for(int i = 0;i<current;i++){
            if(current == 0 ){
                return 0;
            } else {
                st.push(heights[i]);
            }

        }
        int count = 0;
        while(!st.empty() && st.top() >= heights[current]){
            st.pop();
            count++;
        }
        return count;
    }
    
int main(){
    int n;
    cin >> n ;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v[i] = x;
    }
    int l,r;
    int ans=0, area=0;
    for(int i=0;i<n;i++){
        l = nsl(v, i);
        r = nsr(v,i);
        area = (l+r+1) * v[i];
        ans = max(ans, area);
        cout << l << " " << r << " "<< area<<" "<<ans<< endl;
    }
    cout << ans<<endl;
    return 0;

}