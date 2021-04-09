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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[((19 * 19) / 2) + 5][mxN];
int ind[19][19];
int vis[19], act[19];
int a[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	int cnt = 0;
	rep(j, 19) repn(k, j + 1, 19) ind[j][k] = cnt++;
	rep(i, n){
		cin >> a[i];
		rep(j, 19) repn(k, j + 1, 19) if(((a[i] >> j) & 1) && ((a[i] >> k) & 1)) g[ind[j][k]][i] = i + 1;
	}
	rep(j, 19) repn(k, j + 1, 19){
		g[ind[j][k]][mxN - 1] = 1e9;
		for(int i = mxN - 2; i >= 0; i--) if(!g[ind[j][k]][i]) g[ind[j][k]][i] = g[ind[j][k]][i + 1];
	}
	rep(i, q){
		int x, y;
		cin >> x >> y;
		x--, y--;
		int f = 0, nw = 0;
		rep(j, 19) vis[j] = 1e9, act[j] = 0;
		rep(j, 19) if(((a[x] >> j) & 1) && ((a[y] >> j) & 1)){
			cout << "Shi\n";
			goto en;
		}
		rep(j, 19) if((a[x] >> j) & 1){
			nw++;
			act[j] = 1;
			vis[j] = x;
		}
		while(nw){
			int mn = 1e9, bst = -1;
			rep(j, 19) if(act[j] && vis[j] < mn) mn = vis[j], bst = j;
			act[bst] = 0;
			rep(j, 19) if(vis[j] >= mn && j != bst){
				int b = j, c = bst;
				if(b > c) swap(b, c);
				int pos = g[ind[b][c]][mn] - 1;
				if(pos >= vis[j] || pos >= 1e8) continue;
				vis[j] = pos;
				act[j] = 1;
				if(((a[y] >> j) & 1) && pos <= y){
					cout << "Shi\n";
					goto en;
				}
			}
			nw = 0;
			rep(j, 19) if(act[j]) nw++;
		}
		rep(j, 19) if(((a[y] >> j) & 1) && vis[j] <= y) f = 1;
		cout << (f ? "Shi" : "Fou") << '\n';
		en:;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
