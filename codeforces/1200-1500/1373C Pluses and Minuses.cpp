#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����cur��Ҫ>=0���ܽ���
//���������i����cur<0����ô�Դ𰸵Ĺ��׾���i��i��ѭ����
//������cur��˵���� +1 (��һ�δ�ѭ������1)

const int MAXN = 1e6+6;
char s[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>(s+1);
        int len = strlen(s+1);
        ll sum = 0,ans = len;//���ݱ�int
        //ans��ʼ��Ϊlen����Ϊ����ѭ������ѭ��len��
        for(int i = 1;i <= len;i++) {
            sum += (s[i]=='+')?1:-1;//����Ӽ�����
            if(sum<0) {//С��0����ǰλ���й���
                sum += 1;//�´����+1���൱�ڵ�ǰλ��+1
                ans += i;//��ǰλ�õĹ���Ϊi��i��ѭ����
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
