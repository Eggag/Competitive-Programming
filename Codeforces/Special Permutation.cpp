#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	if(n <= 3) cout << -1 << endl;
	else{
		vi ev, odd;
		repn(i, 1, n + 1){
			if(i & 1) odd.pb(i);
			else ev.pb(i);
		}
		reverse(all(ev));
		swap(ev[0], ev[1]);
		if(abs(odd[(int)odd.size() - 1] - ev[0]) < 2){
			swap(ev[0], ev[1]);
			swap(odd[(int)odd.size() - 1], odd[(int)odd.size() - 2]);
			rep(i, odd.size()) cout << odd[i] << " ";
			rep(i, ev.size()) cout << ev[i] << " ";
			cout << endl;
		}
		else{
			rep(i, odd.size()) cout << odd[i] << " ";
			rep(i, ev.size()) cout << ev[i] << " ";
			cout << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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
