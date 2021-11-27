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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<array<int, 21>, int> cnt[mxN], cnt1[mxN];
array<int, 21> cnt2[mxN];
int cur = 0;

ld f(int i){
	ld ans = (ld)(cnt1[i].fi[20] - cnt1[i].fi[cur - 1]) + (ld)((ld)(cnt2[i][cur - 1]) / (ld)(cur));
	return ans;
}

bool cmp(pair<array<int, 21>, int> a, pair<array<int, 21>, int> b){
	return f(a.se) > f(b.se);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi m(n), k(n);
	rep(i, mxN){
		cnt[i].se = cnt1[i].se = mxN - 1;
		rep(j, 20) cnt[i].fi[j] = cnt1[i].fi[j] = 0;
	}
	rep(i, n){
		cin >> m[i] >> k[i];
		cnt[m[i] - 1].fi[k[i]]++;
		cnt[m[i] - 1].se = m[i] - 1;
		cnt1[m[i] - 1].fi[k[i]]++;
		cnt1[m[i] - 1].se = m[i] - 1;
		cnt2[m[i] - 1][k[i]] += k[i];
	}
	rep(i, mxN) repn(j, 1, 21){
		cnt[i].fi[j] += cnt[i].fi[j - 1];
		cnt1[i].fi[j] += cnt1[i].fi[j - 1];
		cnt2[i][j] += cnt2[i][j - 1];
	}
	ld ans = 0;
	vi bst;
	repn(i, 1, 21){
		cur = i;
		sort(cnt, cnt + mxN, cmp);
		ld uwu = 0.0;
		vi cr;
		rep(j, i){
			uwu += f(cnt[j].se);
			cr.pb(cnt[j].se);
		}
		if(uwu > ans){
			ans = uwu;
			bst = cr;
		}
	}
	cout << (int)(bst.size()) << '\n';
	for(int x : bst) cout << x + 1 << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
