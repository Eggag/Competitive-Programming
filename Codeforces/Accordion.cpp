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
	string s;
	cin >> s;
	//find the first [
	//and the last ]
	//and in between them add : and | according to the rules
	int n = s.size();
	int f = -1;
	rep(i, n) if(s[i] == '['){
		f = i;
		break;
	}
	int st = -1;
	for(int i = n - 1; i >= 0; i--) if(s[i] == ']'){
		st = i;
		break;
	}
	if(f == -1 || st == -1 || st < f){
		cout << -1 << endl;
		return 0;
	}
	int fst = -1, lst = -1;
	repn(i, f + 1, st){
		if(s[i] == ':'){
			fst = i;
			break;
		}
	}
	for(int i = st - 1; i > f; i--){
		if(s[i] == ':'){
			lst = i;
			break;
		}
	}
	if(fst == -1 || lst == -1 || fst == lst){
		cout << -1 << endl;
		return 0;
	}
	int ans = 4; //minimum
	repn(i, fst + 1, lst){
		if(s[i] == '|') ans++;
	}
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
