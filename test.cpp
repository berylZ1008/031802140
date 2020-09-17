#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int main(int argc, const char * argv[]) {
    string files[]={
        "orig_0.8_add.txt",
        "orig_0.8_del.txt",
        "orig_0.8_dis_1.txt",
        "orig_0.8_dis_3.txt",
        "orig_0.8_dis_7.txt",
        "orig_0.8_dis_10.txt",
        "orig_0.8_dis_15.txt",
        "orig_0.8_mix.txt",
        "orig_0.8_rep.txt"
    };
    string path;
    string path1="main.exe sim_0.8/orig.txt sim_0.8/";
    string path2=" result.txt";
    for(int i=0;i<9;i++){
        cout<<"文件orig.txt与文件" <<files[i]<< "的相似度："<<endl;
        path=path1+files[i]+path2;
        system(path.c_str());
        cout<<endl;
    }
    return 0;
}

