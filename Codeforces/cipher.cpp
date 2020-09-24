#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int size;
	cin >> size;
	string word;
	cin >> word;
	string ans;
	int c = 0;
	int a = 1;
	while(c < size){
		ans.push_back(word[c]);
		c += a;
		a++;
	}
	cout << ans << endl;
	return 0;
}
