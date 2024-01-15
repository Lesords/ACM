#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：哈希表 + 拉链法解决哈希冲突

const int MAXN = 5e4+5;
const int MOD = 9999991;//质数
int a[MAXN],h[MOD+100],nextt[MAXN],val[MAXN],id;
//h为对应哈希值指向的第一个编号，nextt为下一个编号，val为当前编号的值
bool check(int tmp) {
    //由于tmp有负数，所以需要多模
    int num = (tmp%MOD+MOD)%MOD,hu;
    hu = num;//记录原哈希值
    num = h[num];//第一个编号
    while(num) {//编号存在
        if(val[num]==tmp) return false;//tmp值存在，则不满足条件
        num = nextt[num];//移到下一个编号
    }
    //若tmp不存在，则建立新的编号
    nextt[++id] = h[hu];//头插法
    h[hu] = id;//更新hu的第一个编号
    val[id] = tmp;//记录id的值！！！
    return true;
}
int main() {
    ios::sync_with_stdio(0);//加速
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(val,0,sizeof(val));//初始化三个数组为0
        memset(h,0,sizeof(h));
        memset(nextt,0,sizeof(nextt));
        id = 0;//初始化id为0
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(check(a[i])) cout<<a[i]<<" ";//没有存在则输出
        }
        cout<<"\n";
    }
    return 0;
}
