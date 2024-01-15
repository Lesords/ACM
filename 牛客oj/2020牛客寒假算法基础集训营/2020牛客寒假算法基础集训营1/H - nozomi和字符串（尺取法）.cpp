#include<iostream>//ac
#include<algorithm>
#include<string>
using namespace std;
int vis[2];//标记 0 和 1 的数量
int main() {
	int n,k;
	string a;
	cin>>n>>k>>a;
	int num = 0,ans = 0;//初始化为0
	//i为左区间，j为右区间
	for(int i = 0,j = 0;j < a.size();j++) {//j为当前移动的指针
		vis[a[j]-'0']++;//标记当前的字符
		num = max(vis[1],vis[0]);//更新字符数较多的数量
		while(j-i+1-num>k) {//需要操作的数量大于k时移动i
			vis[a[i++]-'0']--;
		}//删除左指针指向的字符的标记，并右移i
		ans = max(ans,j-i+1);//更新最大结果
	}
	cout<<ans<<endl;
	return 0;
}
