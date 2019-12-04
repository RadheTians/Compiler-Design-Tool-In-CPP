#include<iostream>
using namespace std;


/**
 *
 * @author radhetians
 * E->TE'
 * E'->+TE'|NULL
 * T->FT'
 * T'->*FT'|NULL
 * F->(E)|a
 */


class RecursiveDescent{

    public:
        string inputString="";
        char lookahead='$';
        int len = 0;

    string RecursiveDescentMain(string input){
        inputString = input;
        Match();
        E();
        if(lookahead == '$')
            return "Accept";
        else
            return "Error";
    }

    void Match() {
        lookahead = inputString[len++];
    }
    void E() {
        T();
            EDS();
    }
    void EDS() {
        if(lookahead == '+') {
            Match();
            T();
            EDS();
        }
        else
            return;
    }
    void T() {
        F();
        TDS();
    }
    void TDS() {
        if(lookahead == '*') {
            Match();
            F();
            TDS();
        }
        else
            return;
    }
    void F() {
        if(lookahead == '(') {
            Match();
            E();
            if(lookahead == ')') {
                Match();
            }
        }
        else
            Match();
    }

};
