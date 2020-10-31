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

pi qry(vi q){
	cout << "?";
	rep(i, q.size()) cout << " " << q[i];
	cout << endl;
	int a, b;
	cin >> a >> b;
	return mp(a, b);
}

int main(){
	int n, k;
	cin >> n >> k;
	vi q;
	rep(i, k) q.pb(i + 1);
	pi ans = qry(q);
	q.clear();
	rep(i, k + 1) if(i != ans.fi - 1) q.pb(i + 1);
	pi ans1 = qry(q);
	int exp = ans.se;
	if(ans.se < ans1.se) exp = ans1.se;
	int cnt = 0;
	rep(i, k) if(i != (ans.fi - 1)){
		vi q1;
		rep(j, k + 1) if(j != i) q1.pb(j + 1);
		pi cur = qry(q1);
		if(cur.se == exp) cnt++;
	}
	cout << "! " << cnt + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
