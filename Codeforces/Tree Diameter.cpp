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

vi a, b;

ll query(){
	cout << a.size() << " " << b.size();
	for(int c : a) cout << " " << c;
	for(int c : b) cout << " " << c;
	cout << endl;
	ll res;
	cin >> res;
	return res;
}

void solve(){
	int n;
	cin >> n;
	ll ans = 0;
	rep(i, 7){
		a.clear(), b.clear();
		repn(j, 1, n + 1){
			if(j & (1 << i)) a.pb(j);
			else b.pb(j);
		}
		if(!a.size() || !b.size()) continue;
		ans = max(ans, query());
	}	
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
