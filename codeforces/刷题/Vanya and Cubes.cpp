#include<iostream>//ac
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		int sum = 0,cnt = 0,floor = 0;
		while(sum<=n) {
			cnt++;//层数++
			floor += cnt;//每层的个数
			sum += floor;//全部个数
		}
		cout<<--cnt<<endl;//减去多余的一层
	}
	return 0;
}
