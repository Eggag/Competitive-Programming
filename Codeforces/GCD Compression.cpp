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
	vi a(2 * n);
	rep(i, 2 * n) cin >> a[i];
	vi ev, odd;
	rep(i, 2 * n){
		if(a[i] & 1) odd.pb(i);
		else ev.pb(i);
	}
	if((int)(odd.size()) & 1){
		odd.pop_back();
		ev.pop_back();
	}
	else{
		if(ev.size() >= 2){
			ev.pop_back();
			ev.pop_back();
		}
		else if(odd.size() >= 2){
			odd.pop_back();
			odd.pop_back();
		}
		else assert(0);
	}
	for(int i = 0; i < odd.size(); i += 2){
		cout << odd[i] + 1 << " " << odd[i + 1] + 1 << endl;
	}
	for(int i = 0; i < ev.size(); i += 2){
		cout << ev[i] + 1 << " " << ev[i + 1] + 1 << endl;
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
