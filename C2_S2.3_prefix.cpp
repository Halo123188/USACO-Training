/*
ID: edward.26
TASK: prefix
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
#include <cmath>
#include <bitset>
using namespace std;

set<string> a[20];
string s;
int f[200030], mx;

int main(int argc, const char * argv[]) {
    
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    
    while(fin>>s){
        if(s == ".") break;
        a[s.size()].insert(s);
        mx = max(mx, (int)s.size());
    }
    
    string temp;
    s = " ";
    while(fin>>temp){
        s += temp;
    }
    
    f[0] = 1;
    
    int ans = 0;
    for(int i = 1;i<s.size();i++){
        for(int j = 1;j<= min(i, mx);j++){
            if(a[j].count(s.substr(i-j + 1, j)) != 0 && f[i-j] == 1){
                f[i] = f[i-j];
                ans = i;
                break;
            }
            //if(f[i] == 1) break;
        }
    }
    
    
    fout<<ans<<endl;
    return 0;
}
