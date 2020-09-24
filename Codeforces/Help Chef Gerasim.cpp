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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b(n);
	set<int> st;
	multiset<int> st1;
	rep(i, n) cin >> a[i], st.insert(a[i]), b[i] = a[i], st1.insert(a[i]);
	sort(all(b));
	int f = 1;
	repn(i, 1, n) if(b[i] != b[i - 1]) f = 0;
	if(f){
		cout << "Exemplary pages." << endl;
		return 0;
	}
	if(st.size() > 3){
		cout << "Unrecoverable configuration." << endl;
		return 0;
	}
	rep(i, n) rep(j, n) if(a[i] != a[j]){
		int mid = (a[i] + a[j]) / 2;
		if((st.find(mid) != st.end() || n <= 2) && (a[i] + a[j]) % 2 == 0 && st1.count(a[i]) == 1 && st1.count(a[j]) == 1){
			cout << abs(a[i] - a[j]) / 2 <<  " ml. from cup #" << (a[i] > a[j] ? j : i) + 1 << " to cup #" << (a[j] > a[i] ? j : i) + 1 << "." << endl;
			return 0;
		}
	}
	cout << "Unrecoverable configuration." << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
