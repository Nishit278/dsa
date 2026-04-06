#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int h){
    int i = l;
    int j = mid + 1;
    // int k = l;
    vector<int> c;
    while (i <= mid && j <= h)
    {
        if(v[i]<v[j]){
            c.push_back(v[i++]);
        }
        else
        {
            c.push_back(v[j++]);
        }
    }
        while(i<=mid){
            c.push_back(v[i++]);
            
        }
        while(j<=h){
            c.push_back(v[j++]);
            
        }
   
        
    for (int i = l; i <= h;i++){
        v[i] = c[i-l];
    }
}
void mergeSort(vector<int>&v, int l, int h){
    if(l<h){
        int mid = (l + h) / 2;
        cout << "left" << endl;
        mergeSort(v, l, mid);
        cout << "right" << endl;
        mergeSort(v, mid + 1, h);
        cout << "Merge" << endl;
        merge(v, l, mid, h);
        // cout << l << " " << h << endl;
    }
}

int main(){
    vector<int> v = {4, 3, 1, 2, 6, 7};
    int l = 0, h = v.size() - 1;
    mergeSort(v, l, h);
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
}