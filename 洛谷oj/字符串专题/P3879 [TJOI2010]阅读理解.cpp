#include<iostream>//ac
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;

//题解：字典树插入和查询字符串
//然后每次操作返回最后的节点编号
//根据节点编号来进行操作
//利用bitset来记录哪一行存在该字符串

struct Trie {
    static const int SIZE = 2e5+5;
    int nex[SIZE][26], cnt;
    void init() {
        cnt = 0;
        memset(nex, 0, sizeof(nex));
    }
    int insert(char *s, int l) {  // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        return p;//返回当前节点编号
    }
    int find(char *s, int l) {  // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return p;//返回当前节点编号
    }
}t;

const int MAX = 5e6+5;
char s[33];
bitset<1001> b[MAX];//利用对应节点是否在哪一行出现过
int main() {
    t.init();
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        while(tmp--) {
            cin>>s;
            int len = strlen(s);
            b[t.insert(s, len)][i] = 1;//对应节点在第i行出现过
        }
    }
    cin>>m;
    while(m--) {
        cin>>s;
        int len = strlen(s);
        int pos = t.find(s, len);//节点号
        if(pos) for(int i = 1;i <= n;i++) {
            if(b[pos][i]==1) {//存在，则输出行号
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
