#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

set<int> s[100005];

bool used[100005];

int c[100005];

vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		s[x].insert(y);
		s[y].insert(x);
	}
	for(int i = 1; i <= n; i++){
		if(s[i].size() == 1){
			v.pb(i);
			used[i] = true;
		}
	}
	while(k >= 1){
		if(v.empty()){
			cout << "No" << endl;
			return 0;
		}
		vector<int> nv;
		for(int x: v){
			int y = *s[x].begin();
			c[y]++;
			s[x].erase(y);
			s[y].erase(x);
			if(used[y] == false){
				used[y] = true;
				nv.pb(y);	
			}	
		}
		for(int x : nv){
			if(c[x] < 3 || s[x].size() != min(1, k - 1)){
				cout << "No" << endl;
				return 0;
			}
		}
		v = nv;
		k--;
	}
	cout << "Yes" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
