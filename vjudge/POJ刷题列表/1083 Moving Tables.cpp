#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
int book[205],s[205],e[205];

//题解：由于每个椅子都需要移动，那么只需要判断所有房间移动后
//交叉的路线有多少次即可，因为交叉的地方必须都要移动特定椅子

 
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans = 0;
		memset(book,0,sizeof(book));//初始化标记数组
		for(int i = 1;i <= n;i++) {
			cin>>s[i]>>e[i];
			if(s[i]%2) s[i]++;//转成下方房间号（偶数）
			if(e[i]%2) e[i]++;
			s[i] /= 2, e[i] /= 2;//除2即为列号
			if(s[i]>e[i]) swap(s[i],e[i]);//不确定大小
			for(int j = s[i];j <= e[i];j++) book[j]++;//标记路线
		}
		for(int i = 1;i <= 200;i++) {
			ans = max(ans,book[i]);//寻找交叉路线最多的一次
		}
		cout<<ans*10<<endl;
	}
	return 0;
}
