#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float average(vector<float>& nums);
bool my_compare(float a, float b);

int main(){
    vector<float> nums;
    float n;
    while(cin >> n){
        nums.push_back(n);
    }
    sort(nums.begin(), nums.end(), my_compare);
    cout << "Maior: " << nums[nums.size()-1] << endl;
    cout << "Menor: " << nums[0] << endl;

    cout << "Média: " << average(nums) << endl;
}

float average(vector<float>& nums){
    float soma = 0;
    for(auto& e:nums){
        soma += e;
    }
    return soma / nums.size();
}

bool my_compare(float a, float b){
    return a < b;
}