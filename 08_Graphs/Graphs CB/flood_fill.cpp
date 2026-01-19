#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};
int c, r;
const int N = 1e3+7;
int g[N][N];

void floodFill(int i, int j, int ch, int color){
	if(i<0 or j<0 or i>=r or j>=c)
		return;
	if(g[i][j]!=ch){
		return;
	}
	g[i][j] = color;
	for(int k=0;k<4;k++){
		floodFill(i+dx[k],j+dy[k],ch, color);
	}

}

int main(){
	cin >> r >> c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int x;
			cin >> x;
			g[i][j] = x;
		}
	}
	int sr, sc;
	cin >> sr >> sc;
	int color; cin >> color;
	int ch = g[sr][sc];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}

	floodFill(sr,sc,ch,color);
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}