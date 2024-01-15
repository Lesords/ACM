#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题意:给定两个字符串a,b。判断a串在交换字符后是否可以小于b串
//题解:当前字符往后扫，寻找一个较靠后的值小字符，然后交换

string a,b;
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		int len = a.size() - 1;
		for(int i = 0;i <= len;i++) {
			int equal = i;
			for(int j = i + 1;j <= len;j++) {//尽可能找到靠后的字符
				if(a[j] <= a[equal]&&a[j] != a[i]) {
					equal = j;
				}
			}
			/*也可直接从后面开始查找
			for(int j = len;j > i;j--) {
				if(a[j] < a[equal]) {
					equal = j;
				}
			}
			*/
			if(equal != i) {//存在就交换
				swap(a[i],a[equal]);
				break;
			}
		}
		if(a<b) cout<<a<<endl;
		else cout<<"---"<<endl;
	}
	return 0;
}
