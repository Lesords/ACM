#include<iostream>//ac
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

//题解：样例过多，需要反向bfs记录答案
//用map<string,string> ans来保存对应状态需要的路径（反向输出）

struct node{
    string state,path;//state为状态，path为路径
    int x,y,step;//x和y为字符'x'的坐标
    friend bool operator < (node a,node b) {
        return a.step > b.step;//优先步数少的
    }
};
char s[4][4];
char dir[4] = {'u','d','l','r'};//四个方向对应的方向（反向，终点向起点）
int nextt[4][2] = {1,0,-1,0,0,1,0,-1};//四个方向
vector<string> a;//记录输入的所有状态
set<string> shav;//记录所有需要计算的状态
map<string,string> ans;//保存结果路径
void bfs() {
    priority_queue<node> q;
    set<string> vis;//记录遍历过的状态
    node tmp = {"12345678x","",3,3,0};//初始化状态（结果）
    int vnum = 0;//已获得答案路径的数量
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();q.pop();
        if(vis.count(tmp.state)) continue;//跳过已遍历的
        else {
            if(shav.count(tmp.state)) {//如果为需要计算的状态
                ans[tmp.state] = tmp.path;//记录答案路径
                vnum++;//计算数量++
            }
            vis.insert(tmp.state);//标记已遍历过的
        }
        if(vnum==a.size()) return ;//所有需要的都计算完，直接返回
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>3||ty<1||ty>3) continue;//越界
            int fpos = (tmp.x-1)*3+tmp.y-1;//二维变一维！！！
            int tpos = (tx-1)*3+ty-1;
            node tt = tmp;
            swap(tt.state[tpos],tt.state[fpos]);//交换对应的值
            if(vis.count(tt.state)) continue;//跳过已标记的
            tt.step++;//步数++
            tt.x = tx,tt.y = ty;//更新'x'的坐标值
            tt.path += dir[i];//路径增加
            q.push(tt);
        }
    }
    return ;
}
int main() {
    char tmp;
    while(cin>>tmp) {
        string svis = "";
        svis += tmp;
        for(int i = 1;i <= 8;i++) cin>>tmp,svis+=tmp;//svis为当前字符串的状态
        a.push_back(svis);
        shav.insert(svis);
    }
    bfs();
    for(int i = 0;i < a.size();i++) {//遍历所有需要计算的状态
        if(ans.count(a[i])) {//反向输出
            for(int j = ans[a[i]].size()-1;j >= 0;j--) cout<<ans[a[i]][j];
            cout<<'\n';
        }
        else cout<<"unsolvable\n";//ans中不存在，则无解
    }
    return 0;
}
