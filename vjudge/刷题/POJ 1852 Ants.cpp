#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：每个蚂蚁碰到后往回走，其实等于另一只到尽头的距离
//两个蚂蚁碰到所走的长度为 距离差/2
//然后继续反向走的距离 + 距离差/2 刚好为另一只蚂蚁到尽头的距离
//所以蚂蚁碰到反向走相当于交叉走的路径（换成对方走）

int main() {
	int t,n,m,tmp;
	scanf("%d",&t);
	while(t--) {
		int minn = 0,maxx = 0;
		scanf("%d%d",&n,&m);
		while(m--) {
			scanf("%d",&tmp);
			//minn求所有蚂蚁都掉下去的最短时间
			minn = max(minn,min(tmp,n-tmp));
			maxx = max(maxx,max(tmp,n-tmp));
		}
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}
