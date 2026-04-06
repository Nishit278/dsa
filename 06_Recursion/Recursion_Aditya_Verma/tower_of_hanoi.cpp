/***
 *									STORY			
 * There is a temple of Brahamma in south India, where there are 3 pillars
 * with 64 discs, when Bhramma made universe he assigned some priests with a task
 * to take those discs from tower A to tower C, such that, there exists no 
 * situation where a larger disc is above a smaller disc, and you can pick only 
 * one disc at a time.
 * assuming, moving a disc from 1 tower to another takes 1 second, then 
 * completely solving the problem with 64 discs would take 2^64 seconds 
 * which is equal to 584,942,415,017.75744629 years. The timespan of a universe!
 * or duration of 1 breath of Mahavishnu( kishoradakshayi vishnu).
 ***/


#include <bits/stdc++.h>
using namespace std;

void solve(int n, int s, int d, int h){
	if(n==1){
		cout << "Moving disc "<< n << " from " << s << " to " << d << endl;
		return;
	}
	// cout << "Moving disc from " << s << "to " << h << endl;
	solve(n-1, s, h, d);
	cout << "Moving disc "<< n << " from " << s << " to " << d << endl;
	solve(n-1, h, d, s);


}
int main(){
	int n; cin >> n;
	int s=1, h=2, d=3;
	solve(n,s,d,h);
	return 0;
}