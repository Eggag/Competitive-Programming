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
	int a;
	cin >> a;
	vi a1(a);
	rep(i, a) cin >> a1[i];
	int b;
	cin >> b;
	vi b1(b);
	rep(i, b) cin >> b1[i];
	int half = 24 * 60;
	int f = 0;
	rep(i, a) f += (a1[i] <= half);
	rep(i, b) f += (b1[i] <= half);
	cout << f << endl;
	vector<pi> tot;
	rep(i, a) tot.pb({a1[i], 1});
	rep(i, b) tot.pb({b1[i], 0});
	int sc = 0, sc1 = 0;
	sort(all(tot));
	int cur = -1;
	int ans = 0;
	rep(i, tot.size()){
		if(tot[i].se == 1) sc++;
		else sc1++;
		if(cur == 0){
			if(sc1 > sc) cur = 1, ans++;
		}
		else if(cur == 1){
			if(sc > sc1) cur = 0, ans++;
		}
		if(cur == -1){
			if(sc > sc1) cur = 0;
			else cur = 1;
		}
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
