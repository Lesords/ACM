#include<iostream>//ac
#include<algorithm>
using namespace std;

//题意：在n-1个操作之后（每个位置只能操作一次），输出字典序最小的序列
//题解：确定一个地址pos变量，寻找 未确定区间 内的最小数字
//将其移动到 未确定区间 的最左端，更新pos到最小数字处（从左至此都已操作过）
//如果最小数字为当前位置则，pos++

int a[105];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		int pos = 1;
		while(pos <= n) {
			int in = min_element(a+pos,a+n+1) - a;//求极小值下标
			if(pos == in) {//最小位置为当前位置
				pos++;continue;
			}
			int t = a[in];//临时存储最小值
			for(int i = in;i >= pos + 1;i--) a[i] = a[i-1];//序列整体右移
			a[pos] = t;//更新最左值
			pos = in;//更新位置（当前位置还可操作）
		}
		for(int i = 1;i <= n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}
