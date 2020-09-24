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

vi e[3005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].pb(b);
	}
	int ans = 0;
	for(int j = 0; j < n; j++){
		vi a(n, 0);		
		for(int u : e[j]){
			for(int v : e[u]){
				a[v]++;
			}
		}
		for(int i = 0; i < n; i++){
			if(i == j) continue;
			ans += (a[i] * (a[i] - 1)) / 2;
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
