#include<iostream>//ac
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#define fi first
#define se second
#define pci pair<char, int>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺�������Ž�϶�Ϊ �м�һ���ַ�������β������ͬ�ַ�
//���Կ��԰���˳��洢��Ӧ�ַ����ֵĴ���
//Ȼ���������ַ�Ϊ�м���ж�ǰ�������ַ��Ƿ�һ��������һ������´�
//��ǰ��Ϊ �м��ַ�����+2

vector<pci> v;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        v.clear();//���
        for(int i = 0;i < s.size();i++) {
            if(v.empty()||v.back().fi!=s[i]) {//��¼Ϊ�ջ��ַ���ǰ�治ͬ
                v.push_back({s[i],1});
            }
            else v.back().se++;//�����ַ���++
        }
        int ans = INF;
        for(int i = 1;i < v.size()-1;i++) {
            //ǰ�治һ�������������ַ�������
            if(v[i-1].fi!=v[i+1].fi) ans = min(ans,v[i].se+2);//����ֵ
        }
        if(ans==INF) cout<<"0\n";//�޽�����
        else cout<<ans<<"\n";
    }
    return 0;
}
