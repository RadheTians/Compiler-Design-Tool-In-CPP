
#include<bits/stdc++.h>
using namespace std;
vector<string> Left_Recusrion(vector<string>);
vector<string> Right(string,vector<string>);

vector<string> Right(string NT,vector<string> production){
    vector<string> result;
    for(int i=0;i<production.size();i++){
        if(production[i].substr(0,production[i].find("#")).find(NT)!=-1){
            result.push_back(production[i].substr(production[i].find("#")+1,production[i].length()));
        }
    }
    return result;
}


vector<string> Left_Recusrion(vector<string> production){
  set<string> left;
  vector<string> right, result, temp;
  for(auto i = production.begin();i!=production.end(); ++i){
      string s = *i;
      left.insert(s.substr(0,s.find("#")));
      right.push_back(s.substr(s.find("#")+1,s.length()));
  }
  for(auto i=left.begin();i!=left.end(); ++i){
      string NT = *i;
      vector<string> a;
      vector<string> b;
      temp = Right(NT,production);
      if(NT[0]==temp[0][0]){
        for(auto j=temp.begin();j!=temp.end(); ++j){
          string s = *j;
          if(NT[0]==s[0])
            a.push_back(s.substr(1,s.length()));
          else
            b.push_back(s);
        }

        for(auto j=b.begin();j!=b.end();j++){
          string s =*j;
          result.push_back(NT+"#"+s+NT+"'");
        }
        for(auto j=a.begin();j!=a.end();j++){
          string s =*j;
          result.push_back(NT+"'#"+s+NT+"'");
          result.push_back(NT+"'#@");
        }
      } else {
        for(int j=0;j<temp.size(); ++j)
          result.push_back(NT+"#"+temp[j]);
      }
  }
 return result;

}

