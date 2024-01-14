#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int solve(int val,int level,int w) {
	//根据值和行计算列的位置
	//奇数行从左到右，偶数行从右到左
	if(level%2) return val-(level-1)*w;//下标从1开始
	return w-(val-(level-1)*w-1);//从w开始，记得-1！！！
}
int main() {
	int w,m,n,m_level,n_level,m_pos,n_pos;
	cin>>w>>m>>n;
	m_level = ceil(m*1.0/w);//向上取整，计算行数
	n_level = ceil(n*1.0/w);
	int dis = max(m_level,n_level)-min(m_level,n_level);//行差
	n_pos = solve(n,n_level,w);
	m_pos = solve(m,m_level,w);
	cout<<dis+abs(n_pos-m_pos);//行差+列差即为答案
	return 0;
}
