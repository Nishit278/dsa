#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &sea){
	int n = sea.size();
	int m = sea[0].size();
	if(i<0 or j<0) return;
	if(i>=n or j>=m) return;

	grid[i][j]+=1;

	dfs(i-1,j,sea);
	dfs(i+1,j,sea);
	dfs(i,j+1,sea);
	dfs(i,j-1,sea);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(grid[i][j] == 1){
    			count++;
    			dfs(i,j,grid);
    		}
    	}
    }

}	


int main(){
}

//leetcode