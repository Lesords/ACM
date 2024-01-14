#include<iostream>//ac
#include<cstdio>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//坑点：处理数字的时候不要忘记了负号！！！

const int MAXN = 1e3+5;
int tree[MAXN],n,m;
map<int,int> pa;//pa保存对应值在树中的位置
void update(int dot) {//向上调整
    while(dot!=1) {//不为根则继续
        if(tree[dot]<tree[dot/2]) {//儿子小于父节点则交换，并更新当前节点
            swap(tree[dot],tree[dot/2]);
            dot /= 2;
        }
        else return ;//否则直接结束
    }
}
bool check(string s) {//判断当前字符串是否为数字
    for(int i = 0;i < (int)s.size();i++) {
        //负号，巨巨巨重要！！！
        if(s[i]>='0'&&s[i]<='9'||s[i]=='-') continue;
        else return 0;
    }
    return 1;
}
int to_num(string s) {//将字符串转换为数字
    int ans = 0,st = 0,flag = 0;
    if(s[st]=='-') st++,flag = 1;//特殊处理负号的情况
    for(int i = st;i < (int)s.size();i++) {
        int tmp = s[i]-'0';
        ans = ans*10 + tmp;
    }
    if(flag) ans *= -1;//若有负号，记得改为负数
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>tree[i];
        update(i);//向上调整
    }
    for(int i = 1;i <= n;i++) pa[tree[i]] = i;//记录当前节点值的位置
    getchar();//处理行末空格
    for(int i = 1;i <= m;i++) {
        string s,tmp;
        int a = 0,b = 0,mode = 0,flag = 0;
        getline(cin,s);//每次直接读取一行
        stringstream ss(s);
        while(ss>>tmp) {//每次判断都有独一的单词
            if(tmp=="root") mode = 1;
            else if(tmp=="siblings") mode = 2;
            else if(tmp=="parent") mode = 3;
            else if(tmp=="child") mode = 4;
            if(check(tmp)) {//tmp为数字
                if(!flag) a = to_num(tmp),flag = 1;//flag为0则赋值给a，否则为b
                else b = to_num(tmp);
            }
        }
        //根据对应对应模式判断即可
        if(mode==1) cout<<((a==tree[1])?"T\n":"F\n");//判断当前点是否为根
        else if(mode==2) cout<<((pa[a]/2==pa[b]/2)?"T\n":"F\n");//判断两个节点是否为兄弟节点
        else if(mode==3) cout<<((pa[b]/2==pa[a])?"T\n":"F\n");//判断a是否为b的父节点
        else if(mode==4) cout<<((pa[a]/2==pa[b])?"T\n":"F\n");//判断b是否为a的父节点
    }
    return 0;
}
