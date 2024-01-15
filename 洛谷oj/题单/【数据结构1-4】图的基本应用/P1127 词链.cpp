#include<iostream>//ac
#include<cmath>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//题解：先将所有字符串按照字典序从小到大排序
//由于每个字符串只出现一次，并且首尾字符一致的字符串才可以相连
//如果第一个字符串的首字符和最后一个字符串的末字符相等
//那么起点字符串为字典序最小的字符串
//如果不相等，词链首尾字符（第一个字符串的首字符，最后一个字符串的末字符）是固定的
//那么选择一个在首位置出现的次数大于末位置的字符
//遍历寻找包含该字符的字符串，该字符串末尾不应该为 唯一的最后一个字符

const int MAXN = 1e3+5;
string s[MAXN];
vector<string> ans;//保存结果
int st[30],ed[30],len[MAXN],vis[MAXN];//len记录字符串长度，vis判断该字符是否遍历过
//st为字符在首位置出现的次数，ed为字符在末位置出现的次数
int n,flag;//flag记录是否找到答案，找到答案返回
int idx(char c) {//字符转数字
    return c - 'a';
}
void dfs(int now,int num) {//now为当前遍历的位置，num表示已经确定的字符串数量
    if(num==n) {                        //确定n个，则直接结束
        flag = 1;return;
    }
    if(flag) return;                    //找到结果，直接返回
    char last = s[now][len[now]-1];     //上一个字符串的末字符
    for(int i = 1;i <= n;i++) {
        if(vis[i]) continue;            //跳过已遍历的
        char ch = s[i][0];              //当前字符串的首字符！！！
        if(ch!=last) continue;          //不相等则跳过
        ans.push_back(s[i]);            //添加答案
        vis[i] = 1;                     //标记
        dfs(i,num+1);
        if(flag) return;                //如果找到答案，直接返回，不进行后面的操作
        //回溯
        vis[i] = 0;                     //取消标记
        ans.pop_back();                 //弹出结果
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>s[i];
    sort(s+1,s+1+n);                    //按字典序从小到大排序
    for(int i = 1;i <= n;i++) {
        len[i] = s[i].size();           //记录字符串长度
        st[idx(s[i][0])]++;             //记录字符串首位置的字符
        ed[idx(s[i][len[i]-1])]++;      //记录字符串末位置的字符
    }
    //start记录第一个字符串的位置，one为第一个字符，two为最后一个字符
    int start = 1,one = -1,two = -1;    //默认第一个字符串为字典序最小的
    for(int i = 0;i < 26;i++) {
        if(abs(st[i]-ed[i])==1) {       //有差值
            if(st[i]>ed[i]) one = i;    //首位置多即为one
            else two = i;               //否则为two
        }
    }
    if(one!=-1&&two!=-1) {              //找到one和two，没找到直接默认字典序最小
        for(int i = 1;i <= n;i++) {
            int s0 = idx(s[i][0]);
            int se = idx(s[i][len[i]-1]);//one和two是数字，判断需将字符转数字！！！
            //首字符为one且末字符不为two或two的数量不止一个
            if(s0==one&&(se!=two||ed[two]>1)) {
                start = i;break;        //找到就直接结束
            }
        }
    }
    ans.push_back(s[start]);            //起点
    vis[start] = 1;                     //标记起点
    dfs(start,1);
    if(!flag) {                         //没找到输出***
        cout<<"***";
        return 0;
    }
    for(int i = 0;i < ans.size();i++) {
        if(i) cout<<".";                //中间间隔为 . 即可
        cout<<ans[i];
    }
    return 0;
}

/*
3 ac ca ab
*/
