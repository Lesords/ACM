#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺ÿ���ж�n�ڴӵ�ǰ��ת����һ���̴���λ��
//������һ�������Ե�ǰ��Ϊ  1 2...n  -> 1 2...n n 1 2...
//Ҳ����˵ pos����һ������λ�� Ϊ pos-(len/2)-1
//ע�⣺�����õ�ֵΪ0�������޸ĳ� len/2

typedef long long ll;
int main() {
    string s;
    ll n;
    cin>>s>>n;
    ll len = s.size();//��¼ԭ���ĳ���
    while(n>len) {//�����ԭ���ĳ��ȷ�Χ�������
        ll i = len;
        while(i<n) i <<= 1;//Ѱ������n���Ĵ�
        i >>= 1;//ȡ��һ��ֵ����Ϊ��һ�����ĳ�
        n = (n-i-1);//����n����һ������λ��
        if(n==0) n = i;//����Ϊ0�����������
    }
    cout<<s[n-1];//����0��ʼ��¼
    return 0;
}
