/*
ID: edward.26
TASK: combo
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
int n,a[3],b[3];
int main(int argc, const char * argv[]) {
    
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    
    fin>>n;
    for(int i = 0;i<3;i++){
        fin>>a[i];
    }
    for(int i = 0;i<3;i++){
        fin>>b[i];
    }
    
    int ans;
    int ax = 0, ay = 0, az= 0, bx = 0, by = 0, bz = 0;
    int xx = 0, yy = 0, zz = 0;
    for(int i = 1;i<=n;i++){
        if(abs(i-a[0]) <= 2 || abs(i-a[0]-n) <= 2 || abs(i+n-a[0]) <= 2){
            ax++;
        }
        if(abs(i-b[0]) <= 2 || abs(i-b[0]-n) <= 2 || abs(i+n-b[0]) <= 2){
            bx++;
        }
        if(abs(i-a[1]) <= 2 || abs(i-a[1]-n) <= 2 || abs(i+n-a[1]) <= 2){
            ay++;
        }
        if(abs(i-b[1]) <= 2 || abs(i-b[1]-n) <= 2 || abs(i+n-b[1]) <= 2){
            by++;
        }
        if(abs(i-a[2]) <= 2 || abs(i-a[2]-n) <= 2 || abs(i+n-a[2]) <= 2){
            az++;
        }
        if(abs(i-b[2]) <= 2 || abs(i-b[2]-n) <= 2 || abs(i+n-b[2]) <= 2){
            bz++;
        }
        if((abs(i-a[0]) <= 2 || abs(i-a[0]-n) <= 2 || abs(i+n-a[0]) <= 2) && (abs(i-b[0]) <= 2 || abs(i-b[0]-n) <= 2 || abs(i+n-b[0]) <= 2)){
            xx ++;
        }
        if((abs(i-a[1]) <= 2 || abs(i-a[1]-n) <= 2 || abs(i+n-a[1]) <= 2) && (abs(i-b[1]) <= 2 || abs(i-b[1]-n) <= 2 || abs(i+n-b[1]) <= 2)){
            yy ++;
        }
        if((abs(i-a[2]) <= 2 || abs(i-a[2]-n) <= 2 || abs(i+n-a[2]) <= 2) && (abs(i-b[2]) <= 2 || abs(i-b[2]-n) <= 2 || abs(i+n-b[2]) <= 2)){
            zz ++;
        }
    }
    ans = ax*ay*az + bx*by*bz - xx*yy*zz;
    fout<<ans<<endl;
           
           
    return 0;
}
