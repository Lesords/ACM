#include<iostream>//ac
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 2e5 + 5;
int pos[MAXN],len[MAXN];
int main() {
	int t,n,tmp;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			pos[tmp] = i;//保存位置
		}
		string ans = "1";//第一个绝对为完美数
		len[1] = 0;
		int minn,maxx;
		minn = maxx = pos[1];//初始位置为1
		for(int i = 2;i <= n;i++) {//遍历2~n排列的区间距离  
			minn = min(pos[i],minn);//保留最小的位置
			maxx = max(pos[i],maxx);//保留最大的位置
			len[i] = maxx - minn;//最大和最小位置的跨度即为距离
			if(len[i]<i) ans += '1';//距离需小于数字数量
			else ans += '0';
		}
		cout<<ans<<endl;
	}
	return 0;
}
