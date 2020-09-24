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

string tstr(ll n){
	string ret = "";
	while(n){
		ret += (char)('0' + (n % 10));
		n /= 10;
	}
	reverse(all(ret));
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n1;
	cin >> n1;
	string s = tstr(n1);
	int n = s.size();
	if(n == 2){
		if(n1 == 25 || n1 == 50 || n1 == 75) cout << 0 << endl;
		else if(n1 == 52 || n1 == 57) cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	int ans = 1e9;
	//try to make it 00
	rep(i, s.size()) repn(j, i + 1, s.size()) if(s[i] == '0' && s[j] == '0'){
		ans = min(ans, abs(i - (n - 2)) + abs(j - (n - 1)));
	}
	//try to make it 25
	rep(i, s.size()) rep(j, s.size()) if(s[i] == '2' && s[j] == '5'){
		if(i == (n - 1) && j == (n - 2)){
			ans = min(ans, 1); //just swap them
			continue;
		}
		int cur = abs((n - 2) - i) + abs((n - 1) - j);
		if(j < i) cur++;
		//now deal with the 0 left situation
		int ind = 0;
		while(ind < n && (ind == j || ind == i || s[ind] == '0')){
			cur++;
			if(ind == j) cur--;
			if(ind == i) cur--;
			ind++;
		}
		if(ind != n) ans = min(ans, cur);
	}
	//try to make it 50
	rep(i, s.size()) rep(j, s.size()) if(s[i] == '5' && s[j] == '0'){
		if(i == (n - 1) && j == (n - 2)){
			ans = min(ans, 1); //just swap them
			continue;
		}
		int cur = abs((n - 2) - i) + abs((n - 1) - j);
		if(j < i) cur++;
		//now deal with the 0 left situation
		int ind = 0;
		while(ind < n && (ind == j || ind == i || s[ind] == '0')){
			cur++;
			if(ind == j) cur--;
			if(ind == i) cur--;
			ind++;
		}
		if(ind != n) ans = min(ans, cur);
	}
	//try to make it 75
	rep(i, s.size()) rep(j, s.size()) if(s[i] == '7' && s[j] == '5'){
		if(i == (n - 1) && j == (n - 2)){
			ans = min(ans, 1); //just swap them
			continue;
		}
		int cur = abs((n - 2) - i) + abs((n - 1) - j);
		if(j < i) cur++;
		//now deal with the 0 left situation
		int ind = 0;
		while(ind < n && (ind == j || ind == i || s[ind] == '0')){
			cur++;
			if(ind == j) cur--;
			if(ind == i) cur--;
			ind++;
		}
		if(ind != n) ans = min(ans, cur);
	}
	//try to make it 25
	rep(i, s.size()) rep(j, s.size()) if(s[i] == '2' && s[j] == '5'){
		if(i == (n - 2) && j == (n - 1)){
			ans = min(ans, 1); //just swap them
			continue;
		}
		int cur = abs((n - 1) - i) + abs((n - 2) - j);
		if(i < j) cur++;
		//now deal with the 0 left situation
		int ind = 0;
		while(ind < n && (ind == j || ind == i || s[ind] == '0')){
			cur++;
			if(ind == j) cur--;
			if(ind == i) cur--;
			ind++;
		}
		if(ind != n) ans = min(ans, cur + 1);
	}
	//try to make it 50
	rep(i, s.size()) rep(j, s.size()) if(s[i] == '5' && s[j] == '0'){
		if(i == (n - 2) && j == (n - 1)){
			ans = min(ans, 1); //just swap them
			continue;
		}
		int cur = abs((n - 1) - i) + abs((n - 2) - j);
		if(i < j) cur++;
		//now deal with the 0 left situation
		int ind = 0;
		while(ind < n && (ind == j || ind == i || s[ind] == '0')){
			cur++;
			if(ind == j) cur--;
			if(ind == i) cur--;
			ind++;
		}
		if(ind != n) ans = min(ans, cur + 1);
	}
	//try to make it 75
	rep(i, s.size()) rep(j, s.size()) if(s[i] == '7' && s[j] == '5'){
		if(i == (n - 2) && j == (n - 1)){
			ans = min(ans, 1); //just swap them
			continue;
		}
		int cur = abs((n - 1) - i) + abs((n - 2) - j);
		if(i < j) cur++;
		//now deal with the 0 left situation
		int ind = 0;
		while(ind < n && (ind == j || ind == i || s[ind] == '0')){
			cur++;
			if(ind == j) cur--;
			if(ind == i) cur--;
			ind++;
		}
		if(ind != n) ans = min(ans, cur + 1);
	}
	cout << (ans == 1e9 ? -1 : ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
