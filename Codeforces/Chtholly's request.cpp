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
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
ll llto_string(string s){
	ll sum = (s[0] - '0');
	ll prev = 1;
	repn(i, 1, s.size()){
		sum = (sum + (prev * 10 * (s[i] - '0')));
		prev = (prev * 10);
	}
	return (sum);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int k, p;
	cin >> k >> p;
	ll sum = 0;
	repn(i, 1, k + 1){
		string s = to_string(i);
		string s1 = s;
		reverse(all(s1));
		s += s1;
		ll cur = llto_string(s);
		sum = (sum + cur) % p;
	}
	cout << sum % p << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
