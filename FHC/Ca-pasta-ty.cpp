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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll solve(){
	ll n, k;
	cin >> n >> k;
	vector<array<ll, 3>> s(n);
	rep(i, k) cin >> s[i][0];
	ll as, bs, cs, ds;
	cin >> as >> bs >> cs >> ds;
	rep(i, k) cin >> s[i][1];
	ll ax, bx, cx, dx;
	cin >> ax >> bx >> cx >> dx;
	rep(i, k) cin >> s[i][2];
	ll ay, by, cy, dy;
	cin >> ay >> by >> cy >> dy;
	repn(i, k, n){
		s[i][0] = ((as * s[i - 2][0]) + (bs * s[i - 1][0]) + cs) % ds;	
		s[i][1] = ((ax * s[i - 2][1]) + (bx * s[i - 1][1]) + cx) % dx;	
		s[i][2] = ((ay * s[i - 2][2]) + (by * s[i - 1][2]) + cy) % dy;	
	}
	ll to_put = 0LL;
	ll need_dec = 0LL;
	ll ans = 0LL;
	rep(i, n){
		if(s[i][0] < s[i][1]) to_put += s[i][1] - s[i][0];
		if(s[i][0] > s[i][1] + s[i][2]) need_dec += s[i][0] - (s[i][2] + s[i][1]);
	}
	if(to_put > need_dec){
		ans = need_dec;
		to_put -= need_dec;
		ll can_put = 0LL;
		rep(i, n){
			s[i][0] = min(s[i][0], s[i][2] + s[i][1]);
			s[i][0] = max(s[i][0], s[i][1]);
			can_put += max(0LL, s[i][0] - s[i][1]);
		}
		if(can_put >= to_put){
			ans += to_put;
			return ans;
		}
		return -1;
	}
	else{
		ans = to_put;
		need_dec -= to_put;
		ll can_put = 0LL;
		rep(i, n){
			s[i][0] = min(s[i][0], s[i][2] + s[i][1]);
			s[i][0] = max(s[i][0], s[i][1]);
			can_put += max(0LL, s[i][1] + s[i][2] - s[i][0]);
		}
		if(can_put >= need_dec){
			ans += need_dec;
			return ans;
		}
		return -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
