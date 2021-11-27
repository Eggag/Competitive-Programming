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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<ll, ll> cnt[mxN];
int p[mxN], vis[mxN];

void sieve(){
	repn(i, 2, mxN) if(!p[i]){
		p[i] = i;
		for(int j = i + i; j < mxN; j += i) if(!p[j]) p[j] = i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll x, y;
	cin >> n >> y >> x;
	vi a(n);
	int g = 0;
	rep(i, n) cin >> a[i], g = gcd(a[i], g);
	if(g != 1){
		cout << "0\n";
		return 0;
	}
	sieve();
	ll uwu = 0;
	rep(i, n) if(a[i] & 1) uwu += min(x, y);
	rep(i, mxN) cnt[i] = mp(0, i);
	memset(vis, -1, sizeof(vis));
	rep(i, n){
		int cur = a[i];
		while(cur != 1){
			if(vis[p[cur]] != i){
				cnt[p[cur]].fi++;
				vis[p[cur]] = i;
			}
			cur /= p[cur];
		}
	}
	sort(cnt, cnt + mxN);
	reverse(cnt, cnt + mxN);
	int nm = 0;
	rep(i, mxN) if(cnt[i].fi){
		if(min(x, y) * (n - cnt[i].fi) > uwu) break;
		ll owo = min(x, y) * (n - cnt[i].fi);
		rep(j, n) if(a[j] % cnt[i].se != 0){
			owo -= min(x, y);
			owo += min(x * (cnt[i].se - (a[j] % cnt[i].se)), y);
			if(owo > uwu) break;
		}
		uwu = min(uwu, owo);
		nm++;
		if(nm > 500) break;
	}
	cout << uwu << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
