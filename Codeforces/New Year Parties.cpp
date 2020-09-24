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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	set<int> num;
	rep(i, n){
		if(!i){
			num.insert(a[i] - 1);
		}
		else{
			if(!num.count(a[i] - 1)) num.insert(a[i] - 1);
			else if(!num.count(a[i])) num.insert(a[i]);
			else if(!num.count(a[i] + 1)) num.insert(a[i] + 1);
		}
	}
	int mx = num.size();
	//now the min
	set<int> num1;
	rep(i, n){
		if(!i){
			num1.insert(a[i] + 1);
		}
		else{
			if(num1.count(a[i])) num1.insert(a[i]);
			else if(num1.count(a[i] - 1)) num1.insert(a[i] - 1);
			else num1.insert(a[i] + 1);
		}
	}
	int mn = num1.size();
	cout << mn << " " << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
