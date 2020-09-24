#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, m;
	cin >> n >> m;
	vi x(m), y(m), z(m);
	int dist[n + 1][n + 1];
	rep(i, n + 1) rep(j, n + 1) dist[i][j] = 1e9;
	rep(i, n + 1) dist[i][i] = 0;
	rep(i, m){
		cin >> x[i] >> y[i] >> z[i];
		x[i]--, y[i]--;
		dist[x[i]][y[i]] = z[i];
		dist[y[i]][x[i]] = z[i];
	}
	rep(k, n) rep(i, n) rep(j, n){
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
	rep(i, m){
		if(dist[x[i]][y[i]] != z[i]){
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << m << endl;
	rep(i, m){
		cout << x[i] + 1 << " " << y[i] + 1 << " " << z[i] << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	rep(i, t){
		cout << "Case #" << i + 1 << ": ";
		solve();
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
