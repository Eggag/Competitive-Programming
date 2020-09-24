#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "race.h"
//#include "grader.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vector<pi> g[200005];
int vis[200005];
int ans = 1e9;

void dfs(int cur, int sum, int cnt){
	vis[cur] = 1;
	if(sum > k) return;
	if(sum == k){
		ans = min(ans, cnt);
	}
	for(pi u : g[cur]) if(!vis[u.fi]){
		dfs(u.fi, sum + u.se, cnt + 1);
	}
}

int best_path(int N, int K, int h[][2], int l[]){
	k = K;
	n = N;
	rep(i, n - 1){
		g[h[i][0]].pb({h[i][1], l[i]});
		g[h[i][1]].pb({h[i][0], l[i]});
	}
	rep(i, n){
		memset(vis, 0, sizeof(vis));
		dfs(i, 0, 0);
	}
	return (ans == 1e9 ? -1 : ans);
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
