#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;

//题解：先求每个人的最终分数，取最值
//然后再判断最终分数为最值的人中，哪个最先到达最值的分数

const int MAXN = 1005;
map<string,int> num,tmp;//num为最终得分，tmp为当前得分
string name[MAXN];
int score[MAXN];
int main() {
    int n,maxx = -INF;//初始化为负值
    cin>>n;
    string ans;
    for(int i = 1;i <= n;i++) {
        cin>>name[i]>>score[i];
        num[name[i]] += score[i];//统计最后分数
    }
    map<string,int>::iterator it;
    for(it=num.begin();it!=num.end();it++) {//遍历所有人
        maxx = max(maxx, it->se);//最后分数取最值
    }
    for(int i = 1;i <= n;i++) {
        tmp[name[i]] += score[i];
        //最先到达最值分分数的，并且最后分数需为最值！！！
        if(tmp[name[i]]>=maxx&&num[name[i]]==maxx) {
            ans = name[i];break;
        }
    }
    cout<<ans;
    return 0;
}
