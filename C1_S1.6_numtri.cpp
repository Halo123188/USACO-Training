/*
ID: edward.26
TASK: numtri
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
int n;
int f[1030][1030], a[1030][1030];

int main(int argc, const char * argv[]) {
    
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    
    fin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            fin>>a[i][j];
        }
    }
    
    f[1][1] = a[1][1];
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(j == 1){
                f[i][j] = max(f[i][j], a[i][j] + f[i-1][j]);
                continue;
            }
            if(j == i){
                f[i][j] = max(f[i][j], a[i][j] + f[i-1][j-1]);
                continue;
            }
            f[i][j] = max(f[i][j], a[i][j] + f[i-1][j]);
            f[i][j] = max(f[i][j], a[i][j] + f[i-1][j-1]);
        }
    }
    
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans = max(ans, f[n][i]);
    }
    fout<<ans<<endl;
    
    return 0;
}
