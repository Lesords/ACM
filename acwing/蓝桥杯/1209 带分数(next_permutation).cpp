#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[10],ans,n;
int get_val(int left,int right) {//计算指定范围内的值
	int ans = 0;
	for(int i = left;i <= right;i++) ans = ans*10+a[i];
	return ans;
}
int main() {
	cin>>n;
	for(int i = 1;i <= 9;i++) a[i] = i;//next_permutation需有序，故初始化升序
	do {
		int flag = 0;
		for(int i = 1;i <= 7;i++) {//第一个数
			for(int j = i+1;j <= 8;j++) {//第二个数
				int A = get_val(1,i);
				int B = get_val(i+1,j);
				int C = get_val(j+1,9);//计算三个数的值
				if(n*C==A*C+B) {//判断是否满足条件
					flag = 1;ans++;break;
				}
			}
			if(flag) break;//满足条件则跳过
		}
	} while(next_permutation(a+1,a+10));//继续下一个排列
	cout<<ans<<endl;
	return 0;
}
