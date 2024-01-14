#include<iostream> //ac
#include<string>
#include<set>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
set<pii> st;
int nextt[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int main() {
	string s;
	cin >> s;
	int x = 0, y = 0;
	st.insert({x, y});
	for(int i = 0;i < s.size();i++) {
		if(s[i] == 'L') y--;
		if(s[i] == 'R') y++;
		if(s[i] == 'U') x--;
		if(s[i] == 'D') x++;
		if(st.find({x, y}) != st.end()) {
			cout << "NO\n";
			return 0;
		}
		st.insert({x, y});
		int cnt = 0;
		for(int j = 0;j < 4;j++) {
			int tx = x + nextt[j][0];
			int ty = y + nextt[j][1];
			if(st.find({tx, ty}) != st.end()) cnt++;
		}
		if(cnt >= 2) { // 有相邻的也不行
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}