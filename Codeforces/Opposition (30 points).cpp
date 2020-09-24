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
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int t;
	cin >> t;
	assert(t == 1);
	int cnt = 0;
	vi ove, lve, loe, lov;
	rep(i, s.size() - 3){
		string s1 = s.substr(i, 4);
		if(s1 == "?OVE") ove.pb(i);
		if(s1 == "L?VE") lve.pb(i);
		if(s1 == "LO?E") loe.pb(i);
		if(s1 == "LOV?") lov.pb(i);
	}
	unordered_set<int> pos;
	int cnt1 = 0;
	rep(i, n) if(s[i] == '?') pos.insert(i), cnt1++;
	while(cnt1--){
		cnt++;
		if(cnt % 2 == 1){
			int f = 0;
			while(true && !f){
				if(!ove.size()) break;	
				int ind = (int)ove.size() - 1;
				if(s[ove[ind]] == '?' && (pos.find(ove[ind]) != pos.end())){
					assert(pos.find(ove[ind]) != pos.end());
					pos.erase(ove[ind]);
					cout << ove[ind] + 1 << " " << "L" << endl;
					ove.pop_back();
					f = 1;
					break;
				}
				else ove.pop_back();
			}
			while(true && !f){
				if(!lve.size()) break;	
				int ind = (int)lve.size() - 1;
				if(s[lve[ind] + 1] == '?' && (pos.find(lve[ind] + 1) != pos.end())){
					assert(pos.find(lve[ind] + 1) != pos.end());
					pos.erase(lve[ind] + 1);
					cout << lve[ind] + 2 << " " << "O" << endl;
					lve.pop_back();
					f = 1;
					break;
				}
				else lve.pop_back();
			}
			while(true && !f){
				if(!loe.size()) break;	
				int ind = (int)loe.size() - 1;
				if(s[loe[ind] + 2] == '?' && (pos.find(loe[ind] + 2) != pos.end())){
					assert(pos.find(loe[ind] + 2) != pos.end());
					pos.erase(loe[ind] + 2);
					cout << loe[ind] + 3 << " " << "V" << endl;
					loe.pop_back();
					f = 1;
					break;
				}
				else loe.pop_back();
			}
			while(true && !f){
				if(!lov.size()) break;	
				int ind = (int)lov.size() - 1;
				if(s[lov[ind] + 3] == '?' && pos.find(lov[ind] + 3) != pos.end()){
					assert(pos.find(lov[ind] + 3) != pos.end());
					pos.erase(lov[ind] + 3);
					cout << lov[ind] + 4 << " " << "E" << endl;
					lov.pop_back();
					f = 1;
					break;
				}
				else lov.pop_back();
			}
			if(f) continue;
			if(!pos.size()) break;
			cout << *pos.begin() + 1 << " " << "L" << endl;
			pos.erase(*pos.begin());
		}
		else{
			int p;
			char c;
			cin >> p >> c;
			s[p - 1] = c;
			assert(pos.find(p - 1) != pos.end());
			pos.erase(p - 1);
		}
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
