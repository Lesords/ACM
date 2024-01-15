#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：将原数据转换为对应数字出现的次数
//然后逐个放入优先队列中，每次取两个较大值的 -1
//判断对应数字是否还存在，存在则继续入队列
//由于所有数字出现的次数总共为 2e5 次，所以一个个删除不会超时！！！

const int MAXN = 2e5+5;
int a[MAXN];//记录原数据
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        map<int,int> num;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[a[i]]++;//更新对应数字的数量
        }
        priority_queue<int> q;//优先队列（大顶堆）
        for(auto tmp:num) {
            q.push(tmp.se);//将出现次数入队列
        }
        int ans = n;//ans表示剩余数字，初始时有n个
        while(q.size()>=2) {//队列中有两个不同的数字才可以继续操作
            int one = q.top();q.pop();
            int two = q.top();q.pop();//取前两个较多的数字
            --one,--two;//分别少1
            ans -= 2;//总的少2 对应数量的操作
            if(one) {//对应数量还有，则继续入队列
                q.push(one);
            }
            if(two) {
                q.push(two);
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
