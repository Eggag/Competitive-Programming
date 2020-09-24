#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

void solve(){
	ld a, b, c;
	cin >> a >> b >> c;
	ld d = (b * b) - (4 * a * c);
	if(d < 0) assert(0);
	ld s = sqrtl(d);
	if(s == 0) assert(0);
	else{
		ld ans1 = (-b + s) / (2 * a);
		ld ans2 = (-b - s) / (2 * a);
		if(ans1 < ans2) swap(ans1, ans2);
		cout << fixed << setprecision(15) << ans1 << endl << ans2 << endl;
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	solve();
	return 0;
}
