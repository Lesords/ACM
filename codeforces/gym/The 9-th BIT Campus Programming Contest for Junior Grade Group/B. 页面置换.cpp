#include<iostream>//ac
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：由于OPT算法是最优的，所以直接使用OPT算法计算即可
//OPT算法中，利用vector存储对应界面需要访问的界面可以方便判断！！！
//这样可以遍历所有vector判断最远不访问的界面
//直接利用cnt和vis记录内存中的界面数量，防止set会TLE

const int MAXN = 1e5+5;
const int MAXM = 1e3+5;
int n,m,k;
int a[MAXN],vis[MAXM],num[MAXM];
//vis记录界面是否在内存中，num记录对应界面需要访问的次数
vector<int> vec[MAXM];//vec存储对应界面访问的位置
int OPT() {
    int ans = 0,cnt = 0;
    for(int i = 1;i <= n;i++) {
        num[a[i]]++;//记录所有界面需要访问的次数
    }
    for(int i = n;i >= 1;i--) {//倒序记录界面出现的位置
        vec[a[i]].push_back(i);//可以使得pop_front()为最近的位置
    }
    for(int i = 1;i <= n;i++) {
        int now = a[i];
        if(vis[now]==0) {//没有当前界面
            while(cnt>=k) {//内存中的界面数量大于等于k
                int index = -1;
                for(int j = 1;j <= m;j++) {//先寻找永不访问的界面
                    if(num[j]==0&&vis[j]) {//num为0表示永不访问
                        index = j;break;//vis必须为1表示在内存中
                    }
                }
                if(index==-1) {//否则寻找最久不访问的界面
                    int max_time = 0;
                    for(int j = 1;j <= m;j++) {
                        //跳过j接下来不访问的情况
                        //并且j必须在当前内存中！！！
                        if(vec[j].empty()||!vis[j]) continue;
                        if(vec[j][vec[j].size()-1]>max_time) {
                            max_time = vec[j][vec[j].size()-1];
                            index = j;
                        }//寻找最远不访问的界面
                    }
                }
                vis[index] = 0;//删除index界面，并更新对应数量
                cnt--;
            }
            ans++;//操作次数++
            cnt++;//界面数量++
            vis[now] = 1;//标记当前界面
        }
        num[now]--;//当前界面的访问次数--
        vec[now].pop_back();//删除当前界面的当前出现位置
    }
    return ans;//返回最后结果
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    cout<<"OPT\n"<<OPT();
    return 0;
}
/*
12 8 12
1 3 3 4 4 5 5 5 5 5 5 5
5 2 1
1 2 2 2 2
5 2 1
2 1 2 2 2
*/
