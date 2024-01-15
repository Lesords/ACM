#include <iostream>

using namespace std;

int main() {
	int a, b, r;
	cin >> a >> b >> r;
	r*=2;
	int ans = (a / r) * (b / r);
	if (!ans) cout << "Second\n";
	else cout << "First\n";
	return 0;
}