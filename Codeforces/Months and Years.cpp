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

vi m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi m1 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi m3 = m;
vi m4 = m;
vi m5 = m;
vi m6 = m1;

int a[30];
int n;

bool run3(int pos){
	repn(i, 1, n){
		if(a[i] != m5[pos]) return 0;
		pos++;
	}
	return 1;
}

bool run4(int pos){
	repn(i, 1, n){
		if(a[i] != m6[pos]) return 0;
		pos++;
	}
	return 1;
}

bool run1(int pos){
	repn(i, 1, n){
		if(a[i] != m3[pos]) return 0;
		pos++;
	}
	return 1;
}

bool run2(int pos){
	repn(i, 1, n){
		pos %= 36;
		if(a[i] != m4[pos]) return 0;
		pos++;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, 12) m5.pb(m[i]);
	rep(i, 12) m5.pb(m[i]);
	rep(j, 12){
		if(a[0] == m[j]){
			if(run3(j + 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(i, 12) m6.pb(m[i]);
	rep(i, 12) m6.pb(m[i]);
	rep(j, 12){
		if(a[0] == m1[j]){
			if(run4(j + 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(i, 12) m3.pb(m1[i]);
	rep(i, 12) m3.pb(m[i]);
	rep(i, 12) m4.pb(m[i]);
	rep(i, 12) m4.pb(m1[i]);
	rep(j, 12){
		if(a[0] == m[j]){
			if(run1(j + 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(j, 12){
		if(a[0] == m[j]){
			if(run2(j + 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
