#include <iostream>
using namespace std;

int main(){
    int MAX=20;
    int r,c; cout << "Enter rows: ";
	 cin >> r ;
	 cout<<"Enter columns";
	 cin>>c;
    int A[MAX][MAX];
    cout << "Enter matrix ("<<r<<"x"<<c<<"):\n";
    for(int i=0;i<r;i++)
	{
	 for(int j=0;j<c;j++){
	 	cin >> A[i][j];
	 }
   }

    for(int i=0;i<r;i++){
        int s=0;
        for(int j=0;j<c;j++) {
		s += A[i][j];}
        cout << "Row sum = " << s << '\n';
    }
    for(int j=0;j<c;j++){
        int s=0;
        for(int i=0;i<r;i++){
		 s += A[i][j];}
        cout << "Column  sum = " << s << '\n';
        
    }
    return 0;
}
