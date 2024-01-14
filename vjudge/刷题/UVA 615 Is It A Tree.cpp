#include<iostream>//ac
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//题解：由于部分数据过大，所以可用map将数据对应转换下
//然后记录入度，入度为0的数量只能由一个（根），否则不成立
//从入度为0的位置开始dfs判断环，并且统计经过的数量

//特殊情况：
//没有入度为0的点说明已经有环了
//有多个入度为0的点，为森林
//空树，自环
//一个为树，另一个有环，且只在树中遍历（dfs记录数量可解决）！！！

const int MAXN = 1e5+5;
vector<int> g[MAXN];
map<int,int> to_num;//将点的值缩小
int in[MAXN],mark[MAXN],dfsnum;
//in保存入度，mark用于dfs标记，dfsnum记录dfs过程中访问的节点数
void init(int maxdot) {//清空图
    for(int i = 0;i <= maxdot;i++) g[i].clear();
}
int dfs(int sdot) {//dfs判断是否有环和记录访问数量
    for(int i = 0;i < g[sdot].size();i++) {
        int now = g[sdot][i];
        if(mark[now]) return 0;//已访问
        mark[now] = 1;
        dfsnum++;//访问数量++
        if(!dfs(now)) return 0;//继续调用，若调用结果为0，则直接返回！！！
    }
    return 1;
}
int main() {
    int a,b,cnt = 1;
    while(cin>>a>>b) {
        if(a<0||b<0) break;//结束条件为负数
        if(a==0&&b==0) {//直接为0 0说明为空树
            cout<<"Case "<<cnt++<<" is a tree."<<endl;
            continue;
        }
        memset(in,0,sizeof(in));
        memset(mark,0,sizeof(mark));
        to_num.clear();//初始化操作

        int dnum = 1,a_num,b_num,flag = 0;//dnum为当前节点的编号
        //a_num 和 b_num为修改后的对应节点编号
        a_num = to_num[a] = dnum;//第一个绝对为dnum，剩余的都需要判断是否存在
        if(to_num.find(b)!=to_num.end()) b_num = to_num[b];//存在
        else b_num = to_num[b] = ++dnum;//不存在时，指定值
        g[a_num].push_back(b_num);//存边
        in[b_num]++;//记录入度（单向边）
        while(cin>>a>>b&&a&&b) {
            if(to_num.find(a)!=to_num.end()) a_num = to_num[a];
            else a_num = to_num[a] = ++dnum;
            if(to_num.find(b)!=to_num.end()) b_num = to_num[b];
            else b_num = to_num[b] = ++dnum;//节点转换
            g[a_num].push_back(b_num);//存边
            in[b_num]++;//入度
            if(a_num==b_num) flag = 1;//判断是否自环
        }
        int sdot = 0,num = 0;//sdot表示根，num为根的数量
        for(int i = 1;i <= dnum;i++) if(in[i]==0) {//入度为0即为根
            sdot = i;num++;
        }
        if(flag||num>1||sdot == 0) {//判断自环和森林和环
            cout<<"Case "<<cnt++<<" is not a tree."<<endl;
            init(dnum);//清空边
            continue;
        }
        dfsnum = mark[sdot] = 1;//标记根，并记录访问点数
        //无环 并且 访问数量等于所有节点数
        if(dfs(sdot)&&dfsnum==dnum) cout<<"Case "<<cnt++<<" is a tree."<<endl;
        else cout<<"Case "<<cnt++<<" is not a tree."<<endl;
        init(dnum);//清空边
    }
    return 0;
}
/*
6 8  5 3  5 2  6 4
5 6  0 0

6 8  5 3  5 2  6 4
5 6  5 3 0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

1 2 3 3 0 0

99006 700002 700002 880002  880002 1000001 1000001 1234567890 1234567890 22 0 0

1 2
2 3
4 3
2 4
0 0

1 2
2 3
4 5
0 0

1 7346537
37542 1
0 0

7 7
0 0

100 1
1 2
9 7
7 3
3 88
88 6
1 9
2 6
0 0

1 2
1 2
0 0

999999 5
0 0

0 0

1 2
2 1
0 0

2 5 5 4 4 3 3 2 2 1
10 11 0 0

-4 -5

*/
