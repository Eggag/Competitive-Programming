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
	int n;
	cin >> n;
	string s, s1;
	cin >> s >> s1;
	ll ch = 0; //how many would change if they got a zero
	rep(i, n){
		if(s[i] == '1' && s1[i] == '0') ch++;
	}
	ll cnt = 0;
	rep(i, n) if(s[i] == '0') cnt++;
	ll ch1 = 0;
	rep(i, n){
		if(s[i] == '0' && s1[i] == '0') ch1++;
	}
	ll cnt1 = 0;
	rep(i, n) if(s[i] == '1') cnt1++;
	ll cnt3 = 0, cnt4 = 0;
	rep(i, n) if(s[i] == '0' && s1[i] == '0') cnt3++;
	rep(i, n) if(s[i] == '1' && s1[i] == '0') cnt4++;
	ll ans = (cnt * ch) + (cnt1 * ch1) - (cnt4 * cnt3);
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
