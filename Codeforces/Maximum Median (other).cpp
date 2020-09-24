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
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	if(n == 1){
		cout << a[0] + k << endl;
		return 0;
	}
	ll num = n / 2;
	ll ans = a[num];
	ll cur = 0;
	repn(i, num, n){
		i++;
		while(i < n && a[i] == a[i - 1]){
			i++;
			cur++;
		}
		i--;
		cur++;
		if(i == (n - 1)){
			k /= cur;
			ans += k;
			break;
		}
		else{
			if(k >= ((a[i + 1] - a[i]) * cur)){
				ans = a[i + 1];
				k -= (a[i + 1] - a[i]) * cur;
			}
			else{
				k /= cur;
				ans += k;
				break;
			}
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
