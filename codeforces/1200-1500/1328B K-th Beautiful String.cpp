#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

//��⣺�ҹ��ɣ��ᷢ�ִ������µ�һ��b��λ�ö�Ӧ������Ϊ1 - 2 - 3 - 4 - n-1
//�ڶ���bΪ�ӵ�λ��ʼ����
//���Կ������жϵ�ǰ�����ĸ������жϵ�һ��b��λ�ã�Ȼ�����жϵ�һ��b��λ��

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s(n,'a');//��ʼ��Ϊn��a
        for(int i = 1;i <= n-1;i++) {//�ж����ĸ��ֿ� ���n-1��
            if(k<=i) {//�ڵ�ǰ��Χ��
                s[n-1-i] = 'b';//��һ��b��λ�ã������i����
                s[n-k] = 'b';//�ڶ���b��λ��Ϊ �ӵ�λ��ʼ����k��
                cout<<s<<"\n";
                break;
            }
            else k -= i;//����ɾ����ǰ��Ĵ�С
        }
    }
    return 0;
}
