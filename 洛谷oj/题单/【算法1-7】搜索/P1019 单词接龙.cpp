#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n,ans,vis[25];//vis用来记录对应的字符出现了几次
string s[25];
int check(string a,string b) {//计算a和b的重复词语数量（尽量取小）
    //判断重复就是用a的后缀和b的前缀比较
    int siz = a.size()-1;//不能包含，所以删除一个字符
    a.erase(0,1);
    int ans = INF;//初始化为INF
    while(siz--) {//遍历剩余所有后缀判断是否有重复的
        int op = 1;//1为有重复，0为无重复
        for(int i = 0;i < a.size();i++) {//只判断a的大小即可
            if(a[i]!=b[i]) {//有一个不同则op为0
                op = 0;break;
            }
        }//重复大小为对应a的大小
        if(op) ans = min(ans,int(a.size()));//有重复，取小！！！
        a.erase(0,1);//删除首字符，进行下一个后缀匹配
    }
    if(ans==INF) return 0;//为INF说明没有重复词
    return ans;//返回重复的大小
}
void dfs(string now,int len) {//now为当前需要接龙的字符串，len为总字符串长度
    for(int i = 1;i <= n;i++) {
        //两个字符可以相同，只要有循环节！！！
        if(vis[i]>=2||!check(now,s[i])) continue;//已用两次或无重复
        int siz = s[i].size()-check(now,s[i]);//当前判断字符串-重复字符数即为增加数
        if(!siz) continue;//跳过相同的字符
        ans = max(ans,len+siz);//更新ans
        vis[i]++;//次数++
        dfs(s[i],len+siz);//继续从当前字符串dfs，更新len参数
        vis[i]--;//回溯，次数--
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>s[i];
    char start;
    cin>>start;//为单个字符
    for(int i = 1;i <= n;i++) {//遍历所有字符
        if(s[i][0]!=start) continue;//不为start则跳过
        vis[i]++;//当前次数++
        ans = max(ans,int(s[i].size()));//更新ans的大小
        dfs(s[i],s[i].size());
        vis[i]--;//回溯，次数--
    }
    cout<<ans<<endl;
    return 0;
}
