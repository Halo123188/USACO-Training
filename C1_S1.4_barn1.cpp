/*
ID: edward.26
TASK: barn1
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

int m, s ,c, ans;
int a[205];
vector<pair<int,int>> b;

bool cmp(pair<int,int> x, pair<int,int> y){
    if(x.first == y.first){
        return x.second < y.second;
    }
    return x.first > y.first;
}
int main(int argc, const char * argv[]) {
    
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    
    fin>>m>>s>>c;
    for(int i = 1;i<=c;i++){
        fin>>a[i];
    }
    sort(a+1, a+1+c);
    for(int i = 2;i<=c;i++){
        b.push_back({a[i] - a[i-1], i-1});
    }
    
    sort(b.begin(), b.end(), cmp);
    
    int last = a[1];
    vector<int> cc;
    for(int i = 0;i<m-1;i++){
        if(cc.size() >= c-1){
            break;
        }
        cc.push_back(b[i].second);
    }
    
    sort(cc.begin(), cc.end());
    
//    for(int xxx:cc){
//        cout<<xxx<<" ";
//    }
//    cout<<endl;
    for(int i = 0;i<cc.size();i++){
        
        ans += (a[cc[i]] - last);
        last = a[cc[i]+1];
    }
    
    ans += min(m, c) + a[c] - last;
    fout<<ans<<endl;
   
    return 0;
}
