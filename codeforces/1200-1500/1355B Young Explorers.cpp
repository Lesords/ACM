#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺ͳ�Ƹ��������ֵĴ���
//��ôÿ����ֵ��Ҫ�Ķ�Ա����Ϊ�������Զ�Ӧֵ������ɵ�����Ϊ num[val]/val
//����ǰ��û��ͳ�ƵĿ��Թ鵽����ȥ�����Ժ���Ŀ��Լ���ǰ�������

const int MAXN = 2e5+5;
int a[MAXN],num[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[a[i]]++;//ͳ������
        }
        for(int i = 1;i <= n;i++) {
            if(i>1) num[i] += num[i-1]%(i-1);//�����ǰ��ʣ�������
            ans += num[i]/i;//���㵱ǰֵ������ɵ�����
            num[i-1] = 0;//���㣨memset���Ӷȹ��ߣ�������
        }
        num[n] = 0;//��ʣnλ����Ҫ����
        cout<<ans<<"\n";
    }
    return 0;
}
