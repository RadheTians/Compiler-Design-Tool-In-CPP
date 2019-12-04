#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int z = 0, i = 0, j = 0, c = 0;
char a[40], ac[50], stk[40], act[20];
string result="";

/**
 *
 * @author radhetians
 * E->aEa
 * E->bEb
 * E->c
 */


void check()
{

    strcpy(ac,"R E -> ");
    for(z = 0; z < c; z++)
    {
        if(stk[z] == 'c')
        {
            result=result+ac+"c";
            stk[z] = 'E';
            stk[z + 1] = '\0';
            result=result+"\n$"+stk+"\t"+a+"$\t";
        }
    }

    for(z = 0; z < c - 2; z++)
    {
        if(stk[z] == 'a' && stk[z + 1] == 'E' && stk[z + 2] == 'a')
        {
            result = result+ac+"aEa";
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            result=result+"\n$"+stk+"\t"+a+"$\t";
            i = i - 2;
        }
    }

    for(z=0; z<c-2; z++)
    {

        if(stk[z] == 'b' && stk[z + 1] == 'E' && stk[z + 2] == 'b')
        {
            result=result+ac+"bEb";
            stk[z]='E';
            stk[z + 1]='\0';
            stk[z + 1]='\0';
            result=result+"\n$"+stk+"\t"+a+"$\t";
            i = i - 2;
        }
    }
    return ;
}

string SLR(string a)
{

    c=a.length();
    strcpy(act,"S");
    result = result+"stack\t\tinput\taction";
    for(i = 0; j < c; i++, j++)
    {
        result = result+act;
        stk[i] = a[j];
        stk[i + 1] = '\0';
        a[j]=' ';
        result = result+"\n$"+stk+"\t"+a+"$\t";
        check();
    }
    check();
    if(stk[0] == 'E' && stk[1] == '\0')
        result = result+"Accept\n";
    else
        result = result+"Reject\n";
    return result;
}

