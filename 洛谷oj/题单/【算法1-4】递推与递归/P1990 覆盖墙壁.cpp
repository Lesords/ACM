#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e6+5;
const int MOD = 10000;
int f[MAXN],d[MAXN];//f[i]������i���ķ�������d[i]����iλ�÷�L��ש�ķ�������������
int main() {
    //����Ϊ0��1�ķ�������Ϊ1������Ϊ1�ĳ��ַ�����ҲΪ1������
    f[0] = f[1] = d[1] = 1;
    int n;
    cin>>n;
    for(int i = 2;i <= n;i++) {//��ʽ�Ƶ���PPT
        f[i] = (f[i-1]+f[i-2]+d[i-2]*2)%MOD;
        d[i] = (f[i-1]+d[i-1])%MOD;
    }
    cout<<f[n];
    return 0;
}
