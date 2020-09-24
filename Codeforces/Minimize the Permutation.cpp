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
	vi a(n);
	vi p(105, -1);
	rep(i, n) cin >> a[i], p[a[i]] = i;
	int m = n - 1;
	set<pi> st;
	repn(i, 1, n + 1){
		if(!m) break;
		int ind = p[i];
		while(ind != 0 && m){
			if(a[ind - 1] < a[ind]) break;
			if(st.find(mp(ind, ind - 1)) != st.end()) break;
			p[a[ind - 1]]++;
			p[a[ind]]--;
			swap(a[ind], a[ind - 1]);
			st.insert(mp(ind, ind - 1));
			ind--;
			m--;
		}
	}
	rep(i, n) cout << a[i] << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
