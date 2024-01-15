#include<iostream>//ac
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    string now;//记录当前字符串
    int step;//记录当前步数
    friend bool operator < (node a,node b) {
        return a.step > b.step;//根据步数，小的优先
    }
};
map<string,vector<string> > mp;//存储对应子串可以转换的字符串（用vector!!!
set<string> vis;//用来标记当前字符串状态是否经历过，防止tle！！！
int main() {
    string a,b,tmp1,tmp2;
    cin>>a>>b;
    while(cin>>tmp1>>tmp2) {
        mp[tmp1].push_back(tmp2);//将tmp2放入tmp1对应的vector中
    }
    priority_queue<node> q;
    q.push({a,0});//初始化即为a原串
    int ans = -1;//初始化为-1，若结果仍为-1即表示无解
    while(!q.empty()) {
        node tmp = q.top();q.pop();
        if(tmp.now==b) {//已到达目的串，则更新答案，结束
            ans = tmp.step;break;
        }
        if(vis.count(tmp.now)) continue;//判断当前字符串是否遍历过
        else vis.insert(tmp.now);
        int len = tmp.now.size();//记录当前串的长度
        for(int i = 0;i < len;i++) {
            for(int j = i;j < len;j++) {//取当前串的所有子串！！！
                string ss = "",sleft = "",sright = "";
                for(int k = i;k <= j;k++) ss += tmp.now[k];//当前子串[i,j]
                if(mp.count(ss)) {
                    int pos = 0;
                    while(pos<i) sleft += tmp.now[pos++];//子串前的字符串
                    pos = j+1;
                    while(pos<len) sright += tmp.now[pos++];//子串后的字符串
                    for(int k = 0;k < mp[ss].size();k++) {//遍历当前子串可以转换的字符串
                        string snow = mp[ss][k];//转换后的字符串
                        //则 sleft+snow+sright 即为最后结果串
                        q.push(node{sleft+snow+sright,tmp.step+1});//步数+1
                    }
                }
            }
        }
    }
    if(ans==-1) cout<<"NO ANSWER!\n";
    else cout<<ans<<"\n";
    return 0;
}
