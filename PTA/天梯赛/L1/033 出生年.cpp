#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int y,n,year;
string to_str(int n) {//将数字转为字符串，若不足4个则前补零
    string ans = "";
    while(n) {
        char op = n%10 + '0';
        ans = op + ans;
        n /= 10;
    }
    while(ans.size()<4) ans = '0'+ans;
    return ans;
}
int check(int n) {
    string tmp = to_str(n);
    set<char> st;
    for(int i = 0;i < (int)tmp.size();i++) st.insert(tmp[i]);//统计有几种数字
    return st.size();//返回数字种类数
}
int main() {
    cin>>y>>n;
    for(int i = y;;i++) {
        if(check(i)==n) {//种类数满足条件时
            cout<<year<<" "<<to_str(i)<<"\n";
            return 0;
        }
        year++;//记录岁数
    }
    return 0;
}
