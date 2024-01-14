#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	string a,b;
	while(cin>>a>>b) {
		int len_a = a.size();
		int len_b = b.size();
		int i = 0,j = 0;
		while(i<len_a&&j<len_b) {
			if(a[i]==b[j]) i++,j++;
			else j++;//目标串不需要置零
		}
		if(i==len_a) cout<<"Yes"<<endl;//i最后有++
		else cout<<"No"<<endl;
	}
	return 0;
}
