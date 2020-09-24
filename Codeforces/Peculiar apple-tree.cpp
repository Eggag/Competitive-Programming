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
int cnt[100005];
int depth = 0;

void dfs(int c, int d){
	depth = max(depth, d);
	cnt[d]++;
	for(int u : g[c]){
		dfs(u, d + 1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	dfs(1, 1);
	int ans = 0;
	for(int i = 1; i <= depth; i++) ans += cnt[i] % 2;
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
