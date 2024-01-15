#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll getNums(ll y, ll m, ll d) {
	return y * 12 * 30 +  (m - 1) * 30 + d;
}

ll llabs(ll a, ll b) {
	if (a > b) return a - b;
	return b - a;
}

int getDay(string s) {
	if (s == "Monday") {
		return 0;
	} else if (s == "Tuesday") {
		return 1;
	} else if (s == "Wednesday") {
		return 2;
	} else if (s == "Thursday") {
		return 3;
	} else if (s == "Friday") {
		return 4;
	}
}

string getDayName(int i) {
	if (i == 0) {
		return "Monday";
	} else if (i == 1) {
		return "Tuesday";
	} else if (i == 2) {
		return "Wednesday";
	} else if (i == 3) {
		return "Thursday";
	} else if (i == 4) {
		return "Friday";
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll y, m, d;
		string s;
		ll days = 0;
		cin >> y >> m >> d >> s;
		days = getNums(y, m, d);
		cin >> y >> m >> d;
		ll days2 = getNums(y, m, d);
		ll ans = 0;
		if (days2 > days) {
			ans = (days2 - days) % 5;
			ans = (ans + getDay(s)) % 5;
		} else {
			ans = (days - days2) % 5;
			ans = (getDay(s) - ans + 5) % 5;
		}
		cout << getDayName(ans) << "\n";
	}
	return 0;
}