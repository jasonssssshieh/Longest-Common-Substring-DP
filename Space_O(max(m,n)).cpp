//
//  main.cpp
//  Longest Common Substring
//
//  Created by Zijian Xie on 2016/11/9.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class LongestComSubString{
private:
    string s1;
    string s2;
public:
    LongestComSubString(string& ss1, string& ss2){
        s1 = ss1;
        s2 = ss2;
    }
    
    int DP_max_m_n(){
        if(s1.size() < s2.size()) swap(s1,s2);
        vector<int> dp(s1.size() + 1,0);
        int res = INT_MIN;
        for(int i = 1; i < s2.size() + 1;++i){
            for(int j = (int)s1.size(); j >= 1; --j){
                if(s2[i-1] == s1[j-1]){
                    dp[j] = dp[j-1] + 1;
                    res = max(res,dp[j]);
                }else{
                    dp[j] = 0;
                }
            }
        }
        cout<< "The longest common substring is "<<res<<". "<<endl;
        return res;
    }
    
    int DP_M_N(){
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,0));
        int res = INT_MIN;
        for(int i = 1; i <= s1.size(); ++i){
            for(int j = 1; j <= s2.size();++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                }
                //else dp[i][j] = 0;
            }
        }
        cout<< "The longest common substring is "<<res<<". "<<endl;
        return res;
    }
    
    
};
int main(int argc, const char * argv[]) {
    string ss1 = "abcdaf";
    string ss2 = "zbcdf";
    LongestComSubString* test = new LongestComSubString(ss1,ss2);
    cout<<"Use space O(m*n): ";
    test->DP_M_N();
    cout<<endl;
    cout<<"Use space O(max(m,n)): ";
    test->DP_max_m_n();
    cout<<endl;
    return 0;
}
