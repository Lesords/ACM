#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,flag;//n为目标数，flag判断是否已有答案
char s[105];//字符串的复杂度过高，用数组比较快！！！
//利用大数除的思想，每次只需要保留余数操作即可，余数为0即满足条件
void dfs(int rem,int pos) {//rem为余数，pos为上一个操作的位置
    if(flag||pos>100) return;//已找到，或超过范围（结果不超过100位）
    if(rem==0) {//满足条件
        for(int i = 1;i <= pos;i++) cout<<s[i];
        cout<<"\n";
        //flag标记
        flag = 1;return ;
    }
    //不满足条件时，（pos+1）位只有两种条件 0和1
    if(!flag) s[pos+1] = '0',dfs(rem*10%n,pos+1);//添加0
    if(!flag) s[pos+1] = '1',dfs((rem*10+1)%n,pos+1);//添加1
}
int main() {
    while(cin>>n&&n) {
        flag = 0;
        memset(s,0,sizeof(s));//初始化
        s[1] = '1';//第一位必定是1
        dfs(1%n,1);//从第一个位置开始dfs
    }
    return 0;
}
