#include<iostream>//ac
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

//题解：字典树模板题，利用set来判断是否重复点名
//trie保存的是字典树节点的信息
//End保存的是当前的节点是否为一个字符串
//cnt为节点的编号
//trie的长度计算为 N*str(s) 也就是 字符串数量*字符串长度（每个字符都为一个节点）

const int MAXN = 5e5+5;
int trie[MAXN][26],End[MAXN],cnt;//trie的大小！！！
set<string> st;//用来判重
void Insert(string tmp) {//添加tmp的信息到字典树中
    int p = 1;//初始节点为1
    for(int i = 0;i < tmp.size();i++) {//遍历所有字符
        char ch = tmp[i];
        if(trie[p][ch]==0) trie[p][ch] = ++cnt;//当前节点不存在则建新
        p = trie[p][ch];//移动节点位置
    }
    End[p] = 1;//p位置存在字符串
}
int Find(string tmp) {//判断tmp字符串是否存在
    int p = 1;
    for(int i = 0;i < tmp.size();i++) {//遍历所有字符
        char ch = tmp[i];
        if(trie[p][ch]==0) return 0;//当前节点不存在则返回0
        p = trie[p][ch];
    }
    return End[p];//为1表示存在，0表示不存在
}
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        Insert(tmp);//将tmp添加到字典树中去
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        string tmp;
        cin>>tmp;
        int ok = Find(tmp);//判断tmp字符串
        if(ok&&st.find(tmp)==st.end()) {
            cout<<"OK\n";
            st.insert(tmp);
        }
        else if(ok==0) {//tmp不存在
            cout<<"WRONG\n";
        }
        else if(st.find(tmp)!=st.end()) {//重复了
            cout<<"REPEAT\n";
        }
    }
    return 0;
}
