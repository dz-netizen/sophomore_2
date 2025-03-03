//给定一个整数数组及一个target，寻找出两数之和为target的两个数字的下标
#include<iostream>
#include<vector>
class Solution{
    public:
    std::vector<int> twosum(std::vector<int>& num,int target);
};
std::vector<int> Solution::twosum(std::vector<int> &num,int target){
    std::vector<int> numindex;
    int len=num.size();
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(num[i]+num[j]==target){
                numindex.push_back(i);
                numindex.push_back(j);
                break;
            }
        }
    }
    return numindex;
}
int main(){
    std::vector<int> s={2,13,25,20,11,23,35,5,9};
    Solution solution;
    std::vector<int> result=solution.twosum(s,7);
    for(int it:result){
        std::cout<<it<<' ';
    }
    std::cout<<std::endl;

}
