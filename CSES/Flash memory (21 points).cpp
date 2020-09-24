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

int b, m;

void encode(){
	string state, val;
	cin >> state >> val;
	int n = state.size();
	int n1 = val.size();
	int f = 1;
	rep(i, n) if(state[i] == '1'){
		f = 0;
		break;
	}
	if(f){
		//deal with the clear string separately
		repn(i, n - n1, n) state[i] = val[i - (n - n1)];
		state[n - n1 - 1] = '1';
	}
	else{
		int cnt = 0;
		int st = 0;
		for(int i = n - 1; i >= 0; i--){
			cnt++;
			if(cnt == (m + 1)){
				if(state[i] == '0'){
					st = i + m;
					break;
				}
				cnt = 0;
			}
		}
		int f1 = 1;
		for(int i = st; i >= 0; i--) if(state[i] == '1'){
			f1 = 0;
			break;
		}
		if(!f1){
			cout << 0 << endl;
			return;
		}
		else{
			//we can just put it there
			int sz = st + 1;
			if(sz < (m + 1)){
				//not enough room
				cout << 0 << endl;
				return;
			}
			//add one more
			int nm = 0;
			repn(i, st - m + 1, st + 1){
				state[i] = val[nm];
				nm++;
			}
			state[st - m] = '1'; //the separator
		}
	}
	cout << 1 << "\n" << state << endl;
}

void decode(){
	string state;
	cin >> state;
	int n = state.size();
	int cnt = 0;
	int lst = 0;
	for(int i = n - 1; i >= 0; i--){
		cnt++;
		if(cnt == (m + 1)){
			if(state[i] == '0'){
				cout << state.substr(i + 1 + m + 1, m) << endl;
				return;
			}
			else{
				lst = i + 1;
			}
			cnt = 0;
		}
	}
	cout << state.substr(lst, m) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	//t == 0 -> encode
	//else -> decode
	cin >> b >> m;
	//this problem is kinda weird and takes a while to get
	//but it is very nice
	while(true){
		int c;
		cin >> c;
		if(!c) return 0;
		if(!t) encode();
		else decode();
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
