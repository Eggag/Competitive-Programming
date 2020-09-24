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

void solve(){
	int n, p, k;
	cin >> n >> p >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	int p1 = p;
	int ans = 0;
	for(int i = 1; i < n; i += 2){
		if(p1 < a[i - 1]){
			break;
		}
		else if(p1 >= a[i - 1] && p1 < (a[i])){
			ans++;
			break;
		}
		else{
			ans += 2;
			p1 -= a[i];
		}
	}
	int ans1 = (p > a[0]);
	if(n > 2){
		p1 = p - a[0];
		for(int i = 2; i < n; i += 2){
			if(p1 < a[i - 1]){
				break;
			}
			else if(p1 >= a[i - 1] && p1 < (a[i])){
				ans1++;
				break;
			}
			else{
				ans1 += 2;
				p1 -= a[i];
			}
		}
	}
	cout << max(ans, ans1) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
