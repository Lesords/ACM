#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define yes "1.000000000000"
#define no "0.000000000000"
using namespace std;
int pos,tpos,unknown,num;
void dfs(int p, int step) {//计算可以满足条件的结果数量
    //p为当前位置，step为步数
    if(step==unknown) {//已到达unknown个
        if(p==pos) num++;//可以到达pos，数量++
        return;
    }
    dfs(p+1,step+1);//可以加也可以减
    dfs(p-1,step+1);
}
int main() {
    string a,b;
    cin>>a>>b;
    for(int i = 0;i < a.size();i++) {//先计算命令的最终位置
        if(a[i]=='+') pos++;
        else pos--;
    }
    for(int i = 0;i < b.size();i++) {
        if(b[i]=='+') tpos++;
        else if(b[i]=='-') tpos--;//先计算已知的位置
        else unknown++;//剩余的未知结果
    }
    if(unknown==0&&tpos==pos) cout<<yes;//没有未知的且已到达最终位置
    else if(abs(pos-tpos)>unknown) cout<<no;//未知数量 小于 最终位置和当前的距离差
    else {
        dfs(tpos, 0);//num为可以到达目的点的数量
        double ans = num*1.0/(1<<unknown);//所有可能为 2^unknown 个
        printf("%.12f\n", ans);
    }
    return 0;
}
