#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	map<char, int> mp;
	rep(i, s.size()) mp[s[i]]++;
	if(mp.size() > 4){
		cout << "No" << endl;
		return 0;
	}
	if(mp.size() == 4){
		cout << "Yes" << endl;
	}
	if(mp.size() == 3){
		bool f = 0;
		for(auto x : mp) if(x.se >= 2) f = 1;
		if(f){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	if(mp.size() == 2){
		bool f = 1;
		for(auto x : mp) if(x.se < 2) f = 0;
		if(f){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	if(mp.size() == 1){
		cout << "No" << endl;
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
