#include<algorithm>
#include<iostream>

using namespace std;
int N;
int nums[100005];

int main(void) {
    int T;
    int test_case=1; 
    cin >> T;
    while(--T) {
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> nums[i];
        }
        int res=0;
        
        for(int i=0; i<N; i++) {
            if((i+res)%4==3) {
                continue;
            }
            
            
            int nee = 3-(i+res)%4;
            
            if(i==N-1) {
                res += nee;
                continue;
            }
            int a=nums[i], b=nums[i+1];
            if(b>a && b-a <=10) {
                continue;
            }
            
            
            if(a>=b) {
                res += nee;
                --i;
            } 
            
            else if(b - a <= 20) {
                res++;
                if(nee==1) {
                    --i;
                }
            } 
            
            else if(b - a <= 30) {
                if(nee==3) {
                    res = res + 2;
                } 
                
                else {
                    res += nee;
                    --i;
                }
            } 
            
            else {
                res += nee;
                --i;
            }
        }
        
        cout << "Case #" << test_case << ": " << res << endl;
        
        
        test_case++;
    }
    return 0;
}