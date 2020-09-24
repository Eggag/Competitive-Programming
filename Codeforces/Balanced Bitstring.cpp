#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int z = 0, on = 0;
	rep(i, k){
		if(s[i] == '0') z++;
		else if(s[i] == '1') on++;
	}
	if(on > (k / 2)){
		cout << "NO" << endl;
		return;
	}
	if(z > (k / 2)){
		cout << "NO" << endl;
		return;
	}
	vi vis(n, 0);
	int allx = 0, an = 0, az = 0;
	rep(i, n) if(!vis[i]){
		int a = 0, b = 0;
		for(int j = i; j < n; j += k){
			if(s[j] == '1') a++;
			if(s[j] == '0') b++;
			vis[j] = 1;
		}
		if(i < k && s[i] == '?'){
			if(!b && !a) allx++;
			else if(!a) az++;
			else if(!b) an++;
		}
		if(a && b){
			cout << "NO" << endl;
			return;
		}
	}
	int nm = k / 2 - on;
	if((allx + an) < nm){
		cout << "NO" << endl;
		return;
	}
	else{
		if(nm > an){
			allx -= nm - an;
		}
	}
	nm = k / 2 - z;
	if((allx + az) < nm){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
