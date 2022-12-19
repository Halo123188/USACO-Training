/*
ID: edward.26
TASK: namenum
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

string s;
map<char, char> a;
string dic[5000];
int main(int argc, const char * argv[]) {
    
    ifstream din("dict.txt");
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    
    fin>>s;
    a['A'] = '2';
    a['B'] = '2';
    a['C'] = '2';
    a['D'] = '3';
    a['E'] = '3';
    a['F'] = '3';
    a['G'] = '4';
    a['H'] = '4';
    a['I'] = '4';
    a['J'] = '5';
    a['K'] = '5';
    a['L'] = '5';
    a['M'] = '6';
    a['N'] = '6';
    a['O'] = '6';
    a['P'] = '7';
    a['R'] = '7';
    a['S'] = '7';
    a['T'] = '8';
    a['U'] = '8';
    a['V'] = '8';
    a['W'] = '9';
    a['X'] = '9';
    a['Y'] = '9';
    
    string temp;
    int n = 0;
    while(din>>temp){
        //cin>>temp;
        n++;
        dic[n] = temp;
        //n++;
    }
    
    bool flag = false;
    for(int i = 1; i<=n;i++){
        if(dic[i].size() != s.size()){
            continue;
        }
        string t = "";
        for(int j = 0;j<dic[i].size();j++){
            t += a[dic[i][j]];
        }
        if(t == s){
            fout<< dic[i]<<endl;
            flag = true;
        }
        
    }
    
    if(flag == false){
        fout<<"NONE"<<endl;
    }
    return 0;
}
