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

int g[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, d;
	cin >> n >> m >> d;
	int f = -1;
	rep(i, n){
		rep(j, m){
			cin >> g[i][j];
			if(f == -1) f = g[i][j] % d;
			if(g[i][j] % d != f){
				cout << "-1" << endl;
				return 0;
			}
		}	
	}
	int ans = 1e9;
	for(int s = f; s <= 10005; s += d){
		int sum = 0;
		rep(i, n){
			rep(j, m){
				sum += abs(g[i][j] - s) / d;
			}
		}
		ans = min(ans, sum);
	}
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
