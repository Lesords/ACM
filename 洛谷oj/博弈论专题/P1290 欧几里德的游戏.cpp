#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺SG����
//����n��m���ԣ����� n >= m
//���� n = m*k + r
//���rΪ0����ǰΪ��ʤ̬��n - m*k = 0����ȡһ��0
//�������SG(n,m)�У�SG(n-m,m),SG(n-2m,m),SG(n-3m,m),������,SG(n%m,m)
//������Щ��̽ڵ���ԣ�
//��k���ڵ���2ʱ��Ҳ����˵SG(n,m)����ת��ΪSG(n-(k-1)m,m), SG(n%m,m)
//Ҳ����(m+r,m) (m,r) ����״̬������(m+r,m)����ת��Ϊ(m,r)
//��ô���У���������һ���Ǳ�ʤ̬����һ���Ǳذ�̬
//��ô���ڵ�ǰ���ԣ�����ѡ������һ���ıذ�̬��ת�ƣ���ǰҲΪ��ʤ̬
//����kС��2�ģ������SG(m,n%m)ת��

int judge(int n,int m,int flag) {//flagΪӮ���ˣ�1ΪStan��0ΪOllie
    if(n==m||n/m>=2) return flag;//��ʤ̬
    else return judge(m, n-m,flag^1);//�����������
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        if(m<n) swap(m,n);//��֤m���ڵ���n
        if(judge(m,n,1)) cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";
    }
    return 0;
}
