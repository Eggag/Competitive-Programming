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
	string s, s1;
	cin >> s >> s1;
	int n = s.size();
	int cnt = 0;
	rep(i, n){
		if(s[i] == '+') cnt++;
		else cnt--;
	}
	int cnt1 = 0;
	int cur = 0;
	rep(i, n){
		if(s1[i] == '+') cnt1++;
		else if(s1[i] == '-') cnt1--;
		else cur++;
	}
	cout << fixed << setprecision(15);
	if(!cur){
		if(cnt == cnt1) cout << (ld)1 << endl;
		else cout << (ld)0 << endl;
		return 0;
	}
	int num;
	if(cnt < cnt1){
		num = (cur - (cnt1 - cnt)) / 2;
	}
	else{
		num = ((cur - (cnt - cnt1)) / 2) + (cnt - cnt1);
	}
	ld cnt2 = 0;
	rep(i, (1 << cur)){
		int c = __builtin_popcount(i);
		if(c == num) cnt2++;
	}
	ld num1 = cnt2;
	ld den = (1 << cur);
	ld ans = (ld)(num1 / den);
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
