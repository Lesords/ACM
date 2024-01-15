#include<iostream>//ac
#include<set>
//解法1：遍历整个字符串，逐个修改，判断是否有重合（数据多的时候）
//解法2：由于最多只有10个字符串，所以字符串第一个位置遍历0~9即可
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		set<string> s;
		cin>>n;
		string a[12];
		for(int i = 1;i <= n;i++) {
			cin>>a[i];
			s.insert(a[i]);
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j < i;j++) {//遍历字符串判断是否有一致的
				if(a[i]==a[j]) {
					ans++;//最小步就是每个字符串只改一个字符
					string tmp = a[i];//tmp用于临时修改
					int flag = 0;
					for(int k = 0;k < tmp.size()&&!flag;k++) {
						for(char c = '0';c <= '9';c++) {
							char t = tmp[k];//保存初始字符
							tmp[k] = c;
							if(!s.count(tmp)) {//修改成功
								flag = 1;
								a[i] = tmp;//更新原字符串组
								s.insert(tmp);//集合内插入新字符串
								break;
							}
							tmp[k] = t;//修改失败需还原
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i = 1;i <= n;i++)
			cout<<a[i]<<endl;
	}
	return 0;
}
