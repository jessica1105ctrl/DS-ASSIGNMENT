#include <iostream>
using namespace std;
int max = 100;
int arr[max];
int n = 0;

void create(){
    cout << "Enter number of elements: ";
    cin >> n;
    if(n > max)
     { cout << "Too many elements" ;
         n = max; }
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) cin >> arr[i];
}
void display(){
    if(n==0)
    { cout << "Array is empty.\n";}
    for(int i=0;i<n;i++) {
        cout << arr[i]<<endl;
    }
}
void insert(){
    int pos,val;
    cout << "Enter position (0.." << n << ") and value: ";
    cin >> pos >> val;
    if(pos<0 || pos>n || n==max){ cout << "Invalid position or array full.\n"; return; }
    for(int i=n;i>pos;i--) arr[i]=arr[i-1];
    arr[pos]=val; n++;
}
void del(){
    if(n==0)
    { cout << "Array is empty.\n"; return; }
    int pos;
     cout << "Enter position to delete " << (n-1) << "): ";
    cin >> pos;
    if(pos<0 || pos>=n){ cout << "Invalid position.\n";  }
    for(int i=pos;i<n-1;i++) 
    {
        arr[i]=arr[i+1];
       n--;
    }
}

void linearSearch(){
    int key,f=0; 
    cout << "Enter value to search: "; cin >> key;
    for(int i=0;i<n;i++) {
        if(arr[i]==key)
           f=1;
           break;
    }
    if(f==1){
        cout << "Found at index " << i << '\n'; }
    else cout << "Not found.\n";
}

void main(){
    while(true){
        cout<< "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.BACK\n";
        cout<< "Enter choice: ";
        int ch; if(!(cin>>ch)) return;
        switch(ch){
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linearSearch(); break;
            case 6: return;
            default: cout << "Invalid choice!\n";
        }
    }
}
