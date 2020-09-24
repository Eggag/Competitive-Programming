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
	string s;
	cin >> s;
	if(n & 1){
		cout << 0 << endl;
		return 0;
	}
	int bal = 0, cnt = 0, cnt1 = 0;
	vi bad, bad1;
	int prev = 1e9, prev1 = 0;
	rep(i, n){
		if(s[i] == ')') bal--;
		else bal++;
		if(bal < 0 && s[i] == ')' && bal < prev){
			cnt++;
			bad.pb(i);
			prev = bal;
		}
	}
	bal = 0;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == ')') bal--;
		else bal++;
		if(bal > 0 && s[i] == '(' && bal > prev1){
			cnt1++;
			bad1.pb(i);
			prev1 = bal;
		}
	}
	if(cnt > 2 || cnt1 > 2){
		cout << 0 << endl;
		return 0;
	}
	if(!bal){
		//if we flip we will destroy the balance
		cout << 0 << endl;
		return 0;
	}
	int num = 0;
	if(bal == 2){
		for(int i = n - 1; i >= bad1[0]; i--) if(s[i] == '(') num++;
		cout << num << endl;
		return 0;
	}
	if(bal == -2){
		rep(i, bad[0] + 1) if(s[i] == ')') num++;
		cout << num << endl;
		return 0;
	}
	if(bal != 2 && bal != -2){
		//we flip only one
		//so we can only change by 1
		cout << 0 << endl;
		return 0;
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
