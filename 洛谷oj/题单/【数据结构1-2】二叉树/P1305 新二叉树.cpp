#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题解：根据题意建边，并且记录入度
//入度为0的点即为根，然后顺着根进行前序遍历即可

char s[5],tree[30];//tree记录树节点的值
int l[50],r[30],vis[30],in[30];//l、r分别为左右儿子，vis记录出现的字符，in记录入度
int idx(char ch) {
    return ch-'a'+1;//编号从1开始，防止误判（左右儿子为0表示儿子为空！！！
}
char chx(int id) {
    return id+'a'-1;//转字符需-1
}
void preorder(int rt) {//前序遍历
    cout<<chx(rt);
    if(l[rt]) {
        preorder(l[rt]);
    }
    if(r[rt]) {
        preorder(r[rt]);
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>s;
        vis[idx(s[0])] = 1;//表示当前字符
        if(s[1]!='*') {//若存在左儿子，则记录对应信息
            vis[idx(s[1])] = 1;
            l[idx(s[0])] = idx(s[1]);//左儿子
            in[idx(s[1])]++;//入度
        }
        if(s[2]!='*') {//若存在右儿子，则记录对应信息
            vis[idx(s[2])] = 1;
            r[idx(s[0])] = idx(s[2]);//右儿子
            in[idx(s[2])]++;//入度
        }
    }
    int rt = -1;//rt存根的编号
    for(int i = 0;i < 26;i++) {//寻找根的编号
        if(vis[i]&&in[i]==0) {//存在的字符，并且入度为0
            rt = i;break;
        }
    }
    preorder(rt);
    return 0;
}
