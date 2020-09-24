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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vi mx(k, 0);
	rep(i, s.size()) mx[i % k] = max(mx[i % k], s[i] - '0');
	string s1 = "";
	rep(i, n) s1 += '0';
	rep(i, k) s1[i] = s[i];
	int f = 1;
	rep(i, n){
		if(s[i] < s1[i % k]){
			f = 1;
			break;
		}
		else if(s[i] > s1[i % k]){
			f = 0;
			break;
		}
	}
	if(f){
		cout << n << endl;
		rep(i, n) cout << s1[i % k];
		cout << endl;
		return 0;
	}
	int f1 = 1;
	rep(i, k) if(mx[i] > (s1[i] - '0')) f1 = 0;
	if(!f1){
		for(int i = k - 1; i >= 0; i--){
			if(s1[i] != '9'){
				s1[i]++;
				repn(j, i + 1, k){
					assert(s1[j] == '9');
					s1[j] = '0';
				}
				break;
			}
		}
	}
	repn(i, k, n) s1[i] = s1[i - k];
	cout << s1.size() << endl;
	cout << s1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
