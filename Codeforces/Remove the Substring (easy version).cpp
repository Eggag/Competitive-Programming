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
	string s, t;
	cin >> s >> t;
	//find all subs that are equal to t
	//look right and left, update answer
	int ans = 0;
	//rep(i, (int)((s.size() - t.size())) + 1) if(s[i] == t[0]){
	//	//start from i
	//	int ind = i + 1, cnt = 1;
	//	while((ind < ((int)s.size())) && (cnt < ((int)t.size()))){
	//		if(s[ind] == t[cnt]) cnt++;
	//		ind++;
	//	}
	//	if(cnt == (int)t.size()){
	//		ans = max(ans, max((int)((int)(s.size() - ind)), i));
	//	}
	//}
	rep(i, s.size()){
		repn(j, i, s.size()){
			int cnt = 0;
			rep(k, s.size()){
				if(k < i || k > j){
					if(s[k] == t[cnt]) cnt++;
				}	
				if(cnt == (int)(t.size())){
					ans = max(ans, (j - i + 1));
					break;
				}
			}
		}
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
