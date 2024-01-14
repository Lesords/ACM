#include<iostream>//ac
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int val,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//步数少的优先
    }
};
int n,m,val[5];//val记录当前数字所有位置的值
bool check(int val) {//判断val是否为素数
    for(int i = 2;i*i <= val;i++) {
        if(val%i==0) return 1;
    }
    return 0;
}
int main() {
    set<int> prime;
    for(int i = 1000;i <= 9999;i++) {//先筛四位数的所有素数
        if(check(i)) continue;
        prime.insert(i);
    }
    int t;cin>>t;
    while(t--) {
        cin>>n>>m;
        set<int> vis;//vis判断当前数是否经历过
        priority_queue<node> q;
        node tmp;
        tmp = {n,0};//初始起点
        q.push(tmp);
        int flag = 0;
        while(!q.empty()) {
            tmp = q.top();q.pop();
            if(vis.count(tmp.val)) continue;//跳过已经历过的
            else vis.insert(tmp.val);//否则标记
            if(tmp.val==m) {//满足条件时
                cout<<tmp.step<<"\n";
                flag = 1;break;
            }
            int ttt = tmp.val,pos = 1;
            while(ttt) {
                val[pos++] = ttt%10;
                ttt /= 10;
            }//val保存各个位置上的值，1为低位，4为高位
            for(int i = 0;i <= 9;i++) {//替换的值为0~9
                int wei = 1;//wei表示对应替换位置的值
                for(int j = 1;j <= 4;j++) {//4个位置逐个替换
                    //第j位的值替换为 i
                    int tval = tmp.val - val[j]*wei + i*wei;
                    wei *= 10;
                    if(prime.count(tval)==0) continue;//不为素数，跳过
                    if(tval<1000) continue;//不为四位数，跳过
                    if(vis.count(tval)) continue;//已经历过，跳过
                    node tt = {tval,tmp.step+1};
                    q.push(tt);//入队
                }
            }
        }
        if(!flag) cout<<"Impossible\n";//无解
    }
    return 0;
}
