#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��aΪn�����ӣ��� b = n-a����ô max(a,b) % min(a,b) = 0
//����lcm(a,b)��ֵ���Ϊmax(a,b)
//Ҳ����˵��󹫱������Ϊ���߼������Ǹ�ֵ
//���ԣ����Ա���n�����ӣ�ȡ������ӣ�������һ����������Ӧ��С

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int fac = n;//��ʼ��Ϊn����ֹnΪ�������������������
        for(int i = 2;i*i <= n;i++) {
            if(n%i==0) {//��С���� -> n/fac ��Ϊ�������
                fac = i;break;
            }
        }
        cout<<n/fac<<" "<<(n - n/fac)<<"\n";
    }
    return 0;
}
