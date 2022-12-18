/*
ID: edward.26
TASK: transform
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
string a[15], b[15], c[15];
int check(string a[15], string b[15]){
    bool flag = true;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != b[j][n-1-i]){
                flag = false;
                //cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<b[j][n-1-i]<<endl;
                //break;
            }
        }
    }
    if(flag == true){
        return 1;
    }
    flag = true;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != b[n-1-i][n-1-j]){
                flag = false;
            }
        }
    }
    if(flag == true){
        return 2;
    }
    flag = true;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != b[n-1-j][i]){
                flag = false;
            }
        }
    }
    if(flag == true){
        return 3;
    }
    return -1;
    
}
int main(int argc, const char * argv[]) {
    
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    fin>>n;
    for(int i = 0;i<n;i++){
        fin>>a[i];
        c[i] = a[i];
    }
    
    for(int i = 0;i<n;i++){
        fin>>b[i];
    }
    
    int t = check(a, b);
    if(t != -1){
        fout<<t<<endl;
        return 0;
    }
    
    bool flag = true;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != b[i][n-1-j]){
                flag = false;
            }
        }
    }
    if(flag == true){
        fout<<4<<endl;
        return 0;
    }
    flag = true;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            c[i][n-1-j] = a[i][j];
        }
    }
    t = check(c, b);
    if(t != -1){
        fout<<5<<endl;
        return 0;
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != b[i][j]){
                flag = false;
            }
        }
    }
    if(flag == true){
        fout<<6<<endl;
        return 0;
    }
    fout<<7<<endl;
    
    return 0;
}
