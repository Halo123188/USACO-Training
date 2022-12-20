/*
ID: edward.26
TASK: milk
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

int n,m;
vector<pair<int, int>> p;
long ans;

int main(int argc, const char * argv[]) {
    
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    
    fin>>n>>m;
    p.push_back({-1,-1});
    
    for(int i = 1;i<=m;i++){
        int tp, ta;
        fin>>tp>>ta;
        p.push_back({tp, ta});
    }
    
    sort(p.begin(), p.end());
    
    int i = 1;
    while(n > 0){
        if(p[i].second >= n){
            ans += n * p[i].first;
            n = 0;
        }
        else{
            ans += p[i].first * p[i].second;
            n -= p[i].second;
        }
        i++;
    }
    fout<<ans<<endl;
    return 0;
}
