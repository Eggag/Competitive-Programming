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
	string s;
	cin >> s;
	int q;
	cin >> q;
	int cnt = 0;
	deque<char> le, ri;
	int rev = 0;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			cnt++;
		}
		else{
			int f;
			char c;
			cin >> f >> c;
			if(f == 1){
				if(cnt & 1) ri.push_back(c);
				else le.push_front(c);
			}
			else{
				if(cnt & 1) le.push_front(c);
				else ri.push_back(c);
			}
		}
	}
	if(cnt & 1) reverse(all(s));
	if(cnt & 1) swap(le, ri);
	if(cnt & 1) reverse(all(le)), reverse(all(ri));
	for(char x : le) cout << x;
	cout << s;
	for(char x : ri) cout << x;
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
