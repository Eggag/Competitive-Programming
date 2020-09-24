#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<string> c[100];

int ccmp(int x, int y){
	int count = 0;
	vector<string> &v1 = c[x];
	vector<string> &v2 = c[y];
	for(int i = 0; i < v1.size(); i++){
		for(int j = 0; j < v2.size(); j++){
			if(v1[i] == v2[j]){
				count++;
			}
		}
	}
	return count;
}

int main(){
	freopen("guess.in", "r", stdin);
        freopen("guess.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s; 
		int k;
		cin >> s >> k;
		for(int j = 0; j < k; j++){
			string g;
			cin >> g;
			c[i].pb(g);
		}
	}
	int largest = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			largest = max(largest, ccmp(i, j));
		}
	}
	cout << largest + 1 << endl;
	return 0;
}
