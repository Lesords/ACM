#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
struct node{
    string name;//����
    int score;//����
    friend bool operator < (node a,node b) {
        //�ȳɼ�����Ȼ����������
        if(a.score!=b.score) return a.score > b.score;
        return a.name < b.name;
    }
}a[MAXN];
int main() {
    int n,g,k,ans = 0;//ansΪ����ȯ�ܺ͵�ֵ
    cin>>n>>g>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].name>>a[i].score;
        if(a[i].score>=g) ans += 50;
        else if(a[i].score>=60) ans += 20;
    }
    sort(a+1,a+n+1);
    cout<<ans<<"\n";
    int pos = 0,last = 0;//pos��ʾ��ǰ��λ�ã�last��ʾ��һ�ε�����
    for(int i = 1;i <= n;i++) {
        if(pos==0) {//��һ��
            cout<<++pos<<" "<<a[i].name<<" "<<a[i].score<<"\n";
            last = pos;//����last��ֵ
        }
        else {
            ++pos;//λ�ö���Ҫ�ۼӣ�����
            if(a[i].score==a[i-1].score) {
                //�����������last��ʾ����
                cout<<last<<" "<<a[i].name<<" "<<a[i].score<<"\n";
            }
            else {
                if(pos>k) break;//������ͬ���ҵ�ǰ����k�����������
                cout<<pos<<" "<<a[i].name<<" "<<a[i].score<<"\n";
                last = pos;//����last��ֵ
            }
        }
    }
    return 0;
}
