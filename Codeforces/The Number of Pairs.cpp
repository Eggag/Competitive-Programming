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
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 2e7 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN], vis[mxN];
 
void sieve(int n){
	for(int i = 2; i < n; i++) if(!p[i]){
		p[i] = i;
		for(int j = i + i; j < n; j += i) if(!p[j]) p[j] = i;
	}	
}

vector<pi> dd;
int in = 1;
vi owo;

void f(int ind, int num){
	if(vis[num] != in) owo.pb(num), vis[num] = in;
	if(ind == (int)(dd.size())) return;
	int mul = 1;
	rep(i, dd[ind].se + 1) f(ind + 1, num * mul), mul *= dd[ind].fi;
}

void solve(){
	int c, d, x;
	cin >> c >> d >> x;
	vi uwu;
	int nw = x;
	while(nw != 1){
		uwu.pb(p[nw]);
		nw /= p[nw];
	}
	dd.clear();
	owo.clear();
	sort(all(uwu));
	int cnt = ((int)(uwu.size()) ? 1 : 0);
	repn(j, 1, uwu.size()){
		if(uwu[j] == uwu[j - 1]) cnt++;
		else{
			dd.pb(mp(uwu[j - 1], cnt));
			cnt = 1;
		}
	}
	if(cnt) dd.pb(mp(uwu[(int)(uwu.size()) - 1], cnt));
	f(0, 1);
	int ans = 0;
	for(int num : owo){
		int sm = (x / num) + d;
		if(sm % c == 0){
			int cur = sm / c;
			int nm = 0;
			while(cur != 1){
				nm++;
				int div = p[cur];
				while(cur % div == 0) cur /= div;
			}
			ans += (1 << nm);
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	sieve(mxN - 2);
	while(t--) solve(), in++;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
