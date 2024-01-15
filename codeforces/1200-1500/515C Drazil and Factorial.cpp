#include<iostream>//ac
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//题解：遍历所有的数，将其对应转换为值较大的几位数
//然后将所有数位降序排序输出即可

vector<char> v;
bool cmp(char a, char b) {
    return a > b;
}
int main() {
    int n;
    string s;
    cin>>n>>s;
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='1'||s[i]=='0') continue;//跳过0和1（不能出现0和1）
        //2 3 5 7只能转换为本身
        //其他数：先当前-1，然后再继续换算后面的值，否则-2继续
        if(s[i]=='2'||s[i]=='3'||s[i]=='5'||s[i]=='7') v.push_back(s[i]);
        else if(s[i]=='4') {
            v.push_back('3');
            v.push_back('2');
            v.push_back('2');
        }
        else if(s[i]=='6') {
            v.push_back('5');//差个6
            v.push_back('3');//2*3 = 6
        }
        else if(s[i]=='8') {
            v.push_back('7');//差个8
            v.push_back('2');//2*2*2 = 8
            v.push_back('2');
            v.push_back('2');
        }
        else if(s[i]=='9') {//8不行，所以按照7来计算
            v.push_back('7');//差8*9
            v.push_back('3');//2*2*2 * 3*3
            v.push_back('3');
            v.push_back('2');
        }
    }
    sort(v.begin(),v.end(),cmp);//降序输出即可
    for(int i = 0;i < v.size();i++) cout<<v[i];
    return 0;
}
