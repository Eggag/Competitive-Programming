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

int v[10005];

vi div(int num){
	vi d;
	for(int i = 1; (i * i) <= num; i++){
		if(num % i == 0){
			if(i != num) d.pb(i);
			if((num / i) != i && i != 1) d.pb(num / i);
		}
	}
	return d;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	memset(v, 0, sizeof(v));
	int ans = 0;
	vi di = div(220);
	repn(i, 1, 10000){
		vi d = div(i);
		int sum = 0;
		rep(j, d.size()) sum += d[j];
		vi d1 = div(sum);
		int sum1 = 0;
		rep(j, d1.size()) sum1 += d1[j];
		if(i == sum1 && i != sum) ans += i;
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
