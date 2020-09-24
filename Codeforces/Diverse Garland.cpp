#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int cost[200005][3];
int from[200005][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	string s;
	cin >> n >> s;
	int a[n];
	rep(i, n){
		if(s[i] == 'B') a[i] = 0;
		if(s[i] == 'G') a[i] = 1;
		if(s[i] == 'R') a[i] = 2;
	}
	rep(i, n) cost[i][0] = cost[i][1] = cost[i][2] = 1e9;
	cost[0][0] = (a[0] != 0);
	cost[0][1] = (a[0] != 1);
	cost[0][2] = (a[0] != 2);
	repn(i, 1, n){
		rep(x, 3) rep(y, 3) if(x != y){
			if(cost[i][y] > cost[i - 1][x] + (a[i] != y)){
				cost[i][y] = cost[i - 1][x] + (a[i] != y);
				from[i][y] = x;
			}
		}
	}
	int x = 0;
	if(cost[n - 1][1] < cost[n - 1][0]) x = 1;
	if(cost[n - 1][2] < cost[n - 1][x]) x = 2;
	cout << cost[n - 1][x] << endl;
	string ans;
	for(int i = n - 1; i >= 0; i--){
		ans += ("BGR"[x]);
		x = from[i][x];
	}
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
