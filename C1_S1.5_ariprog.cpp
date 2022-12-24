/*
ID: edward.26
TASK: ariprog
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
using namespace std;
int n, m;
vector<int> a;
vector<pair<int,int>> ans;
set<int> c;
bool f[125005];

//垃圾题目 用set就超时
int main(int argc, const char * argv[]) {
    
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    
    fin>>n>>m;
    int mx = 0;
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=m;j++){
            if(f[i*i+j*j] == 0){
                a.push_back(i*i+j*j);
                f[i*i+j*j] = 1;
                mx = max(mx, i*i+j*j);
            }
        }
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0;i<a.size();i++){
        for(int j = i+1;j<a.size();j++){
            if(a[j] == a[i]) continue;
            int d = a[j] - a[i];
            if(a[j] + (n-2)*d > mx) continue;
            bool flag = true;
            int temp = a[j];
            for(int i = 1;i<=n-2;i++){
                temp += d;
                if(f[temp] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back({d, a[i]});
            }
        }
    }
    if(ans.size() == 0){
        fout<<"NONE"<<endl;
        return 0;
    }
    
    sort(ans.begin(), ans.end());
    for(auto xx:ans){
        fout<<xx.second<<" "<<xx.first<<endl;
    }
    return 0;
}
