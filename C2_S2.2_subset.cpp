/*
ID: edward.26
TASK: subset
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
using namespace std;
long long n, f[45][1000];

int main(int argc, const char * argv[]) {
    
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    
    
    fin>>n;
    if(n * (n+1) % 4 != 0){
        fout<<0<<endl;
        return 0;
    }
    f[1][1] = 1;
    for(int i = 2;i<=n;i++){
        f[i][i] += 1;
        for(int j = 1;j<=i*(i+1)/2;j++){
            f[i][j] = f[i-1][j];
            if(j-i>=0){
                f[i][j] += f[i-1][j-i];
            }
            //f[i][j] += f[i-1][j-i];
        }
    }
    fout<<f[n][n*(n+1)/4]<<endl;
    return 0;
}
