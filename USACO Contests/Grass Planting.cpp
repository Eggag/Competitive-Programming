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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("planting.in", "r", stdin);
        freopen("planting.out", "w", stdout);
	int n;
	cin >> n;
	vi adj[n + 1];
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(b);
	}	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int c = adj[i].size();
		ans = max(ans, c);
	}
	cout << ans + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
