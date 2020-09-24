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

int a[105];
vi g[105];

void dfs(int cur){
	a[cur] = 1;
	for(int v : g[cur]){
		dfs(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		g[b].pb(a);
	}
	for(int i = 1; i <= n; i++){
		memset(a, 0, sizeof(a));
		int c = 0;
		dfs(i);
		for(int i = 0; i <= n; i++){
			if(a[i]) c++;
		}
		if(c == n){
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
