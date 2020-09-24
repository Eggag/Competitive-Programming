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

bool suf(string a, string b){
	if(a.size() > b.size()) return 0;
	reverse(all(a));
	reverse(all(b));
	rep(i, a.size()){
		if(a[i] != b[i]) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	map<string, set<string>> mp;
	rep(i, n){
		string name;
		int num;
		cin >> name >> num;
		rep(j, num){
			string s;
			cin >> s;
			mp[name].insert(s);
		}
	}
	cout << mp.size() << endl;
	for(auto x : mp){
		for(string y : x.se){
			for(string z : x.se) if(y != z){
				if(suf(y, z)) mp[x.fi].erase(y);
				else if(suf(z, y)) mp[x.fi].erase(z);
			}
		}
	}
	for(auto x : mp){
		cout << x.fi << " ";
		cout << x.se.size();
		for(string y : x.se) cout << " " << y;
		cout << endl;
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
