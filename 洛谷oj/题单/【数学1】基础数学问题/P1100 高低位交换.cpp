#include<iostream>//ac
#include<string>
using namespace std;
int num[36],change[36];
unsigned int solve(unsigned int n) {//32λ��������unsigned
    unsigned int tmp = n,cnt = 0,ans = 0;
    //1-32��1��λ��32��λ��
    while(tmp) {
        num[++cnt] = tmp&1;//��¼��ǰλ�Ĵ�С
        tmp >>= 1;
    }
    while(cnt<32) num[++cnt] = 0;//��λ��������
    for(int i = 1;i <= 16;i++) change[i] = num[i+16];//��λ�ɵ�λ
    for(int i = 17;i <= 32;i++) change[i] = num[i-16];//��λ�ɸ�λ
    unsigned int val = 1;//��Ӧλ�õ�ֵ
    for(int i = 1;i <= 32;i++) {//������תʮ����
        if(change[i]) ans += val;
        val <<= 1;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
