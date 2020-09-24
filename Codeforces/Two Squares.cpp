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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vector<pi> a(4), b(4);
	rep(i, 4) cin >> a[i].fi >> a[i].se;
	sort(all(a));
	rep(i, 4){
		cin >> b[i].fi >> b[i].se;
		if((b[i].fi >= a[0].fi && b[i].fi <= a[2].fi) &&
				b[i].se >= a[0].se && b[i].se <= a[1].se){
			cout << "YES" << endl;
			return 0;
		}
	}
	sort(all(b));
	vi cnt(4, 0);
	rep(i, 4){
		//we are looking at the ith sq. vertex
		//check if it is above or below the right lines
		//b[0] - b[2]
		int cur = 0;
		if(a[i].fi >= b[0].fi && a[i].fi <= b[3].fi &&
				a[i].se <= b[2].se && a[i].se >= b[1].se){
			if(a[i].se <= (b[0].se + (a[i].fi - b[0].fi))) cur++, cnt[0]++;
			if(a[i].se >= (b[1].se + (b[1].fi - a[i].fi))) cur++, cnt[1]++;
			if(a[i].se <= (b[3].se + (b[3].fi - a[i].fi))) cur++, cnt[2]++;
			if(a[i].se >= (b[1].se + (a[i].fi - b[1].fi))) cur++, cnt[3]++;
		}
		if(cur == 4){
			cout << "YES" << endl;
			return 0;
		}
	}
	rep(i, 4) if(!cnt[i]){
		cout << "NO" << endl;
		return 0;
	}
	if(b[0].fi < a[0].fi && b[3].fi > a[2].fi &&
			b[1].se < a[0].se && b[2].se > a[1].se){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
