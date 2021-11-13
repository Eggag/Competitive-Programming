#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<vi> cr;
	rep(i, n){
		vi nw;
		rep(j, n - 1){
			if(s[j] == 'R' && s[j + 1] == 'L'){
				swap(s[j], s[j + 1]);
				nw.pb(j + 1);
				j++;
			}	
		}
		if(nw.size()) cr.pb(nw);
		else break;
	}
	if((int)(cr.size()) > k || !cr.size()){
		cout << -1 << '\n';
		return 0;
	}
	vector<vi> nww;
	int sz = (int)(cr.size());
	rep(i, cr.size()){
		while(cr[i].size() > 1){
			if(sz == k) break;
			int lst = cr[i].back();
			cr[i].pop_back();
			nww.pb(vi{lst});
			sz++;
		}
		nww.pb(cr[i]);
	}
	if((int)(nww.size()) != k) cout << -1 << '\n';
	else{
		rep(i, k){
			cout << (int)(nww[i].size());
			for(int x : nww[i]) cout << " " << x;
			cout << '\n';
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
