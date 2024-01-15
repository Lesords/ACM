#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：分成 k-1 个个位数和 一个 大数，和即为答案

bool cmp(char a, char b) {//从大到小排序
    return a > b;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回最大和的字符串
     * @param x string字符串 即题目描述中所给字符串
     * @param k int整型 即题目描述中所给的k
     * @return string字符串
     */
    string Maxsumforknumers(string x, int k) {
        // write code here
        sort(x.begin(),x.end(),cmp);//先排序
        string tmp = "",num = "",ans = "";//tmp为大数，num为k-1小数的和，ans为结果
        int len = x.size(),val = 0,jin = 0;//val表示k-1小数的和，jin为进位值
        for(int i = 0;i <= len-k;i++) tmp += x[i];
        for(int i = len-k+1;i < len;i++) {
            val += x[i]-'0';//k-1个数的和
        }
        reverse(tmp.begin(),tmp.end());//翻转，使得开头为低位
        while(val) {
            char ch = val%10 + '0';
            num += ch;//转成字符串类型数据
            val /= 10;
        }//左边为低位
        while(tmp.size()<num.size()) tmp += '0';//长度对齐
        while(num.size()<tmp.size()) num += '0';
        tmp += '0',num += '0';//补零（进位）
        for(int i = 0;i < tmp.size();i++) {//逐位相加
            int a = tmp[i] - '0';
            int b = num[i] - '0';
            ans += (a+b+jin)%10 + '0';
            jin = (a+b+jin)/10;//进位值
        }
        reverse(ans.begin(),ans.end());//翻转即为正常数值
        if(ans[0]=='0') ans.erase(0,1);//去除前导零
        return ans;
    }
};

int main() {
    string s;
    int k;
    cin>>s>>k;
    Solution a;
    cout<<a.Maxsumforknumers(s,k);
    return 0;
}
