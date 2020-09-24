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

ll to_int(string s1){
	reverse(all(s1));
	ll num = 0;
	ll nm = 1;
	rep(i, s1.size()){
		num += nm * (s1[i] - '0');
		nm *= 10;
	}
	return num;
}

void solve(){
	ll n;
	cin >> n;
	ll n1 = n;
	ll cnt = 0;
	while(n1) n1 /= 10, cnt++;
	ll cnt1 = 0;
	repn(i, 1, cnt + 1){
		//i is the length
		repn(j, 1, 10){ //the digit
			string s = "";
			rep(k, i) s += (char)(j + '0');
			ll num = to_int(s);
			if(num <= n) cnt1++;
		}
	}
	cout << cnt1 << endl;
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
