#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���ö������ж�ѡȡ�����з�����Ȼ��������ֵ����

int num[] = {1,6,28,88,198,328,648};
int siz[] = {8,18,28,58,128,198,388};
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i < (1<<7);i++) {//ÿ���Ż�ȯռһ��λ��
        int tmp = 0,val = 0;//tmp����ѡ��ȯ֮���RMB��val����ȯ��ֵ
        for(int j = 0;j < 7;j++) {//1��ʾѡ��0��ʾ��ѡ
            if(i&(1<<j)) {
                tmp += num[j];
                val += siz[j]+num[j]*10;
            }
            if(tmp>n) break;//RMB����
        }
        if(tmp>n) continue;//RMB����
        ans = max(ans,val+(n-tmp)*10);//ȡ��ֵ
        //  (n-tmp)Ϊʣ���
    }
    cout<<ans;
    return 0;
}
