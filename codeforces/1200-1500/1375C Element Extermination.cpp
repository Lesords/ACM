#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺a[1] < a[n]ʱ�н⣬��Ϊ 1-n֮������ҵ�һ����С��r
//ʹa[1] < a[r]����ô1-r�м����е�Ԫ�ض�������rƥ�䣬��rɾ����Ȼ���ٰ�rɾ��
//���������ʹ����ֻʣһ��Ԫ��
//���a[1] > a[n] �Ļ�����ô�������Ĳ�������a[2] > a[1]������ɾ��a[1]
//��������a[1] > a[n]�����Թ��ɵ�a[2] > a[n]�����²�ƥ��

//����Ҳ����ջ�������˼������������

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,a,b;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            if(i==1) a = tmp;//��¼��һ����
            if(i==n) b = tmp;//��¼���һ����
        }
        if(a<b) cout<<"YES\n";//��һ��С�����һ�����н�
        else cout<<"NO\n";
    }
    return 0;
}
