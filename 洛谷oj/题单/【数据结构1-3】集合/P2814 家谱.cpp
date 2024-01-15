#include<iostream>//ac
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

//题解：利用map将字符串转换成数字，然后进行并查集即可

const int MAXN = 5e4+5;
int dis[MAXN],num;      //dis记录祖先，num为字符串编号
map<string,int> id;     //将字符串转为数字
map<int,string> name;   //将数字转为字符串
int getf(int pos) {     //寻找祖先，路径压缩
    return dis[pos]==pos?pos:dis[pos]=getf(dis[pos]);
}
void Merge(int a,int b) {//合并操作，a是祖先
    a = getf(a),b = getf(b);
    if(a!=b) {
        dis[b] = a;
    }
}
int main() {
    for(int i = 1;i < MAXN;i++) dis[i] = i;//初始化祖先为本身
    string s,fa;
    char op;
    //空格处理末尾回车
    while(scanf(" %1c",&op)&&op!='$') {     //$为结束符
        cin>>s;
        //新的字符串，需添加对应信息
        if(id.find(s)==id.end()) id[s] = ++num,name[num] = s;
        if(op=='#') {                       //更新祖先的字符串
            fa = s;
        }
        else if(op=='+') {                  //将儿子节点合并到父节点
            Merge(id[fa],id[s]);
        }
        else {
            int fa = getf(id[s]);           //查询id[s]的祖先，不能直接dis数组寻找！！！
            cout<<s<<" "<<name[fa]<<"\n";   //根据祖先的id输出字符串
        }
    }
    return 0;
}
