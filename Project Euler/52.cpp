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

vi fun(int n){
	set<int> st;
	while(n){
		st.insert(n % 10);
		if(n < 10) break;
		n /= 10;
	}
	vi ret(st.begin(), st.end());
	return ret;
}

bool eq(vi a, vi b){
	if(a.size() != b.size()) return 0;
	sort(all(a));
	sort(all(b));
	rep(i, a.size()) if(a[i] != b[i]) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int num = 1;
	while(1){
		int num2 = num * 2;
		int num3 = num * 3;
		int num4 = num * 4;
		int num5 = num * 5;
		int num6 = num * 6;
		vi n1 = fun(num);
		vi n2 = fun(num2);
		vi n3 = fun(num3);
		vi n4 = fun(num4);
		vi n5 = fun(num5);
		vi n6 = fun(num6);
		if(!eq(n1, n2) || !eq(n1, n3) || !eq(n1, n4) || !eq(n1, n5) || !eq(n1, n6)){
			num++;
			continue;
		}
		cout << num << endl;
		debug(num2);
		debug(num3);
		debug(num4);
		debug(num5);
		debug(num6);
		return 0;
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
