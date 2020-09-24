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
	vector<char> a(n);
	rep(i, n) cin >> a[i];
	vector<char> op;
	char c;
	int ind = 0;
	while(cin >> c) if(c != ' ') op.pb(c);
	vector<int> cur;
	rep(i, op.size()){
		if(op[i] <= 'Z' && op[i] >= 'A'){
		        cur.pb(a[ind] == 'T');
		        ind++;
		}
		else{
			if(op[i] == '*'){
				int tmp = cur[(int)cur.size() - 2] & cur[(int)cur.size() - 1];
				cur.pop_back();
				cur.pop_back();
				cur.pb(tmp);	
			}
			if(op[i] == '+'){
				int tmp = cur[(int)cur.size() - 2] | cur[(int)cur.size() - 1];
				cur.pop_back();
				cur.pop_back();
				cur.pb(tmp);	
			}
			if(op[i] == '-') cur[(int)cur.size() - 1] ^= 1;
		}
	}
	cout << (cur[0] ? 'T' : 'F') << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
