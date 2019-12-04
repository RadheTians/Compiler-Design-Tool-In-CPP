#include<bits/stdc++.h>
using namespace std;

vector<string> keyword(string s){

    vector<string> temp;
    string keys[]={"asm","else","new","this","auto","enum","operator","throw","bool",
            "explicit","private","true","break","export","protected","try",
            "case","extern","public","typedef","catch","false","register",
            "typeid","char","float","reinterpret_cast","typename","class",
            "for","return","union","const","friend","short","unsigned",
            "const_cast","goto","signed","using","continue","if","sizeof",
            "virtual","default","inline","static","void","delete","int",
            "static_cast","volatile""do","long","struct","wchar_t",
            "double","mutable","switch","while","dynamic_cast","namespace","template","include","iostream","std","printf"};
    int rows = sizeof(keys)/sizeof(keys[0]);
    for(int i=0;i<rows;i++){
        if(s.find(keys[i]) !=-1)
            temp.push_back(keys[i]);

    }
    return temp;

}

vector<string> operators(string s){

    vector<string> temp;
    string keys[]= {"+", "-", "*", "/", "%", "=", "++",
                "--", "==", "+=", "-=", "*=",
                "/=", "!=", ">","<", ">=", "<=", "&&","||","!","<<",">>","&","^","|","%=","&=","^=","|=",",","?","?:"};
    int rows = sizeof(keys)/sizeof(keys[0]);
    for(int i=0;i<rows;i++){
        if(s.find(keys[i]) !=-1)
            temp.push_back(keys[i]);

    }
    return temp;

}

vector<string> delimiter(string s){

    vector<string> temp;
    string keys[]= {";",")","(","}","{","]","[","'"};
    int rows = sizeof(keys)/sizeof(keys[0]);
    for(int i=0;i<rows;i++){
        if(s.find(keys[i]) !=-1)
            temp.push_back(keys[i]);

    }
    return temp;

}


vector<string> LexicalAnalyzer(string path){

    string line;
    ifstream file;
    vector<string> result, temp;
    int l=1;

    file.open(path);
    while(file){
        getline(file,line);
        result.push_back("LINE : "+to_string(l)+"\n");

        result.push_back("---KEYWORDS---\n");
        string t="";
        temp = keyword(line);
        for(int i=0;i<temp.size();i++)
            t=t+temp[i]+"  ";
        t=t+"\n";
        result.push_back(t);

        result.push_back("---OPERATORS---\n");
        string o="";
        temp = operators(line);
        for(int i=0;i<temp.size();i++)
            o=o+temp[i]+"  ";
        o=o+"\n";
        result.push_back(o);

        result.push_back("---DELIMITER---\n");
        string d="";
        temp = delimiter(line);
        for(int i=0;i<temp.size();i++)
            d=d+temp[i]+"  ";
        d=d+"\n";
        result.push_back(d);

        l++;

    }
    file.close();
    return result;
}
