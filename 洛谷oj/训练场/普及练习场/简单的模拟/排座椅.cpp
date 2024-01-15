#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int num,time;//num为编号，time为次数
	friend bool operator < (node a,node b) {
		return a.time > b.time;//从大到小排序
	}
}col[1005],row[1005];
int ans_c[1005],ans_r[1005];//用来保存结果
int main() {
	int m,n,k,l,d;
	memset(col,0,sizeof(col));//初始化
	memset(row,0,sizeof(row));
	cin>>m>>n>>k>>l>>d;
	int x1,y1,x2,y2;
	for(int i = 1;i <= d;i++) {
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2) {//行相同（取列）
			int minn = min(y1,y2);
			col[minn].num = minn;//保存较小值
			col[minn].time++;//次数++
		}
		else {
			int minn = min(x1,x2);
			row[minn].num = minn;
			row[minn].time++;
		}
	}
	sort(col+1,col+1005);//结构体排序
	sort(row+1,row+1005);
	for(int i = 1;i <= k;i++) {//保存编号
		ans_r[i] = row[i].num;//行结果
	}
	for(int i = 1;i <= l;i++) {
		ans_c[i] = col[i].num;//列结果
	}
	//输出结果需为字典序！！！
	sort(ans_r+1,ans_r+k+1);//字典序（从小到大）
	sort(ans_c+1,ans_c+l+1);
	for(int i = 1;i <= k;i++) {//输出结果
		if(i!=1) cout<<' ';
		cout<<ans_r[i];
	}
	cout<<endl;
	for(int i = 1;i <= l;i++) {
		if(i!=1) cout<<' ';
		cout<<ans_c[i];
	}
	cout<<endl;
	return 0;
}
