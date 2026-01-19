#include <bits/stdc++.h>
#include <vector>
#include <map>
#define ll long long int 
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
    ll t;
    cin >>t;
    while(t--){
        ll n ;
        cin >> n;
        ll arr[n];
        FOR(i,n){
            cin>>arr[i];
        }
        vector <ll> vec;
        stack <ll> st;
        FOR(i,n){
            if(st.empty()){
                vec.push_back(-1);
            }
            else if (!st.empty() && st.top()>arr[i]){
                vec.push_back(st.top());
            }
            else if (!st.empty() && st.top() <=arr[i]) {
                while(!st.empty() && st.top() <=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    vec.push_back(-1);

                } else {
                    vec.push_back(st.top());
                }

            }
            st.push(arr[i]);
        }
        FOR(i,n){
            cout << vec[i]<<" ";
        }
        cout << endl;

    }
    return 0;
}