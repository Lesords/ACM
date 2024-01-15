#include <iostream> //ac
#include <algorithm>

using namespace std;

#define ll long long

const int MAXN = 1e5+10;

int a[MAXN];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, avg = 0;
		ll sum = 0, plus = 0, minus = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		avg = sum / n;
		sort (a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; ++i) {
			if (a[i] > avg) {
				minus += a[i] - avg;
			} else if (a[i] < avg) {
				plus += avg - a[i];
			}
		}
		if (minus >= plus) {
			cout << minus << "\n";
		} else {
			cout << minus + (minus - plus) << "\n";
		}
	}
	return 0;
}