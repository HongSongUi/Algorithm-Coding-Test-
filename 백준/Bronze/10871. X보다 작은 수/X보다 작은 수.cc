#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int a,b,c;
	cin>>a>>b;
	for(int i = 0;i<a;i++){
		cin>>c;
		if(b>c){
			cout<<c<<endl;
		}
	}
	
	return 0;
}