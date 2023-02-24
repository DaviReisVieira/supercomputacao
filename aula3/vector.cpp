#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool my_compare(float a, float b);

int main(){
    vector<float> nums;
    nums.push_back(10.5);
    nums.push_back(4.0);
    nums.push_back(3.0);

    
    for(auto& e:nums){
        cout << e << endl;
    }
    sort(nums.begin(), nums.end(), my_compare);
    for(auto& e:nums){
        cout << e << endl;
    }
}

bool my_compare(float a, float b){
    return a < b;
}