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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi A, B;
	rep(i, n){
		if(s[i] == 'A') A.pb(i);
		else B.pb(i);
	}
	ll ans = 0LL;
	int a = 0, b = 0;
	rep(i, n){
		if(s[i] == 'A'){
			a++;
			if(a == (int)(A.size())) continue;
			if(A[a] - 1 > i) ans += n - A[a];
			else ans += n - (i + 1) - (b < (int)(B.size()));
		}
		else{
			b++;
			if(b == (int)(B.size())) continue;
			if(B[b] - 1 > i) ans += n - B[b];
			else ans += n - (i + 1) - (a < (int)(A.size()));
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
