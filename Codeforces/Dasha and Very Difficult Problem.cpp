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

int nm[100005];

bool cmp(pi a, pi b){
	return nm[a.se] < nm[b.se];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, l, r;
	cin >> n >> l >> r;
	vi p(n);
	vector<pi> a(n);
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	rep(i, n) cin >> p[i], nm[i] = p[i];
	sort(all(a), cmp);
	//for the smallest c[i]
	//take b = l
	//and the next one has to be larger than that
	//but with b <= r
	vi ans(n, 0);
	int lst = l - a[0].fi;
	ans[a[0].se] = l;
	repn(i, 1, n){
		ans[a[i].se] = (lst + 1) + a[i].fi;
		if(ans[a[i].se] > r){
			cout << -1 << endl;
			return 0;
		}
		if(ans[a[i].se] < l) lst += l - ans[a[i].se], ans[a[i].se] = l;
		lst++;
	}	
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
