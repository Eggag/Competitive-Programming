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
const int MAXN = 15;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void update(int ind, T delta){
		for(; ind < MAXN; ind += (ind & (-ind))){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind; ind -= (ind & (-ind))){
			sum += bit[ind];
		}
		return sum;
	}
};

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi a(n);
	BIT<int> bit;
	rep(i, n) a[i] = s[i] - '0', bit.update(a[i] + 1, 1);
	vi a1 = {a[0]}, a2;
	bit.update(a[0] + 1, -1);
	int f1 = 1;
	string ans = "1";
	repn(i, 1, n){
		bit.update(a[i] + 1, -1);
		if(bit.query(a[i])){
			a2.pb(a[i]);	
			ans += '2';
		}
		else{
			if((a2.size() && a[i] < a2[(int)(a2.size()) - 1]) || (!a2.size())) a1.pb(a[i]), ans += '1';
			else a2.pb(a[i]), ans += '2';
		}
	}
	if(f1){
		int f = 1;
		repn(i, 1, a1.size()){
			if(a1[i] < a1[i - 1]){
				f = 0;
				break;
			}
		}
		rep(i, a2.size()){
			if(!i){
				if(a2[i] < a1[a1.size() - 1]){
					f = 0;
					break;
				}
			}
			else{
				if(a2[i] < a2[i - 1]){
					f = 0;
					break;
				}
			}
		}
		if(f){
			cout << ans << endl;
			return;
		}
	}
	BIT<int> bit1;
	rep(i, n) a[i] = s[i] - '0', bit1.update(a[i] + 1, 1);
	a1 = {}, a2 = {a[0]};
	bit1.update(a[0] + 1, -1);
	f1 = 1;
	ans = "2";
	repn(i, 1, n){
		bit1.update(a[i] + 1, -1);
		if(bit1.query(a[i])){
			a2.pb(a[i]);	
			ans += '2';
		}
		else{
			if((a[i] < a2[(int)(a2.size()) - 1])) a1.pb(a[i]), ans += '1';
			else a2.pb(a[i]), ans += '2';
		}
	}
	if(f1){
		int f = 1;
		repn(i, 1, a1.size()){
			if(a1[i] < a1[i - 1]){
				f = 0;
				break;
			}
		}
		rep(i, a2.size()){
			if(!i){
				if(a2[i] < a1[a1.size() - 1]){
					f = 0;
					break;
				}
			}
			else{
				if(a2[i] < a2[i - 1]){
					f = 0;
					break;
				}
			}
		}
		if(f){
			cout << ans << endl;
			return;
		}
	}
	cout << '-' << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
