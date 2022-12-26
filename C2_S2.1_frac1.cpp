/*
ID: edward.26
TASK: frac1
LANG: C++
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <cstdio>
#include <numeric>
using namespace std;
int n;
vector<pair<int,int>> ans;

bool cmp(pair<int,int> x, pair<int,int> y){
    return x.first * y.second < x.second * y.first;
}

int main(int argc, const char * argv[]) {
    
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    
    fin>>n;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            if(gcd(i, j) == 1){
                ans.push_back({j, i});
            }
        }
    }
    
    sort(ans.begin(), ans.end(), cmp);
    
    fout<<"0/1"<<endl;
    for(auto xx:ans){
        fout<<xx.first<<"/"<<xx.second<<endl;
    }
    fout<<"1/1"<<endl;
    return 0;
}
