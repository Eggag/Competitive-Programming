#include <bits/stdc++.h>
#define long long ll;
using namespace std;


int main(){
	string word, ans;
	cin >> word;
	vector<char> vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	for(int i = 0; i < word.size(); i++){
		if(find(vowels.begin(), vowels.end(), word[i]) == vowels.end()){
			ans.push_back('.');
			ans.push_back(word[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
