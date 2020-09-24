#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int need[mxN], cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vi a(m), b(s);
	rep(i, m) cin >> a[i];
	rep(i, s) cin >> b[i], need[b[i]]++;
	int tot = 0, cur = 0;
	rep(i, mxN) if(need[i]) tot++;
	int ind = 0;
	while(ind < m && cur < tot){
		cnt[a[ind]]++;
		if(cnt[a[ind]] == need[a[ind]]) cur++;
		ind++;
	}
	if(cur < tot){
		cout << -1 << endl;
		return 0;
	}
	vi ans(m, -1);
	ans[0] = ind - 1;
	repn(i, 1, m){
		if(cnt[a[i - 1]] == need[a[i - 1]] && need[a[i - 1]]) cur--;
		cnt[a[i - 1]]--;
		while(ind < m && cur < tot){
			cnt[a[ind]]++;
			if(cnt[a[ind]] == need[a[ind]]) cur++;
			ind++;
		}
		if(cur < tot) break;
		ans[i] = ind - 1;
	}
	rep(i, m){
		if(ans[i] == -1) break;
		int nm = i / k;
		nm += ((m - i) - (ans[i] - i + 1 - k)) / k;
		if(nm >= n){
			int rem = i % k;
			vi cur;
			memset(cnt, 0, sizeof(cnt));
			for(int j = i - 1; j >= i - rem; j--) cur.pb(j + 1);
			int r = ans[i] - i + 1 - k;
			repn(j, i, ans[i] + 1){
				if(r <= 0) break;
				if(need[a[j]]){
					cnt[a[j]]++;
					if(cnt[a[j]] > need[a[j]]) cnt[a[j]]--, r--, cur.pb(j + 1);
				}
				else r--, cur.pb(j + 1);
			}
			cout << cur.size() << endl;
			for(int x : cur) cout << x << " ";
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
