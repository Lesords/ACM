#include<iostream>//ac
#include<string>
using namespace std;
string a[205];
int main() {
	int len = 0,cnt = 1,num = 0,op = '0';//第一个字符时判断'0'
	//洛谷评测机和数据所用的系统不一样，所以回车符也不一样
	//getline会多出一个回车符
	while(cin>>a[cnt]) {
		if(!len) len = a[cnt].size();//记录len
		cnt++;
	}
	cout<<len;//字符串长度即为所求的N
	for(int i = 1;i < cnt;i++) {//遍历所有字符串
		for(int j = 0;j < a[i].size();j++) {//遍历字符串中所有字符
			if(a[i][j]==op) num++;//如果与当前字符一致
			else {//不一致
				cout<<" "<<num;//输出num
				num = 1;//更新num（当前算一个）
				op = (op=='0')?'1':'0';//op字符为相反
			}
		}
	}
	cout<<' '<<num;//最后肯定还有一个num处于末尾未输出
	return 0;
}
