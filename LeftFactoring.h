#include<bits/stdc++.h>
using namespace std;
vector<string> Left_Factoring(vector<string>);

vector<string> Left_Factoring(vector<string> production){
     vector<string> left, right, result,temp;
     for(auto i = production.begin(); i != production.end(); ++i){
        string s = *i;
        left.push_back(s.substr(0,s.find("#")));
        right.push_back(s.substr(s.find("#")+1,s.length()));
     }
     char c = right[0][0];
     for(int i = 0; i < right.size(); i++){
          if(c != right[i][0]) {
               result.push_back(left[i]+"#"+right[i]);
          } else {
               temp.push_back(right[i]);
          }
     }
     string str="";
     int x=0;
     for(int i = 0; i < temp[0].length(); i++){
          char c = temp[0][i];
          int flag = 0;
          for(int j=0;j < temp.size();j++){
              if(temp[j][i] == c){
                  continue;
              }else
              {
                   str = temp[0].substr(0,i);
                   flag = 1;
                   x = i;
                   break;
              }
          }
          if(flag == 1)
              break;
     }
     result.push_back(left[0]+"#"+str+left[0]+"'");
     for(int i=0;i<temp.size();i++){
          if(x==temp[i].length()){
              result.push_back(left[i]+"'#@");
          }else
          {
              result.push_back(left[i]+"'#"+temp[i].substr(x,temp[i].length()));
          }
     }
     return result;

}
