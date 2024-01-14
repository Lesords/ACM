#include<iostream>//ac
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
string s;
int main() {
    int n;
    cin>>n;
    getchar();//读取数字末尾回车符
    getline(cin,s);
    int len = s.size();
    int siz = ceil(len*1.0/n);//计算总共有几列
    vector<vector<char> > ans(n,vector<char>(siz,' '));//初始化二维vector
    int pos = 0;
    for(int i = siz-1;i >= 0;i--) {//构造数组
        for(int j = 0;j < n;j++) {//需要特殊处理字符串结束符！！！
            if(pos>=len) ans[j][i] = ' ';//如果超过字符串大小，则为空格
            else ans[j][i] = s[pos++];
        }//最后一列不满需要补齐空格！！！
    }
    for(int i = 0;i < n;i++) {//输出结果
        for(int j = 0;j < siz;j++) cout<<ans[i][j];
        cout<<"\n";
    }
    return 0;
}
