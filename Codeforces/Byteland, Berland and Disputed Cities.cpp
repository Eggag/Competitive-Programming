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
#define inf 0x3f3f3f3f

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ll, char>> p(n);
	rep(i, n){
		ll x;
		char c;
		cin >> x >> c;
		p[i] = mp(x, c);
	}
	int st = n;
	rep(i, n) if(p[i].se == 'P'){
		st = i;
		break;
	}
	ll lstB = -inf, lstR = -inf;
	ll ans = 0LL;
	rep(i, st){
		if(p[i].se == 'B'){
			if(lstB != -inf) ans += p[i].fi - lstB;
			lstB = p[i].fi;
		}
		else{
			if(lstR != -inf) ans += p[i].fi - lstR;
			lstR = p[i].fi;
		}
	}
	if(st != n){
		if(lstB != -inf) ans += p[st].fi - lstB;
		if(lstR != -inf) ans += p[st].fi - lstR;
	}
	repn(i, st, n){
		int cr = i;
		i++;
		while(i < n && p[i].se != 'P') i++;
		if(i == n){
			ll lst1 = p[cr].fi, lst2 = p[cr].fi;
			repn(j, cr + 1, n){
				if(p[j].se == 'B'){
					ans += p[j].fi - lst1;
					lst1 = p[j].fi;
				}
				else{
					ans += p[j].fi - lst2;
					lst2 = p[j].fi;
				}
			}
		}
		else{
			int f = 0, f1 = 0;
			repn(j, cr + 1, i){
				if(p[j].se == 'B') f = 1;
				if(p[j].se == 'R') f1 = 1;
			}
			ll cur = 2 * (p[i].fi - p[cr].fi);
			ll cur1 = (f + f1 + 1) * (p[i].fi - p[cr].fi);
			ll g = 0LL, g1 = 0LL;
			ll lst1 = p[cr].fi, lst2 = p[cr].fi;
			repn(j, cr + 1, i + 1){
				if(p[j].se == 'B'){
					g = max(g, p[j].fi - lst1);
					lst1 = p[j].fi;
				}
				else if(p[j].se == 'R'){
					g1 = max(g1, p[j].fi - lst2);
					lst2 = p[j].fi;
				}
				else{
					if(lst1 != p[cr].fi) g = max(g, p[j].fi - lst1);
					lst1 = p[j].fi;
					if(lst2 != p[cr].fi) g1 = max(g1, p[j].fi - lst2);
					lst2 = p[j].fi;
				}
			}
			ans += min(cur, cur1 - (g + g1));
			i--;
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
