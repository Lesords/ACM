#include <iostream>//ac
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k, n, m, tmp;
		string s;
		cin >> k >> s;
		cin >> n >> m;
		for (int i = 1; i <= m ; ++i) {
			cin >> tmp >> tmp;
		}
		int res = m - (n - 1);
		if (s[res%k] == '1') cout << "2\n";
		else cout << "1\n";
	}
	return 0;
}