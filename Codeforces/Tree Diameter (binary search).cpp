#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int query(vi a, vi b){
	cout << a.size() << " " << b.size();
	for(int c : a) cout << " " << c;
	for(int c : b) cout << " " << c;
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void solve(){
	int n;
	cin >> n;
	vi stuff;
	repn(i, 2, n + 1) stuff.pb(i);
	int maxd = query({1}, stuff);
	while(stuff.size() != 1){
		vi x, y;
		int dist = stuff.size() / 2;
		rep(i, dist) x.pb(stuff[i]);
		repn(i, dist, stuff.size()) y.pb(stuff[i]);
		stuff.clear();
		if(query({1}, x) == maxd){
			for(int c : x) stuff.pb(c);
		}
		else{
			for(int c : y) stuff.pb(c);
		}
	}
	vi g;
	repn(i, 1, n + 1) if(i != stuff[0]){
		g.pb(i);
	}
	int ans = query(stuff, g);
	cout << "-1 " << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
