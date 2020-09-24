#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int vis[105][105];
int done[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, sx, sy;
	cin >> n >> m >> sx >> sy;
	vis[sx][sy] = 1;
	pi cur = {sx, sy};
	cout << sx << " " << sy << endl;
	int lst = -1;
	rep(i, n){
		int nm = 1;
		rep(j, m + 1){
			if(nm <= m && !vis[cur.fi][nm]){
				vis[cur.fi][nm] = 1;
				cout << cur.fi << " " << nm << endl;
				lst = nm;
			}
			else{
				if(nm >= m){
					//we change cur
					done[cur.fi] = 1;
					repn(k, 1, n + 1) if(!done[k]){
						cur.fi = k;
						break;
					}
					if(!vis[cur.fi][lst]) cout << cur.fi << " " << lst << endl;
					vis[cur.fi][lst] = 1;
					break;
				}
			}
			nm++;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
