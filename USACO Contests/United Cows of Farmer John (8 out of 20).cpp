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
const int mxN = 5005;

ll bit[mxN];
vi st[mxN], en[mxN], g[mxN];
int l[mxN], r[mxN];

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vi b(n);
	rep(i, n) cin >> b[i], g[b[i]].pb(i);
	//for n <= 5000 we can do the same thing as in gold
	//except we have to iterate in the sweep, so it is n^2 logn
	for(int i = n - 1; i >= 0; i--){
		l[i] = 0, r[i] = mxN - 1;
		auto it = lower_bound(all(g[b[i]]), i); //right
		it++;
		if(it != g[b[i]].end()) r[i] = *it - 1;
		it--;
		if(it != g[b[i]].begin()){
			it--;
			l[i] = *it + 1;
		}
		st[l[i]].pb(i);
		en[i].pb(i);
	}
	ll ans = 0LL;
	rep(i, n){
		for(int x : st[i]) update(x, 1);
		for(int x : en[i]) update(x, -1);
		//now we iterate over potential 'middle' leaders
		repn(j, i + 1, min(r[i] + 1, n)) if(l[j] <= i){
			int ri = min(r[i], r[j]);	
			//debug("?");
			ans += query(ri) - query(j);
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
