#include<iostream>
#include<algorithm>

using namespace std;

int arr1[3], arr2[3];

int main(void) {
    cin >> arr1[0] >> arr1[1] >> arr1[2] ;
    cin >> arr2[0] >> arr2[1] >> arr2[2];
    
    sort(arr1, arr1+3);
    sort(arr2, arr2+3);
    
    for(int i=0; i<3; i++) {
        if(arr1[i] != arr2[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if(arr1[0]*arr1[0] + arr1[1]*arr1[1] != arr1[2]*arr1[2]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
        
    return 0;
}