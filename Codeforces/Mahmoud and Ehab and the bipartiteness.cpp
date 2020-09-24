#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

vi g[100005];
ll cnt[2];

void dfs(int c, int p, int color){
	cnt[color]++;
	for(int u : g[c]){
		if(u == p) continue;
		dfs(u, c, !color);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		g[b].pb(a);
		g[a].pb(b);
	}
	dfs(1, 0, 0);
	ll ans = (cnt[0] * cnt[1]) - (n - 1);
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
