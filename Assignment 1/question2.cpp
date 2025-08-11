include<iostream>
using namespace std;
int size;
int Array[50];
void create(){
    cout << "Enter number of elements\n";
    cin >> size;
    for(int i = 0; i < size; i++) {
        cout << "Enter element" << i+1<<"\n";
        cin >> Array[i];
    }
}
    
void display()
{
    for(int i = 0; i < size; i++) {
        cout << Array[i] << "\n";
    }
}


void duplicate_remove(){
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(Array[i] == Array[j]) {
                for(int k = j; k < size - 1; k++) {
                    Array[k] = Array[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}
void main(){
    create();
    duplicate_remove();
    cout<<"The array is:\t";
    display();
}




