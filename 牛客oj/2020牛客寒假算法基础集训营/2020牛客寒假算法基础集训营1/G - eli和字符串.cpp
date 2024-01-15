#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 2e5 + 5;
int num[28],pos[28][MAXN];
//num保存对应字符数量
//pos[i][j]表示为 i 字符的第 j 个的位置
int main() {
	int n,k;
	int ans = INF;//初始化为无限大（求最小）
	string a;
	cin>>n>>k>>a;
	for(int i = 0;i < a.size();i++) {//遍历字符串a
		int tmp = a[i]-'a';
		num[tmp]++;//当前字符数量++
		pos[tmp][num[tmp]] = i;//记录位置
		//tmp字符的第num[tmp]个的位置为i
		if(num[tmp]>=k) {//数量达到标准时
			int dis = i - pos[tmp][num[tmp]-k+1] + 1;
			//当前位置 - 往左（k-1）的位置 + 1
			//dis为满足k个tmp字符的长度
			ans = min(ans,dis);//更新最小值
		}
	}
	cout<<(ans==INF?(-1):ans);
	return 0;
}
