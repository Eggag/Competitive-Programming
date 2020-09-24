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

void solve(){
	string a, b;
	cin >> a >> b;
	//keep track of locations and if letters don't match, print "NO"
	int i = 0, j = 0; //starting locations.
	while(i < a.size()){
		if(a[i] != b[j]){
			cout << "NO" << endl;
			return;
		}
		int f = 0;
		if(a[i + 1] != a[i] || i == a.size() - 1){
			while(j < b.size() - 1 && b[j] == b[j + 1]){
				j++;
				f = 1;
			}
		}
		i++, j++;
	}
	if(i != a.size() || j != b.size()) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	while(n--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
