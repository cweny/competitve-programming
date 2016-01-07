#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

//window: array of sizes of contiguous non decreasing numbers or contiguous non increasing numbers
//window[i] = x means there are x contiguous non decreasing numbers. -x means x contiguous non increasing
//p1, p2: indexes to window, represent the start and end of the current window being evaluated
//ranges: number of subranges in the current window
int nums[100005], window[1000005], n, k, p1, p2, ranges;
vector<int> n_dec_ranges, n_inc_ranges;

int get_summation(int n) {
    if(n%2 == 0) return (n/2)*(n+1);
    return ((n+1)/2) * n;
}

void add_to_windows(int index) {
    if(window[p2] > 0 && nums[index] >= nums[index-1]) {
        ranges += get_summation(window[p2]+1) - get_summation(window[p2]);
        window[p2]++;
    } else if (window[p2] > 0) {
        p2++;
        window[p2] = -1;
    } else if(window[p2] < 0 && nums[index] < nums[index-1]) {
        window[p2]--;
    } else {
        p2++;
        window[p2] = 1;
        ranges += 1;
    }
}

void delete_from_windows(int index) {
    if(window[p1] > 0) {
        ranges -= (get_summation(window[p1]) - get_summation( window[p1]-1 ));
        window[p1]--;
    } else if(window[p1] < 0){
        window[p1]++;
    }
    if(window[p1] == 0) {
        p1++;
    }
}

void Main(vector<int> &vec) {
    p1 = p2 = 0;
    ranges = 0;
    
    //windows base case
    if(nums[1] <= nums[2]) {
        window[p2] = 1;
        ranges = 1;
    } else {
        window[p2] = -1;
    }
    
    //build initial window of size k
    for(int i=3; i<=k; i++) {
        add_to_windows(i);
    }
    vec.push_back(ranges);
    
    //move window through all numbers and compute ranges in each window
    for(int i=k+1; i<=n; i++) {
        add_to_windows(i);
        delete_from_windows(i-k);
        vec.push_back(ranges);
    }
    
}

//complexity: O(n)
int main(void) {
    cin >> n >> k;
    
    //if k==1, there are no subranges
    if(k==1) {
        for(int i=0; i<n-k+1; i++) {
            cout << 0 << endl;
        }
        return 0;
    }
    
    for(int i=1; i<=n; i++) {
        cin >> nums[i];
    }
    
    //compute all non decreasing subranges 
    Main(n_dec_ranges);
    for(int i=1; i<=n; i++) {
        nums[i] = -nums[i];
    }
    
    //compute all non increasing subranges
    Main(n_inc_ranges);
    
    for(int i=0; i<n-k+1; i++) {
        cout << n_dec_ranges[i] - n_inc_ranges[i] << endl;
    }
    
    return 0;    
}