#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ֻ��ab�����ַ���
//�����ȫa���ַ��������׸��ַ�����Ȼ����last��¼�ϸ��ַ���
//ÿ�����last�ַ�����ǰa[i]����ʣ��ĸ��ݵ� a[i]+1 ����ȡ������

const int MAXN = 105;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        string last(50,'a');//��ʼ��ȫaΪ��һ��
        cout<<last<<"\n";//�����һ��
        string now = "";
        for(int i = 1;i <= n;i++) {//����ʣ��n��
            now = "";
            for(int j = 0;j < a[i];j++) now += last[j];//a[i]����ͬ
            //�±�a[i] ��ʵ���ǵ� a[i]+1 ���������������0��ʼ��
            for(int j = 0;j < 50-a[i];j++) now += (last[a[i]]=='a')?'b':'a';//ȡ��
            cout<<now<<"\n";
            last = now;//����last�ַ���
        }
    }
    return 0;
}
