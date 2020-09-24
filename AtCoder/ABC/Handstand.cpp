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

int n, k;
string s;
vi comp(100005, 0);

bool check(int sz){
	rep(i, n - sz + 1){
		//we are looking at [i, i + sz)
		int num = comp[i + sz - 1] - (!i ? 0 : comp[i - 1]); //the number of 0 components
		if(i && (s[i - 1] == '0' && s[i] == '0')) num++;
		if(num <= k) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	cin >> s;
	int sz = 0;
	rep(i, n){
		if(i) comp[i] = comp[i - 1];
		if(s[i] == '0'){
			if(!sz) sz = 1, comp[i]++;
			else sz++;
		}
		else{
			if(sz) sz = 0;
		}
	}
	//do prefix sums on the number of 0 components
	//it is monotonic, if we can get n, we can get n - 1
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
