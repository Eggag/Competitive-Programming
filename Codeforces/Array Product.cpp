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
	int n;
	cin >> n;
	vi a(n);
	vi z;
	int neg = 0;
	pi mn = {1e9 + 1, -1};
	int nz = 0;
	rep(i, n){
		cin >> a[i];
		if(!a[i]) z.pb(i);
		else nz = 1;
		if(a[i] < 0){
			neg++;
			if(abs(a[i]) < mn.fi){
				mn.fi = abs(a[i]);
				mn.se = i;
			}
		}
	}
	if(!nz){
		rep(i, z.size() - 1){
			cout << "1 " << z[i] + 1 << " " << z[i + 1] + 1 << endl;
		}
		return 0;
	}
	if(neg && (z.size() == n - 1)){
		rep(i, n - 1){
			cout << "1 " << i + 1 << " " << i + 2 << endl;
		}
		return 0;
	}
	set<int> d;
	if(z.size()){
		if(neg % 2 != 0) z.pb(mn.se);
		rep(i, z.size() - 1){
			d.insert(z[i]);
			cout << "1 " << z[i] + 1 << " " << z[i + 1] + 1 << endl;
		}	
		d.insert(z[z.size() - 1]);
		cout << "2 " << z[z.size() - 1] + 1 << endl;
	}	
	else if(neg % 2 != 0){
		d.insert(mn.se);
		cout << "2 " << mn.se + 1 << endl; 
	}
	vi ans;
	rep(i, n){
		if(d.find(i) == d.end()) ans.pb(i);
	}
	rep(i, ans.size() - 1){			
		cout << "1 " << ans[i] + 1 << " " << ans[i + 1] + 1 << endl;
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
