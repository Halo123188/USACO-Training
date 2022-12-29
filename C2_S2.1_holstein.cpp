/*
ID: edward.26
TASK: holstein
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
int n, m;
int a[30], s[20][30], used[20], c[30];
vector<int> ans, t;

bool check(){
    for(int i = 1;i<=n;i++){
        if(c[i] < a[i]){
            return false;
        }
    }
    return true;
}

void cal(int pos){
    
    bool res = check();
    if(res){
        if(ans.size() > t.size() || ans.size() == 0){
            ans = t;
        }
        else if(ans.size() == t.size()){
            vector<int> temp = t;
            sort(ans.begin(), ans.end());
            sort(temp.begin(), temp.end());
            for(int i = 0;i<ans.size();i++){
                if(temp[i] < ans[i]){
                    ans = temp;
                    break;
                }
                else if(temp[i] > ans[i]){
                    break;
                }
            }
            
        }
        return;
    }
    if(pos >= m+1){
        return;
    }
    
    
    for(int i = 1;i<=n;i++){
        c[i] += s[pos][i];
    }
    t.push_back(pos);
    cal(pos+1);
    
    t.pop_back();
    for(int i = 1;i<=n;i++){
        c[i] -= s[pos][i];
    }
    cal(pos+1);
    
    
}

int main(int argc, const char * argv[]) {
    
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    
    fin>>n;
    for(int i = 1;i<=n;i++){
        fin>>a[i];
    }
    fin>>m;
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            fin>>s[i][j];
        }
    }
    
    cal(1);
    sort(ans.begin(), ans.end());
    fout<<ans.size();
    for(auto xx:ans){
        fout<<" "<<xx;
    }
    fout<<endl;
    
    
    return 0;
}
