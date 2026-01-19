//Google kickstart round D 2020

//  Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi. A day is record breaking if it satisfies both of the following conditions:

//     The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
//     Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.

// Note that the very first day could be a record breaking day!

// Please help Isyana find out the number of record breaking days.
// Input

// The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Vi.
// Output

// For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of record breaking days.
// Limits

// Time limit: 20 seconds per test set.
// Memory limit: 1GB.
// 1 ≤ T ≤ 100.
// 0 ≤ Vi ≤ 2 × 105.
// Test set 1

// 1 ≤ N ≤ 1000.
// Test set 2

// 1 ≤ N ≤ 2 × 105 for at most 10 test cases.
// For the remaining cases, 1 ≤ N ≤ 1000.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin >> t;
    for(ll x = 1;x<=t;x++){
        ll n;
        cin >> n;
        
        ll arr[n+1];
        arr[n] = -1;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        if(n==1){
            cout << "case #"<<x<<": "<<1<<endl;
            return 0;
        }
        ll ans =0;
        ll m = -1;
      
    
        for(ll i=0;i<n;i++){
            //For the last element
        if(i == n - 1 && arr[i] > m)
        {
                ans++;
                //cout<<arr[i]<<" is a answer "<<endl;
               
        }

        //For first element
        else if(i == 0 && arr[0] > arr[1])
        {
               ans++;
        }

        //Normal Case
        else if(arr[i] > m && arr[i] > arr[i + 1])
        {
                ans++;
                //cout<<arr[i]<<" is a answer "<<endl;
        }
        m = max(arr[i], m);
        }
        
        
        cout<< "case #"<<x<<": "<<ans<<endl;
    }
    return 0;
}