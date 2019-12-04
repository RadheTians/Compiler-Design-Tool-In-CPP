
#include <bits/stdc++.h>
using namespace std;

class FirstAndFollow{

    private:
        vector<char> ntermnl;
        int ntlen;
        vector<string> gram[10];
        vector<string> fst,flw;

    public:
        string FstAndFlw(string production[],int no) {
            int i;
            set<char> NT;
            string result="";
            for(int x=0;x<no;x++) {
                NT.insert(production[x][0]);
            }
            ntlen=NT.size();
            for(auto iter=NT.begin();iter!=NT.end();iter++) {
                char s= *iter;
                ntermnl.push_back(s);
            }
            int e=0;
            for (auto it=NT.begin();it!=NT.end(); it++) {
                char s =*it;
                vector<string> pro;
                for(int y=0;y<no;y++) {
                    if(production[y][0]==s)
                        pro.push_back(production[y].substr(2,production->length()));
                }
                for(auto iter=pro.begin();iter!=pro.end();iter++) {
                    string s= *iter;
                    gram[e].push_back(s);
                }
                e++;
            }
            for(i=0;i<ntlen;i++){
                string s = first(i);
                set<char> f;
                for(int j=0;j<s.length();j++)
                    f.insert(s[j]);
                s="";
                for(auto j=f.begin();j!=f.end();j++)
                    s=s+*j;
                fst.push_back(s);
            }
            for(i=0;i<ntlen;i++){
                string s = follow(i);
                set<char> f;
                for(int j=0;j<s.length();j++)
                    f.insert(s[j]);
                s="";
                for(auto j=f.begin();j!=f.end();j++)
                    s=s+*j;
                flw.push_back(s);
            }
            result = result+"FIRST SET\n";
            for(i=0;i<ntlen;i++)
                result = result+ntermnl[i]+" : "+fst[i]+"\n";
            result = result+"FOLLOW SET\n";
            for(i=0;i<ntlen;i++)
                result = result+ntermnl[i]+" : "+flw[i]+"\n";
            return result;
        }
        string FirstMain(string production[],int no) {
            int i;
            set<char> NT;
            string result="";
            for(int x=0;x<no;x++) {
                NT.insert(production[x][0]);
            }
            ntlen=NT.size();
            for(auto iter=NT.begin();iter!=NT.end();iter++) {
                char s= *iter;
                ntermnl.push_back(s);
            }
            int e=0;
            for (auto it=NT.begin();it!=NT.end(); it++) {
                char s =*it;
                vector<string> pro;
                for(int y=0;y<no;y++) {
                    if(production[y][0]==s)
                        pro.push_back(production[y].substr(2,production->length()));
                }
                for(auto iter=pro.begin();iter!=pro.end();iter++) {
                    string s= *iter;
                    gram[e].push_back(s);
                }
                e++;
            }
            for(i=0;i<ntlen;i++){
                string s = first(i);
                set<char> f;
                for(int j=0;j<s.length();j++)
                    f.insert(s[j]);
                s="";
                for(auto j=f.begin();j!=f.end();j++)
                    s=s+*j;
                fst.push_back(s);
            }

            result = result+"FIRST SET\n";
            for(i=0;i<ntlen;i++)
                result = result+ntermnl[i]+" : "+fst[i]+"\n";
            return result;
        }
        string FollowMain(string production[],int no) {
            int i;
            set<char> NT;
            string result="";
            for(int x=0;x<no;x++) {
                NT.insert(production[x][0]);
            }
            ntlen=NT.size();
            for(auto iter=NT.begin();iter!=NT.end();iter++) {
                char s= *iter;
                ntermnl.push_back(s);
            }
            int e=0;
            for (auto it=NT.begin();it!=NT.end(); it++) {
                char s =*it;
                vector<string> pro;
                for(int y=0;y<no;y++) {
                    if(production[y][0]==s)
                        pro.push_back(production[y].substr(2,production->length()));
                }
                for(auto iter=pro.begin();iter!=pro.end();iter++) {
                    string s= *iter;
                    gram[e].push_back(s);
                }
                e++;
            }
            for(i=0;i<ntlen;i++){
                string s = first(i);
                set<char> f;
                for(int j=0;j<s.length();j++)
                    f.insert(s[j]);
                s="";
                for(auto j=f.begin();j!=f.end();j++)
                    s=s+*j;
                fst.push_back(s);
            }
            for(i=0;i<ntlen;i++){
                string s = follow(i);
                set<char> f;
                for(int j=0;j<s.length();j++)
                    f.insert(s[j]);
                s="";
                for(auto j=f.begin();j!=f.end();j++)
                    s=s+*j;
                flw.push_back(s);
            }
            result = result+"FOLLOW SET\n";
            for(i=0;i<ntlen;i++)
                result = result+ntermnl[i]+" : "+flw[i]+"\n";
            return result;
        }
        string first(int i) {
            int found=0;
            string temp="",str="";
            for(int j=0;j<gram[i].size();j++)
            {
                for(int k=0;k<gram[i][j].length();k++,found=0)
                {
                    for(int l=0;l<ntlen;l++)
                    {
                        if(gram[i][j][k]==ntermnl[l])
                        {
                            str=first(l);
                            if(!(str.length()==1 && str[0]=='@'))
                                for(int z=0;z<str.length();z++) {
                                    if(str[z]!='@')
                                        temp=temp+str[z];
                                }
                            found=1;
                            break;
                        }
                    }
                    if(found==1)
                    {
                        if(str.find("@")!=0)
                            continue;
                    }
                    else
                        temp=temp+gram[i][j][k];
                    break;
                }
            }
            return temp;
        }
        string follow(int i) {
            vector<char> pro,chr;
            string temp="";
            int j,k,l,m,n,found=0;
            if(i==0)
            temp="$";
            for(j=0;j<ntlen;j++)
            {
                for(k=0;k<gram[j].size();k++)
                {
                    for(int z=0;z<gram[j][k].length();z++)
                    pro.push_back(gram[j][k][z]);
                    for(l=0;l<pro.size();l++)
                    {
                        if(pro[l]==ntermnl[i])
                        {
                            if(l==pro.size()-1)
                            {
                                if(j<i)
                                    temp=temp+flw[j];
                            }
                            else
                            {
                                for(m=0;m<ntlen;m++)
                                {
                                    if(pro[l+1]==ntermnl[m])
                                    {
                                        for(int z=0;z<fst[m].length();z++)
                                        chr.push_back(fst[m][z]);
                                        for(n=0;n<chr.size();n++)
                                        {
                                            if(chr[n]=='@')
                                            {
                                                if(l+1==pro.size()-1)
                                                    temp=temp+follow(j);
                                                else
                                                    temp=temp+follow(m);
                                            }
                                            else
                                                temp=temp+chr[n];
                                        }
                                        found=1;
                                    }
                                }
                                if(found!=1)
                                    temp=temp+pro[l+1];
                            }
                        }
                    }
                }
            }
            return temp;
        }
};

