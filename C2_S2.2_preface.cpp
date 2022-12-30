/*
ID: edward.26
TASK: preface
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
int n;
map<char, int> a;

void cal(char x, char y, char z, int i){
    if(i == 4){
        a[y]++;
        a[x]++;
        return;
    }
    if(i == 9){
        a[z]++;
        a[x]++;
        return;
    }
    a[x] += i % 5;
    if(i >= 5){
        a[y]++;
    }
}

int main(int argc, const char * argv[]) {
    
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    fin>>n;
    
    for(int i = 1;i<=min(9, n);i++){
        cal('I', 'V', 'X', i);
    }
    
    for(int i = 10;i<=min(99, n);i++){
        cal('I', 'V', 'X', i%10);
        cal('X', 'L', 'C', i/10);
    }
    
    for(int i = 100; i<= min(999, n);i++){
        cal('I', 'V', 'X', i%10);
        cal('X', 'L', 'C', (i/10)%10);
        cal('C', 'D', 'M', i/100);
    }
    
    for(int i = 1000; i<= min(9999, n);i++){
        cal('I', 'V', 'X', i%10);
        cal('X', 'L', 'C', (i/10)%10);
        cal('C', 'D', 'M', (i/100)%10);
        a['M'] += i/1000;
    }
    
    if(a.count('I') > 0){
        fout<<'I'<<" "<<a['I']<<endl;
    }
    if(a.count('V') > 0){
        fout<<'V'<<" "<<a['V']<<endl;
    }
    if(a.count('X') > 0){
        fout<<'X'<<" "<<a['X']<<endl;
    }
    if(a.count('L') > 0){
        fout<<'L'<<" "<<a['L']<<endl;
    }
    if(a.count('C') > 0){
        fout<<'C'<<" "<<a['C']<<endl;
    }
    if(a.count('D') > 0){
        fout<<'D'<<" "<<a['D']<<endl;
    }
    if(a.count('M') > 0){
        fout<<'M'<<" "<<a['M']<<endl;
    }
    
    return 0;
}
