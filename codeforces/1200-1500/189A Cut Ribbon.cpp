#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��Ŀ�ɻ�Ϊ��n = ai+bj+cz����(i+j+z)�����ֵ
//�������ݽ�С�������ֱ�ӱ���i��jȻ����z�����ȡ���ֵ����

int main() {
    int n,a,b,c,ans = 0;
    cin>>n>>a>>b>>c;
    for(int i = 0;i <= n/a;i++) {//��������i��j
        for(int j = 0;j <= n/b;j++) {
            int sum = i*a+j*b;
            int rest = n-sum;//ʣ��ֵ
            if(rest<0||rest%c) continue;//����Ϊ����������Ҫ������
            ans = max(ans,i+j+rest/c);//ȡ���ֵ
        }
    }
    cout<<ans;
    return 0;
}
