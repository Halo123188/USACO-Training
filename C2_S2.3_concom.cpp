/*
ID: edward.26
TASK: concom
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

int n, m;
int a[105][105], vis[105], own[105], f[105];

void search(int p){
    if(vis[p] == 1) return;
    
    vis[p] = 1;
    for(int i = 1;i<=m;i++){
        f[i] += a[p][i];
        if(f[i] > 50){
            own[i]  = 1;
            search(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    
    fin>>n;
    
    for(int i = 1;i<=n;i++){
        int x, y, z;
        fin>>x>>y>>z;
        a[x][y] = z;
        m = max(m, max(x, y));
    }
    
    for(int i = 1;i<=m;i++){
        memset(vis, 0, sizeof vis);
        memset(own, 0, sizeof own);
        memset(f, 0, sizeof f);
        
        search(i);
        
        for(int j = 1;j<=m;j++){
            if(i != j && own[j] == 1){
                fout<<i<<" "<<j<<endl;
            }
        }
    }
    
    
   
    return 0;
}
