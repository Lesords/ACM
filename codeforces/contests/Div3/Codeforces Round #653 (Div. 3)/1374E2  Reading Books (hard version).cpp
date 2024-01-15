#include<iostream>//ac
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：分为4个类队列，1个剩余队列，1个已使用队列
//1.判断是否有必须的both书籍，从小到大选择
//2.判断both和alice+bob哪个组合值较小直到both为空
//3.补其alice和bob所需的书籍（单独类）
//4.若所选书籍数量不满足时判断以下情况：
//5.若both小于none，alice，bob则先选择both（特判）
//6.若 已使用的both +none小于alice+bob，则选择none
//7.否则在alice，bob，none三类中选择最小的
//8.最后在所有剩余的书籍中从小到大选择还需要的书籍

const int MAXN = 2e5+10;
struct node{
	int val,index;
	friend bool operator < (node a,node b) {
		if(a.val!=b.val) return a.val > b.val;
		return a.index > b.index;
	}
};
struct node1{//已经读过的both类书
	int val,index;
	friend bool operator < (node1 a,node1 b) {
		return a.val < b.val;//大的优先
	}
};
int ans[MAXN],cost;//ans保存书号，cost为总花费值
int main() {
	int n,m,k,cnt = 0,a_num = 0,b_num = 0;
	priority_queue<node> alice,bob,both,non,rest;
	priority_queue<node1> used;
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++) {
		int t,a,b;
		cin>>t>>a>>b;
		if(a+b==2) both.push(node{t,i});
		if(a+b==0) non.push(node{t,i});
		if(a&&!b) alice.push(node{t,i});
		if(!a&&b) bob.push(node{t,i});
	}
	//both类的+单类较小值小于k即为不满条件
	if(both.size()+min(alice.size(),bob.size())<k) {
		cout<<"-1";
		return 0;
	}
	node tmp_a,tmp_b,tmp;
	if(2*k>m) {//肯定需要both的数量的情况
		if(2*k-m>both.size()) {//both数量不够
			cout<<"-1";
			return 0;
		}
		int num = 2*k-m;//num为必需的both数量
		while(num--) {
			tmp = both.top();
			both.pop();
			cost += tmp.val;//cost为总花费值
			ans[++cnt] = tmp.index;//保存书号
			a_num++,b_num++;
		}
	}
	while(a_num<k&&b_num<k) {//还是先判断both类书
		if(!both.empty()) {
			tmp_a.val = tmp_b.val = INF;//先初始化，防止某类书为空
			tmp = both.top();
			if(!alice.empty()) tmp_a = alice.top();
			if(!bob.empty()) tmp_b = bob.top();
			if(tmp.val<=tmp_a.val+tmp_b.val) {
				cost += tmp.val;//增加花费
				used.push(node1{tmp.val,tmp.index});//使用过的both类书需放入used类中
				both.pop();
				ans[++cnt] = tmp.index;//保存书号
			}
			else {//选择alice+bob组合
				bob.pop(),alice.pop();
				cost += tmp_a.val+tmp_b.val;//增加花费
				ans[++cnt] = tmp_a.index;//保存书号
				ans[++cnt] = tmp_b.index;
			}
			a_num++,b_num++;
		}
		else break;
	}
	while(a_num<k) {//补其alice需要的书
		tmp_a = alice.top();
		cost += tmp_a.val;
		ans[++cnt] = tmp_a.index;//保存书号
		a_num++;
		alice.pop();
	}
	while(b_num<k) {//补其bob需要的书
		tmp_b = bob.top();
		cost += tmp_b.val;
		ans[++cnt] = tmp_b.index;//保存书号
		b_num++;
		bob.pop();
	}
	int num = 0;//num为被删除的书的数量
	set<int> mark,del;//mark用来标记被删除的both类书籍，del用来标记已经输出的书
	if(cnt<m) {
		node1 usedd;
		while(1) {//判断both+none和alice+bob哪类的值较小
			usedd.val = tmp.val = tmp_a.val = tmp_b.val = INF;
			if(cnt-num==m) break;//所借阅的书够用时结束
			if(!alice.empty()) tmp_a = alice.top();
			if(!bob.empty()) tmp_b = bob.top();
			if(!non.empty()) tmp = non.top();
			if(!used.empty()) usedd = used.top();
			int tt = min(min(tmp_a.val,tmp_b.val),tmp.val);//取三类中最小值
			node ttmp;
			ttmp.val = INF;
			if(!both.empty()) ttmp = both.top();
			if(ttmp.val < tt) {//特判both为更小的情况！！！
				cost += ttmp.val;
				ans[++cnt] = ttmp.index;
				if(mark.count(ttmp.index)) mark.erase(ttmp.index);//去除删除标记
				both.pop();
				continue;
			}
			if(tmp.val==tt) {//none为最小时
				if(usedd.val+tt>=tmp_a.val+tmp_b.val) {//both+none大于alice+bob时
				    //删除both，然后添加alice+bob
					if(usedd.val+tt>=INF) break;//其中一个为空
					if(alice.empty()||bob.empty()||used.empty()) break;//三类中有一个为空都不行
					cost -= usedd.val;
					cost += tmp_a.val+tmp_b.val;
					ans[++cnt] = tmp_a.index;
					ans[++cnt] = tmp_b.index;
					alice.pop(),bob.pop(),used.pop();//used为使用过的both，此时需删除最大值
					both.push(node{usedd.val,usedd.index});//把删除的书放入原队列中
					mark.insert(usedd.index);//添加删除标记
					num++;
				}
				else {//添加none的情况更小
					if(non.empty()) break;
					cost += tmp.val;
					ans[++cnt] = tmp.index;
					non.pop();
				}
			}
			else {//此时需要在both和alice和bob之间判断最小值
				node tmp_both;
				tmp_both.val = INF;
				if(!both.empty()) tmp_both = both.top();//both的值
				if(tmp_a.val<=tmp_b.val&&tmp_a.val<=tmp_both.val) {//alice最小
					if(tmp_a.val==INF) break;//INF说明为空
					cost += tmp_a.val;
					ans[++cnt] = tmp_a.index;//添加对应书号及值
					alice.pop();
				}
				else if(tmp_b.val<=tmp_a.val&&tmp_b.val<=tmp_both.val) {//bob最小
					if(tmp_b.val==INF) break;//INF说明为空
					cost += tmp_b.val;
					ans[++cnt] = tmp_b.index;//添加对应书号及值
					bob.pop();
				}
				else {//both最小
					if(tmp_both.val==INF) break;//INF说明为空
					cost += tmp_both.val;
					ans[++cnt] = tmp_both.index;//添加对应书号及值
					if(mark.count(tmp_both.index)) mark.erase(tmp_both.index);//移除删除标记
					both.pop();
				}
			}
		}
		//剩余的所有书放入同一个队列中从小到大排序
		while(!both.empty()) rest.push(both.top()),both.pop();
		while(!alice.empty()) rest.push(alice.top()),alice.pop();
		while(!bob.empty()) rest.push(bob.top()),bob.pop();
		while(!non.empty()) rest.push(non.top()),non.pop();
		while(cnt-num<m) {
			tmp = rest.top();rest.pop();
			ans[++cnt] = tmp.index;
			if(mark.count(tmp.index)) mark.erase(tmp.index);//移除删除标记
			cost += tmp.val;
		}
	}
	cout<<cost<<endl;
	int flag = 0;
	for(int i = 1;i <= cnt;i++) {
		if(mark.count(ans[i])) continue;//跳过被删除的both
		if(del.count(ans[i])) continue;//跳过已经输出的书号
		if(flag) cout<<' ';
		cout<<ans[i];
		del.insert(ans[i]);//标记已输出的书号
		flag = 1;
	}
	return 0;
}
