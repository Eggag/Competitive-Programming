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
int ans = 0;
int sum[100005];

int dfs(int c, int p){
	sum[c] = 1;
	for(auto x : g[c]){
		if(x == p) continue;
		sum[c] += dfs(x, c);
	}
	if(sum[c] % 2 == 0) ans++;
	return sum[c];
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
		g[a].pb(b);
		g[b].pb(a);
	}
	if(n % 2 != 0){
		cout << "-1" << endl;
		return 0;
	}
	dfs(1, 0);
	cout << ans - 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
