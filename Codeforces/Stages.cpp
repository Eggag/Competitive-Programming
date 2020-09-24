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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(all(s));
	string s1 = "";
	s1 += s[0];
	repn(i, 1, s.size()){
		if(s[i] != s[i - 1]) s1 += s[i];
	}
	int ans = s1[0] - 'a' + 1;
	k--;
	int ind = 1;
	int prev = 0;
	while(k){
		if(((s[ind] - 'a') - (s[prev] - 'a')) >= 2){
			ans += s[ind] - 'a' + 1;
			prev = ind;
			ind++;
			k--;
		}	
		else{
			ind++;
		}
		if((ind >= n) && k){
			cout << -1 << endl;
			return 0;
		}
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
