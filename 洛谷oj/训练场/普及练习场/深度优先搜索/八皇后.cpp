#include<iostream>//ac
#include<cstring>
using namespace std;
int n,book[20],a[20],ans;
int to_right[30],to_left[30];//正斜线，反斜线
//正斜线：左上角到右下角    （坐标差）
//反斜线：右上角到左下角    （坐标和）
void dfs(int step) {//step表示当前行
	if(step>n) {
		ans++;//次数++
		if(ans<=3){
			for(int i = 1;i <= n;i++) {
				if(i!=1) cout<<' ';
				cout<<a[i];
			}
			cout<<endl;
		}
		return;
	}
	for(int i = 1;i <= n;i++) {//表示选择哪一列
		//三个方向有一个标记时，跳过
		if(book[i]||to_left[step+i]||to_right[i-step+n]) continue;
		book[i]++;//竖直方向标记
		to_right[i-step+n]++;//正斜线的标记点为 坐标差（+n避免负号）
		to_left[step+i]++;//反斜线的标记点为 坐标和
		a[step] = i;
		dfs(step+1);
		book[i]--;//清除对应标记
		to_right[i-step+n]--;
		to_left[step+i]--;
	}
}
int main() {
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
