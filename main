#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "cppjieba/include/cppjieba/Jieba.hpp"
using namespace std;
string GbkToUtf8(const char *src_str)//gbk编码文件转utf-8编码 
{
	int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, src_str, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	string strTemp = str;
	if (wstr) delete[] wstr;
	if (str) delete[] str;
	return strTemp;
}

string Utf8ToGbk(const char *src_str)//utf-8编码文件转gbk编码 
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}
string textread(char const *argv)//文件读入 
{
	ifstream infile;
	string t,s;
	s="\0"; 
 
	infile.open(argv);
	if (!infile.is_open()){
		cout << "open file failure!" << endl;
	}
		
	while (!infile.eof())
	{
		infile >> t;
		s += t;
	}
	infile.close();
 	
	const char* p = s.data();
 	s = GbkToUtf8(p);
 	return p;
	
}


float jaccard(vector<string> a,vector<string> b){
    int common=0;
    float sim=0;
    for(int i=0;i<a.size()-1;++i){
        for(int j=0;j<b.size()-1;++j){
            if(a[i]==b[j]){
                common+=1;
            }
        }
    }
    float sum=a.size()+b.size()-common;
    sim=common/sum;
    return sim;
}
void writeout(char const *argv,double result){//文件写入 
	ofstream outfile;
	if (!outfile.is_open()){
		cout << "open outfile failure!" << endl;
	} 
	
	outfile.open(argv);	
	outfile<<fixed<<setprecision(2)<<result<<endl;
	outfile.close();
}
int main(int argc,char const *argv[]) {
    const char* const DICT_PATH = "cppjieba/dict/jieba.dict.utf8";
    const char* const HMM_PATH = "cppjieba/dict/hmm_model.utf8";
    const char* const USER_DICT_PATH = "cppjieba/dict/user.dict.utf8";
    const char* const IDF_PATH = "cppjieba/dict/idf.utf8";
    const char* const STOP_WORD_PATH = "cppjieba/dict/stop_words.utf8";
    cppjieba::	Jieba jieba(DICT_PATH,HMM_PATH,USER_DICT_PATH,IDF_PATH,STOP_WORD_PATH);	
    string s1,s2;
    s1="\0";
    s2="\0";
    vector<string>a,b;
    s1=textread(argv[1]);
    jieba.Cut(s1,a,true);
    sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()), a.end());
    s2=textread(argv[2]);
    jieba.Cut(s2,b,true);
    sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()), b.end());
    float sim=jaccard(a,b);
    writeout(argv[3],sim);
    return 0;
}
