#include<iostream>//ac  �����жϻ����ַ�����Ӧ������
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//��⣺����ö�ٶ�Ӧ�������е��ַ������ж��Ƿ�����ͬ���ַ�����
//���û�У����޷��γɻ����ַ���

int n;
string s[105];
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>s[i];
        int flag = 0;//0Ϊ���Թ����ַ���
        for(int i = 1,j = n;i<j;i++,j--) {//��������Ϊi < j������
            int mark = 0;
            for(int aa = 0;aa < s[i].size();aa++) {//�ж�aa��bb���Ƿ������ͬ���ַ�
                for(int bb = 0;bb < s[j].size();bb++) {
                    if(s[i][aa]==s[j][bb]) {
                        mark = 1;break;
                    }
                }
                if(mark) break;
            }
            if(mark==0) {//û����ͬ�ַ����޷����ɻ����ַ���
                flag = 1;break;
            }
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
