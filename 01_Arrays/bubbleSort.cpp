#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];

//     }
    
//     for(int i=1;i<n;i++){
//         for (int j=0;j<n-i;j++){
//             if(arr[j]>arr[j+1]){
//             int temp = arr[j+1];
//             arr[j+1] = arr[j];
//             arr[j] = temp;
//             }
//         }
       
//     }
//     for(int i=0;i<n;i++){
//         cout << arr[i]<<" ";
//     }
//     cout <<endl;
//     return 0;
// }
void bubbleSort(int *arr, int n){
    for (int i = 1; i < n;i++){
        for (int j = 0; j < n - i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(){
    
    int arr[5] = {5,4,3,9,1};
    int n = sizeof(arr) / sizeof(int);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    bubbleSort(arr, n);
    for (auto x: arr){
        cout << x << ", ";
    }
    cout << endl;
}