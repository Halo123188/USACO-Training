/*
ID: edward.26
TASK: zerosum
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


int n, sum;
vector<string> z;
char a[25];

void solve(int bef, int p){
    if(p == 2*n){
        if(sum == 0){
            string s = "";
            for(int i = 1;i<p;i++){
                s += a[i];
            }
            z.push_back(s);
        }
        return;
    }
    
    
    a[p] = ' ';
    sum -= bef;
    int b = 10*bef + (bef%10) +1;
    if(bef < 0){
        b = 10*bef + (bef%10) -1;
    }
    sum += b;
    
    solve(b, p+2);
    
    
    sum -= b;
    a[p] = '+';
    sum += bef;
    b = bef%10+1;
    if(bef < 0){
        b = (bef%10)*-1+1;
    }
    sum += b;
    
    solve(b, p+2);
    
    a[p] = '-';
    sum -= b;
    b *= -1;
    sum += b;
    
    solve(b, p+2);
    
    sum -= b;
}



int main(int argc, const char * argv[]) {
    
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    
    fin>>n;
    
    for(int i = 1;i<=n;i++){
        a[2*i-1] = '0'+i;
    }
    
    sum = 1;
    solve(1, 2);
    sort(z.begin(), z.end());
    for(auto xx:z){
        fout<<xx<<endl;
    }
    return 0;
}
