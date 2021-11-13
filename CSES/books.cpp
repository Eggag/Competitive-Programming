#include <bits/stdc++.h>
#include "books.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define debug(x) cerr << #x << " " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))

void solve(int n, int k, ll a, int s){
	int l = k, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		ll cur = skim(mid);
		if((ll)(cur * k) >= a) r = mid;
		else l = mid + 1;
	}
	if((ll)(skim(n) * k) < a) impossible();
	ll sum = 0LL;
	vi ans;
	vector<ll> rem;
	repn(i, (l - k) + 1, l + 1){
		ll s = skim(i);
		sum += s;
		ans.pb(i);
		rem.pb(s);
	}
	if(sum >= a){
		if(sum > 2 * a) impossible();
		answer(ans);
		return;
	}
	repn(i, l + 1, l + 1 + k){
		ll cr = skim(i);
		sum -= rem[i - (l + 1)];
		sum += cr;
		ans.pb(i);
		if(sum >= a && sum <= 2 * a){
			vi ans1;
			repn(j, (i - (l + 1)) + 1, ans.size()) ans1.pb(ans[j]);
			answer(ans1);
			return;
		}
		if(sum > 2 * a){
			ll sm = 0LL;
			vi ans1;
			repn(j, 1, k) sm += skim(j), ans1.pb(j);
			cr += sm;
			if(cr >= a && cr <= 2 * a){
				ans1.pb(i);
				answer(ans1);
				return;
			}
			else impossible();
		}
	}
	impossible();
}
