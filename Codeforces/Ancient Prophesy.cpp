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

bool dig(char x){
	return (x >= '0' && x <= '9');
}

int mystoi(string s){
	int ret = 0;
	int mul = 1;
	for(int i = s.size() - 1; i >= 0; i--){
		ret += mul * (int)(s[i] - '0');
		mul *= 10;
	}
	return ret;
}

int mo[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool valid(int d, int m, int y){
	if(!(y >= 2013 && y <= 2015)) return 0;
	if(!(m >= 1 && m <= 12)) return 0;
	if(!d || d > mo[m - 1]) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	//lmao there
	map<string, int> m;
	rep(i, n - 10 + 1){
		//first 2 are digits
		if(!dig(s[i])) continue;
		if(!dig(s[i + 1])) continue;
		string day = "";
		day += s[i];
		day += s[i + 1];
		if(s[i + 2] != '-') continue;
		if(!dig(s[i + 3])) continue;
		if(!dig(s[i + 4])) continue;
		string month = "";
		month += s[i + 3];
		month += s[i + 4];
		if(s[i + 5] != '-') continue;
		if(!dig(s[i + 6])) continue;
		if(!dig(s[i + 7])) continue;
		if(!dig(s[i + 8])) continue;
		if(!dig(s[i + 9])) continue;
		string year = s.substr(i + 6, 4);
		if(valid(mystoi(day), mystoi(month), mystoi(year))) m[s.substr(i, 10)]++;
	}
	string bst = "";
	int mx = 0;
	for(pair<string, int> x : m){
		if(x.se > mx){
			mx = x.se;
			bst = x.fi;
		}
	}
	cout << bst << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
