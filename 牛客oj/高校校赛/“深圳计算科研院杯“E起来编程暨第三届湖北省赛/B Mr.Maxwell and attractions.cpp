#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

//题解：贪心+优先队列
//建立两个优先队列分别存储户外和户内的风景，大根堆
//由于题目需要在早上工作的天数至少为k天
//那么也就是说，下午去参观的天数至少需要k天
//那么可以分成两个情况：
//必须选择下午，不一定要选择下午
//由于室内的下午参观不受影响，所以室内的全部下午参观！！！

const int MAXN = 1e5+5;
double a[MAXN],b[MAXN];
int main() {
    int n,m,t,k;
    cin>>n>>m>>t>>k;
    priority_queue<double> indoor,outdoor;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        indoor.push(a[i]);
    }
    for(int i = 1;i <= m;i++) {
        cin>>b[i];
        outdoor.push(b[i]);//0.8
    }
    double ans = 0;
    for(int i = 1;i <= t;i++) {//总共t天
        double in = indoor.top();
        double out = outdoor.top();
        if(i+k<=t) {//今天不一定需要下午去
            if(in>=out) {//室内的价值更大
                ans += in;
                indoor.pop();//弹出旧的，添加新的
                indoor.push(in*0.6);
                k--;//室内的，下午去
            }
            else {
                ans += out;
                outdoor.pop();//弹出旧的，添加新的
                outdoor.push(out*0.6);
            }
        }
        else {//必须下午去
            k--;
            if(in>=out*0.8) {//室外的需要乘0.8！！！
                ans += in;
                indoor.pop();//弹出旧的，添加新的
                indoor.push(in*0.6);
            }
            else {
                ans += out*0.8;
                outdoor.pop();//弹出旧的，添加新的
                outdoor.push(out*0.6);//白天恢复原价，所以只需要*0.6
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}
