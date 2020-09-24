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
#define endl '\n'
const int MOD = (1e9 + 7);

vi g[100005];
int v[100005];
ll sz;

void dfs(int e){
	sz++;
	v[e] = 1;
	for(int u : g[e]){
		if(!v[u]){
			dfs(u);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(c == 0){
			g[a - 1].pb(b - 1);
			g[b - 1].pb(a - 1);
		}
	}
	ll ans = 1;
	for(int i = 0; i < k; i++){
		ans = (ans * n) % MOD;
	}
	for(int i = 0; i < n; i++){
		if(!v[i]){
			sz = 0;
			dfs(i);
			ll s = 1;
			for(int j = 0; j < k; j++){
				s = s * sz % MOD;
			}
			ans = (ans - s + MOD) % MOD;
		}
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
