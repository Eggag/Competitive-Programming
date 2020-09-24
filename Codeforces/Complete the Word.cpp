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
	int n = s.size();
	if((int)s.size() < 26){
		cout << -1 << endl;
		return 0;
	}
	vi cnt(30, 0);
	int q = 0;
	int num = 0;
	rep(i, 26){
		if(s[i] == '?') q++;
		else{
			int cur = s[i] - 'A';
			if(!cnt[cur]) num++;
			cnt[cur]++;
		}
	}
	if((num + q) == 26){
		vector<char> ch;
		rep(k, 26){
			if(!cnt[k]) ch.pb((char)('A' + k));
		}
		reverse(all(ch));
		rep(k, 26){
			if(s[k] == '?'){
				assert(ch.size());
				s[k] = ch[(int)ch.size() - 1];
				ch.pop_back();
			}
		}
		assert(!ch.size());
		rep(k, n) if(s[k] == '?') s[k] = 'A';
		cout << s << endl;
		return 0;
	}
	repn(i, 26, s.size()){
		//add
		if(s[i] == '?') q++;
		else{
			int cur = s[i] - 'A';
			if(!cnt[cur]) num++;
			cnt[cur]++;
		}
		//subtract
		int j = i - 26;
		if(s[j] == '?') q--;
		else{
			int nm = s[j] - 'A';
			if(cnt[nm] == 1) num--;
			cnt[nm]--;
			assert(cnt[nm] >= 0);
		}
		if((num + q) == 26){
			vector<char> ch;
			rep(k, 26){
				if(!cnt[k]) ch.pb((char)('A' + k));
			}
			reverse(all(ch));
			repn(k, i - 26 + 1, i + 1){
				if(s[k] == '?'){
					assert(ch.size());
					s[k] = ch[(int)ch.size() - 1];
					ch.pop_back();
				}
			}
			assert(!ch.size());
			rep(k, n) if(s[k] == '?') s[k] = 'A';
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
