#include<iostream>//ac
using namespace std;

//��⣺ֱ��ģ�⼴��

const int MAXN = 1005;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        //numΪ�غ�����sum_aΪa���ܺͣ�sum_bΪb���ܺͣ�flagΪ�Ƿ���ǰ����
        int num = 0, sum_a = 0, sum_b = 0,flag = 0;
        int l = 1, r = n, last_a = 0, last_b = 0;
        //���ұ߽磬a����һ��ֵ��b����һ��ֵ
        while(l<=r) {
            int tmp = 0;
            num++;//�غ�++
            for(int i = l;i <= r;i++) {//�������ۼ�ֵ
                tmp += a[i];
                if(tmp>last_b) {//����b��ֵ���ɽ���
                    l = i+1;//�ƶ���߽磨��ǰ��ʹ�ã����ƣ�
                    break;
                }
                if(i==r) flag = 1;//����߽磬����ǰ����
            }
            sum_a += last_a = tmp;//�ۼӲ�������һ��ֵ
            if(flag||l>r) break;//������ǰ��������������
            tmp = 0;//��ʼ��
            num++;//����һ���غ�
            for(int i = r;i >= l;i--) {//���ҵ����ۼ�ֵ
                tmp += a[i];
                if(tmp>last_a) {//����a��ֵ���ɽ���
                    r = i-1;//�ƶ��ұ߽�
                    break;
                }
                if(i==l) flag = 1;//��ǰ����������
            }
            sum_b += last_b = tmp;//�ۼӲ�������һ��ֵ
            if(flag) break;//������ǰ��������
        }
        cout<<num<<" "<<sum_a<<" "<<sum_b<<"\n";
    }
    return 0;
}
