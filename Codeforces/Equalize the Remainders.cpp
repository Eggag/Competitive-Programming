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
	int n, m;
	cin >> n >> m;
	vi cnt(m, 0);
	vi a(n);
	rep(i, n) cin >> a[i], cnt[a[i] % m]++;
	set<int> av; //we store the ones that need to be fixed here
	rep(i, m) if(cnt[i] < (n / m)) av.insert(i);
	ll ans = 0;
	rep(i, n) if(cnt[a[i] % m] > (n / m)){
		int cur = (a[i] % m);
		auto it = av.lb(cur);
		if(it != av.end()){
			int nxt = *it;
			a[i] += nxt - cur;
			ans += nxt - cur;
			cnt[cur]--;
			cnt[nxt]++;
			if(cnt[nxt] == (n / m)) av.erase(*it);
		}
		else{
			assert(av.size());
			int nxt = *av.begin();
			a[i] += ((nxt + 1) + (m - 1 - cur));
			ans += ((nxt + 1) + (m - 1 - cur));
			cnt[cur]--;
			cnt[nxt]++;
			if(cnt[nxt] == (n / m)) av.erase(*av.begin());
		}
	}
	cout << ans << endl;
	rep(i, n) cout << a[i] << " ";
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
