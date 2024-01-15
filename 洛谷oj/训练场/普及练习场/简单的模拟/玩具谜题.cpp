#include<iostream>//ac
#include<cstdio>
using namespace std;

//题解：模拟判断每次走的方向即可
//逆时针：向内+右走（0+1），向外+左走（1+0）
//顺时针：向内+左走（0+0），向外+右走（1+1）

const int MAXN = 1e5+5;
int a[MAXN];
char name[MAXN][15];//二维数组
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i]>>name[i];
	int op,step,now = 1;
	for(int i = 1;i <= m;i++) {
		cin>>op>>step;//注意a的下标为当前位置（now）！！！
		if((a[now]+op)%2) {//逆时针
			now = (now+step)%n;
			if(!now) now = n;//为0时转为n
		}
		else {//顺时针
			now -= step;
			if(now<=0) now += n;//为非正数时+n
		}
	}
	cout<<name[now]<<endl;
	return 0;
}
