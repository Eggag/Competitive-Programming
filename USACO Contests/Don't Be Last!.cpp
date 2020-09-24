#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	freopen("notlast.in", "r", stdin);
        freopen("notlast.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, string>> milk;
	milk.pb(mp(0, "Elsie"));
	milk.pb(mp(0, "Bessie"));
	milk.pb(mp(0, "Daisy"));
	milk.pb(mp(0, "Gertie"));
	milk.pb(mp(0, "Annabelle"));
	milk.pb(mp(0, "Maggie"));
	milk.pb(mp(0, "Henrietta"));
	for(int i = 0; i < n; i++){
		string name;
		int m;
		cin >> name >> m;
		for(int a = 0; a < 7; a++){
			if(name == milk[a].s){
				milk[a].f += m;
				break;
			}
		}
	}
	sort(milk.begin(), milk.end());
	int y = 0;
	string x;
	for(int i = 0; i < 7; i++){
		if(milk[i].f > 0){
			y = milk[i].f;
			x = milk[i].s; 
			break;
		}
	}
	if(y == 0){
		cout << "Tie" << endl;
		return 0;
	}
	int count = 0;
	for(int i = 0; i < 7; i++){
		if(milk[i].f > y){
			if(milk[i + 1].f == milk[i].f){
				cout << "Tie" << endl;	
			}
			else{
				cout << milk[i].s << endl;
			}
			return 0;
		}
		if(milk[i].f == y){
			count++;
		}


	}
	if(count > 1){
		cout << "Tie" << endl;
		return 0;
	}
	cout << x << endl;	
	return 0;
}
