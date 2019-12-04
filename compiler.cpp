#include "compiler.h"
#include "ui_compiler.h"

#include "RecursiveDescent.h"
#include "LexicalAnalyzer.h"
#include "LeftRecursion.h"
#include "LeftFactoring.h"
#include "FirstAndFollow.h"
#include "SLR.h"
#include <QMessageBox>

Compiler::Compiler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Compiler)
{
    ui->setupUi(this);
}

Compiler::~Compiler()
{
    delete ui;
}


void Compiler::on_fst_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Please check grammar..."));
    }else{
        vector<string> grammar;
        int a=0;
        for(int i=0;i<rdString.length();i++){
            if(rdString[i]=='\n' || rdString[i]=='\0'){
                grammar.push_back(rdString.substr(a,i-a));
                a=i+1;
            }
        }
        string pro[grammar.size()];
        for (int i =0;i<grammar.size();i++) {
            pro[i]=grammar[i];
        }
        string firstResult = FirstAndFollow().FirstMain(pro,grammar.size());

        ui->output->setPlainText(firstResult.c_str());
    }
}

void Compiler::on_flw_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Please check grammar..."));
    }else{
        vector<string> grammar;
        int a=0;
        for(int i=0;i<rdString.length();i++){
            if(rdString[i]=='\n' || rdString[i]=='\0'){
                grammar.push_back(rdString.substr(a,i-a));
                a=i+1;
            }
        }
        string pro[grammar.size()];
        for (int i =0;i<grammar.size();i++) {
            pro[i]=grammar[i];
        }
        string firstResult = FirstAndFollow().FollowMain(pro,grammar.size());

        ui->output->setPlainText(firstResult.c_str());
    }
}

void Compiler::on_faf_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Please check grammar..."));
    }else{
        vector<string> grammar;
        int a=0;
        for(int i=0;i<rdString.length();i++){
            if(rdString[i]=='\n' || rdString[i]=='\0'){
                grammar.push_back(rdString.substr(a,i-a));
                a=i+1;
            }
        }
        string pro[grammar.size()];
        for (int i =0;i<grammar.size();i++) {
            pro[i]=grammar[i];
        }
        string firstResult = FirstAndFollow().FstAndFlw(pro,grammar.size());

        ui->output->setPlainText(firstResult.c_str());
    }
}


void Compiler::on_lex_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string lapath = iptgrammar.toStdString();
    if(lapath.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Please check your path..."));
    }else{
        vector<string> laResult = LexicalAnalyzer(lapath);
        string opt="";
        for(int i=0;i<laResult.size();i++)
            opt=opt+laResult[i];
        ui->output->setPlainText(opt.c_str());
    }

}

void Compiler::on_lr_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Please check grammar..."));
    }else{
        vector<string> grammar;
        int a=0;
        for(int i=0;i<rdString.length();i++){
            if(rdString[i]=='\n'){
                grammar.push_back(rdString.substr(a,i-a));
                a=i+1;
            }
        }
        vector<string> result = Left_Recusrion(grammar);
        string rdResult="";
       for(auto i=result.begin();i!=result.end();i++){
           string s =*i;
           rdResult=rdResult+s+"\n";
        }
        ui->output->setPlainText(rdResult.c_str());
    }

}

void Compiler::on_lf_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Please check grammar..."));
    }else{
        vector<string> grammar;
        int a=0;
        for(int i=0;i<rdString.length();i++){
            if(rdString[i]=='\n'){
                grammar.push_back(rdString.substr(a,i-a));
                a=i+1;
            }
        }
        vector<string> result = Left_Factoring(grammar);
        string rdResult="";
        for(auto i=result.begin();i!=result.end();i++){
           string s =*i;
           rdResult=rdResult+s+"\n";
        }
        ui->output->setPlainText(rdResult.c_str());
    }
}

void Compiler::on_rd_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Empty String!"));
    }else{
        string rdResult = RecursiveDescent().RecursiveDescentMain(rdString+"$");
        ui->output->setPlainText(rdResult.c_str());
    }
}

void Compiler::on_slr_clicked()
{
    QString iptgrammar = ui->input->toPlainText();
    string rdString = iptgrammar.toStdString();
    if(rdString.length()==0){
        QMessageBox::question(this,tr("Alert"),tr("Empty String!"));
    }else{
        string rdResult = SLR(rdString);
        ui->output->setPlainText(rdResult.c_str());
    }
}
