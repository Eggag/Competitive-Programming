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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool prime(ll num){
	for(ll i = 2; (i * i) <= num; i++){
		if(num % i == 0) return 0;
	}
	return 1;
}

void solve(){
	ll z;
	cin >> z;
	ll s = sqrtl(z), s1 = s - 1;
	ll a = -1, b = -1;
	ll c = -1, d = -1;
	while(true){
		if(prime(s)){
			if(c == -1) c = s;
			else{
				d = s;
				break;
			}
		}
		s++;
	}
	while(true){
		if(prime(s1)){
			if(a == -1) a = s1;
			else{
				b = s1;
				break;
			}
		}
		s1--;
	}
	if(c * d <= z) cout << c * d << '\n';
	else if (c * a <= z) cout << c * a << '\n';
	else cout << a * b << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
