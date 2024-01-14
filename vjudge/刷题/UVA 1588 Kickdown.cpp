#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 999999
using namespace std;
int is_right(string a,string b,int len,bool dir) {
	for(int i = 1;i <= len;i++)//移动块前方补零
		dir?b = '0' + b:a = '0' + a;
	while(b.size()<a.size()) b += '0';//较小的块后方补零
	while(a.size()<b.size()) a += '0';
	int l_a = 0,l_b = 0;
	while(l_a<a.size()) {
		int tmp1 = a[l_a] - '0';
		int tmp2 = b[l_b] - '0';
		if(tmp1+tmp2>3) return INF;//不满足条件
		l_a++,l_b++;
	}
	return a.size();//固定块长度即为容器长度
}
int main() {
	string a,b;
	while(cin>>a>>b) {//a为底部固定块,b为上方移动块 
		int len = 0,ans = INF;
		while(len<=a.size()||len<=b.size()) {//len小于任意串
			ans = min(is_right(a,b,len,1),ans);//向右移
			ans = min(is_right(a,b,len,0),ans);//向左移！！！
			len++;//移动位数++
		}
		cout<<ans<<endl;
	}
	return 0;
} 
