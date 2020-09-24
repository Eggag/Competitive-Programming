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

vector<pi> g[55];
int r[55];
vi k[55];
int l[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);
	int n, m, d, s;
	cin >> n >> m >> d >> s;
	rep(i, d){
		int a, b, c;
		cin >> a >> b >> c;
		l[a][b]++;
		if(l[a][b] < 2){
			g[a].pb(mp(b, c));
			k[b].pb(a);
		}
	}
	rep(i, s){
		int a, b;
		cin >> a >> b;
		rep(i, g[a].size()){
			if(g[a][i].se < b) r[g[a][i].fi]++;
		}
	}
	vi type;
	rep(i, 55){
		if(r[i] == s){
			type.pb(i);
		}
	}
	int ans = 0;
	rep(i, type.size()){
		ans = max(ans, (int) k[type[i]].size());
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
