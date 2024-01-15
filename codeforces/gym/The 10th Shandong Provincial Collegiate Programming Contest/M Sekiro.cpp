#include <iostream>//ac

using namespace std;

int solve(int n, int k) {
	while (k--) {
		if (n == 0 || n == 1) break;
		n = (n + 1) >> 1;
	}
	
	return n;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}
	return 0;
}