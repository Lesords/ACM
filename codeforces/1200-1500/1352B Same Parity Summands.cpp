#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺�Ⱥ��ж���ż�����������ж��Ƿ�������n
//ż����ǰ�涼Ϊ2+ʣ��ֵ�����ܺͱ���Ϊż������n/2�������������k
//������ǰ�涼Ϊ1+ʣ��ֵ�����ܺͱ������k����(n-k)����Ϊż�����������ܶ�Ϊ������

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(n%2==0&&n/2>=k) {//ż�������ж��ܺ��Ƿ�Ϊż��
            cout<<"YES\n";
            for(int i = 1;i < k;i++) cout<<"2 ";
            cout<<n-(k-1)*2<<"\n";//�������һ��ʣ��ֵ
        }
        else if(n>=k&&(n-k)%2==0) {//��������Ҫ�ж� n ������������
            cout<<"YES\n";
            for(int i = 1;i < k;i++) cout<<"1 ";
            cout<<n-(k-1)<<"\n";//�������һ��ʣ��ֵ
        }
        else cout<<"NO\n";
    }
    return 0;
}
