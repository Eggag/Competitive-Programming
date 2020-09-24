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

set<int> amount;
vi b1, b2;

void dfs(int d, int a){
	if(d == 6){
		amount.insert(a);
		return;
	}
	if(d % 2 == 0){
		//Takes away
		for(int i = 0; i < b1.size(); i++){
			int g = b1[i];
			b1.erase(b1.begin() + i);
			b2.pb(g);
			dfs(d + 1, a - g);
			b1.insert(b1.begin() + i, 1, g);
			b2.pop_back();
		}
	}
	else{
		//Brings in
		for(int i = 0; i < b2.size(); i++){
			int h = b2[i];
			b2.erase(b2.begin() + i);
			b1.pb(h);
			dfs(d + 1, a + h);
			b1.pop_back();
			b2.insert(b2.begin() + i, 1, h);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("backforth.in", "r", stdin);
        freopen("backforth.out", "w", stdout);
	for(int i = 0; i < 10; i++){
		int y;
		cin >> y;
		b1.pb(y);
	}
	for(int i = 0; i < 10; i++){
		int x;
		cin >> x;
		b2.pb(x);
	}
	dfs(2, 1000);
	cout << amount.size() << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
