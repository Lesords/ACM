#include<iostream>//ac
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：建立三个优先队列，分别为11,10,01三种情况
//先判断11的队列是否满足小于10,01两者和
//然后继续判断10,01两个队列即可

int main() {
	int n,k,t,a,b;
	priority_queue<int,vector<int>,greater<int> > alice;
	priority_queue<int,vector<int>,greater<int> > bob;
	priority_queue<int,vector<int>,greater<int> > both;
	cin>>n>>k;
	while(n--) {
		cin>>t>>a>>b;
		if(a&&b) both.push(t);          //11情况
		else if(a&&!b) alice.push(t);   //10情况
		else if(!a&&b) bob.push(t);     //01情况
	}
	int ans = 0,num_a = 0,num_b = 0,flag = 0;
	while(num_a<k&&num_b<k) {
		if(!both.empty()) {//先判断11的队列
			int tmp_a = INF,tmp_b = INF;//初始化为INF，防止队列为空
			if(!alice.empty()) tmp_a = alice.top();
			if(!bob.empty()) tmp_b = bob.top();
			if(both.top()<=tmp_a+tmp_b) {//小于其他两个队列的和
				ans += both.top();
				both.pop();//弹出
			}
			else {//否则选其他两个队列
				ans += tmp_a+tmp_b;
				alice.pop(),bob.pop();//弹出
			}
			num_a++,num_b++;
		}
		else break;
	}
	while(num_a<k) {//再判断Alice是否满足条件
		if(alice.empty()) {//为空说明无结果
			flag = 1;break;
		}
		ans += alice.top();
		alice.pop(),num_a++;
	}
	while(!flag&&num_b<k) {//判断Bob是否满足条件
		if(bob.empty()) {//为空说明无结果
			flag = 1;break;
		}
		ans += bob.top();
		bob.pop(),num_b++;
	}
	if(flag) cout<<"-1";//无结果输出-1
	else cout<<ans;
	return 0;
}
