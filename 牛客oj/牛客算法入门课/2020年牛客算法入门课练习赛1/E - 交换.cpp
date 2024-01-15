#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int ans,a[MAXN],b[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i],b[i]=a[i];
	sort(a+1,a+1+n);//排序后的位置为目的顺序
	for(int i = 1;i <= n;i++) {
		if(b[i]!=a[i]) {//目的位置不为当前人
			for(int j = i+1;j <= n;j++) {//找人并交换
				if(b[j]==a[i]) {//不限制交换的位置
					swap(b[i],b[j]),ans++;//ans++
					break;//tle！！！
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
