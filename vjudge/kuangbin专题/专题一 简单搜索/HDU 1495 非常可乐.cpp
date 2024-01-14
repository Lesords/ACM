#include<iostream>//ac
#include<queue>
#include<set>
#include<utility>
#include<algorithm>
#define INF 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
struct node{
    int a[3],step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//优先次数少的
    }
};
int c[3];//记录三个杯子的容量
bool check(node val) {
    sort(val.a,val.a+3);//将杯子排序
    //若最小的为空，且其他两个值相同即为满足条件
    if(val.a[0]==0&&val.a[1]==val.a[2]) return 1;
    return 0;
}
int main() {
    while(cin>>c[0]>>c[1]>>c[2]&&c[0]+c[1]+c[2]) {
        priority_queue<node> q;
        set<pii > st;//标记两个杯子的量即可，因为第三个量是固定的
        node tmp = {c[0],0,0,0};//初始化只有第一个有水
        q.push(tmp);
        int ans = INF;
        while(!q.empty()) {
            node tmp = q.top();q.pop();
            pii vis = {tmp.a[0],tmp.a[1]};
            if(st.count(vis)) continue;//跳过已标记的
            else st.insert(vis);
            if(check(tmp)) {//若满足条件则更新答案
                ans = tmp.step;break;
            }
            for(int i = 0;i < 3;i++) {//i杯的水倒在j杯里
                for(int j = 0;j < 3;j++) {//总共六个方向（倒水）
                    if(i==j||tmp.a[i]==0) continue;//相同的或者i没水则跳过
                    node now = tmp;
                    int sum = now.a[i]+now.a[j];//总和
                    now.a[j] = min(sum,c[j]);//不能超过j的容量！！！
                    now.a[i] = sum-now.a[j];//i为剩下的
                    now.step++;//次数++
                    q.push(now);
                }
            }
        }
        if(ans==INF) cout<<"NO\n";//无解的时候
        else cout<<ans<<"\n";
    }
    return 0;
}
