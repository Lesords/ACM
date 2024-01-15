#include<iostream>//ac
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int q,op,k;
	while(cin>>q) {//多组输入
		stack<string> sta;//存放历史字符串
		string ans,tmp;
		while(q--) {
			cin>>op;
			//恢复为前一个字符串，并弹出对应字符串
			if(op==4) ans = sta.top(),sta.pop();
			else {
				if(op==3) {
					cin>>k;
					//下标从0开始，故-1
					cout<<ans[k-1]<<"\n";
				}
				else if(op==1) {
					cin>>tmp;
					sta.push(ans);//更新历史字符串
					ans += tmp;
				}
				else if(op==2) {
					cin>>k;
					sta.push(ans);//更新历史字符串
					//删除字符串后k个字符
					ans.erase(ans.size()-k,k);
					//erase函数第一个参数表示起点，第二个为个数
				}
			}
		}
	}
	return 0;
}
