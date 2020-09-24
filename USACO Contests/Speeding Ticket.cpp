#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

struct seg{
	int start, finish, speed;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	int st = 0;
	vector<seg> s, s1;
	rep(i, n){
		int a, b;
		cin >> a >> b;
		s.pb({st, st + a, b});
		st = st + a;
	}
	st = 0;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		s1.pb({st, st + a, b});
		st = st + a;
	}
	repn(i, 1, 101){
		int speed1, limit;
		rep(j, n){
			if(i <= s[j].finish && i >= s[j].start){
				limit = s[j].speed;
				break;
			}
		}
		rep(j, m){
			if(i <= s1[j].finish && i >= s1[j].start){
                                speed1 = s1[j].speed;
                                break;
                        }
		}
		ans = max(ans, speed1 - limit);
	}
	cout << ans << endl;
	//rep(i, n){
	//	cout << s[i].start << " " << s[i].finish << " " << s[i].speed << endl;
	//}
	//rep(i, m){
	//	cout << s1[i].start << " " << s1[i].finish << " " << s1[i].speed << endl;
	//}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
