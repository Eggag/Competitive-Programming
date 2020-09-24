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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s1;
	cin >> s1;
	string s = "";
	rep(i, n) if(s1[i] != '0') s += s1[i];
	n = s.length();
	if(!n){
		cout << "YES" << endl;
		return 0;
	}
	int c = 0;
	rep(i, n) c += s[i] - '0';
	vi pos;
	repn(i, 1, c){
		if(c % i == 0) pos.pb(i);
	}
	//for(int x : pos) debug(x);
	rep(i, pos.size()){
		int sum = 0;
		int j;
		for(j = 0; j < n; j++){
			sum += s[j] - '0';
			if(sum == pos[i]) sum = 0;
			if(sum > pos[i]) break;
		}
		if(j == n){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
