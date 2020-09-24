#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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
	freopen("names.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	string cur = "";
	vector<string> ans;
	char c;
	int st = 0;
	while(cin >> c){
		if(c == '"'){
			if(st){
				st = 0;
				ans.pb(cur);
				cur = "";
			}
			else{
				st = 1;
			}
		} 
		else if(c != ',') cur += c;
	}
	sort(all(ans));
	ll sum = 0;
	rep(i, ans.size()){
		string n = ans[i];
		ll cnt = 0;
		rep(j, n.size()) cnt += n[j] - 'A' + 1;
		sum += (i + 1) * cnt;
	}
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
