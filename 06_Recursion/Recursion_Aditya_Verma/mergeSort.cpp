#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];


void merge(int l, int r, int mid){
	int lsz = mid-l+1;
	int L[lsz + 1];
	int rsz = r-mid;
	int R[rsz + 1];
	for(int i=0;i<lsz;++i){
		L[i] = a[i+l];
	}
	for(int i=0;i<rsz;++i){
		R[i] = a[i+mid+1];
	}
	L[lsz] = R[rsz] = INT_MAX;

	int li=0;
	int ri=0;

	for(int i=l;i<=r;++i){
		if(L[li]<=R[ri]){
			a[i] = L[li];
			li++;
		} else{
			a[i] = R[ri];
			ri++;
		}
	}
}

void mergeSort(int l, int r){
	if(l==r) return;

	int mid = (l+r)/2;
	mergeSort( l,  mid);
	mergeSort( mid+1,  r);
	merge(l, r, mid);
}

int main(){
	int n; cin >> n;
	// int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	mergeSort(0, n-1);
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;

}