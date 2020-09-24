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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	vector<ll> a(3 * n);
	rep(i, 3 * n) cin >> a[i];
	ll ans = -1e18;
	multiset<ll> st;
	ll sum = 0;
	rep(i, n) st.insert(a[i]), sum += a[i];
	vector<ll> p;
	repn(i, n, 3 * n) p.pb(a[i]);
	sort(all(p));
	ll sum2 = 0;
	rep(i, n) sum2 += p[i];
	ans = sum - sum2;
	multiset<ll> av;
	repn(i, n, 3 * n) av.insert(a[i]);
	int nm = n;
	ll sum3 = 0;
	multiset<ll> bst;
	ll mx = 0;
	while(nm--){
		sum3 += *av.begin();
		bst.insert(*av.begin());
		mx = max(mx, *av.begin());
		av.erase(av.begin());
	}
	repn(i, 1, n + 1){
		if(bst.find(a[n - 1 + i]) == bst.end() && av.find(a[n - 1 + i]) != av.end()) av.erase(av.find(a[n - 1 + i]));
		ll sum1 = sum;
		if(a[n + i - 1] > (*st.begin())){
			sum1 -= *st.begin();
			st.erase(st.begin());
			sum1 += a[n + i - 1];
			st.insert(a[n + i - 1]);
		}
		sum = sum1;
		if(a[n - 1 + i] <= mx){
			sum3 -= a[n - 1 + i];
			bst.erase(bst.find(a[n - 1 + i]));
			sum3 += *av.begin();
			mx = max(mx, *av.begin());
			bst.insert(*av.begin());
			av.erase(av.begin());
		}
		ans = max(ans, sum - sum3);
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
