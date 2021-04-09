#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 2e5 + 5;

ll bit[mxN];

void update(int ind, ll delta){
	for(; ind < mxN; ind = ind | (ind + 1)){
		bit[ind] += delta;
	}
}

ll query(int ind){
	ll sum = 0;
	for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
		sum += bit[ind];
	}
	return sum;
}

vi g[mxN];
vi st[mxN], en[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vi b(n);
	rep(i, n) cin >> b[i], g[b[i]].pb(i);
	for(int i = n - 1; i >= 1; i--){
		auto it = lower_bound(all(g[b[i]]), i);
		int l = 0;
		if(it != g[b[i]].begin()){
			it--;
			l = *it;
		}
		en[i].pb(i);
		st[l].pb(i);
	}
	ll ans = 0LL;
	rep(i, n - 1){
		for(int x : st[i]) update(x, 1);
		for(int x : en[i]) update(x, -1);
		auto it = lower_bound(all(g[b[i]]), i);
		it++;
		if(it == g[b[i]].end()) ans += query(mxN - 1);
		else{
			int nxt = *it - 1;
			ans += query(nxt);
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
