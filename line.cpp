#include<iostream>
#include"line.h"
#include"impfunc.h"

using namespace std;

int Line::numTokens(){
        return tokens.size();
}
int Line::getLine(){
        return lineNum;
}
void Line::print(){
        if(lineNum!=0){
                cout<<"Line number is "<<lineNum<<endl;
        }
        if(tokens.empty()){
                cout<<"Line is empty."<<endl;
        }
        else {
                for(unsigned int i=0;i<tokens.size();++i){
                        cout<<tokens[i].first<<" at column number "<<tokens[i].second<<endl;
                }
        }
}
string Line::getFirst(){
        return tokens[0].first;
}
void Line::error(){
        string temp="General Syntax Error.";
        int ind=0;
        cerr<<"Line:"<<lineNum<<" Column:"<<tokens[ind].second<<" - ERROR - "<<temp<<endl;
}
void Line::error(string temp){
        int ind=0;
        cerr<<"Line:"<<lineNum<<" Column:"<<tokens[ind].second<<" - ERROR - "<<temp<<endl;
}
void Line::error(string temp, int ind){
        cerr<<"Line:"<<lineNum<<" Column:"<<tokens[ind].second<<" - ERROR - "<<temp<<endl;
}
bool Line::checkToken(){
        if(!correctToken(tokens[0].first)){
                cerr<<"Line:"<<lineNum<<" Column:"<<tokens[0].second<<" - ERROR - Invaid token. - '"<<tokens[0].first<<"'"<<endl;
                return false;
        }
        else return true;
}
Statement* Line::createPrintStatement(){
        if((tokens[1].first)[0]=='"'){
                if(tokens.size()>2){
                        error("Unexpected tokens in 'print' Statement. ");
                        return NULL;
                }
                string temp;
                for(unsigned int i=1;i<tokens[1].first.size()-1;++i){
                        temp.push_back((tokens[1].first)[i]);
                }
                return new PrintStringStatement(temp);
        }
        else {
                vector<string> expr;
                for(unsigned int i=1;i<tokens.size();++i){
                        expr.push_back(tokens[i].first);
                }
                Expr* temp = parseExpr(expr);
                if(temp==NULL){
                        error("Incorrect Expr. in 'print' Statement",2);
                        return NULL;
                }
                else return new PrintExprStatement(temp);
        }
}
Statement* Line::createPrintlineStatement(){
        if(tokens.size()>1){
                error("Unexpected tokens in 'println' Statement. ");
                return NULL;
        }
        else return new PrintlineStatement();
}
WhileStatement* Line::createWhileStatement(){
        if(tokens.back().first!="do"){
                error("Missing 'do' token in 'while' Statement. ",tokens.size()-1);
                return NULL;
        }
        vector<string> expr;
        for(unsigned int i=1;i<tokens.size()-1;++i){
                expr.push_back(tokens[i].first);
        }
        CondExpr* temp = parseCondExpr(expr);
        if(temp==NULL){
                error("Incorrect Conditional Expr. in 'while' Statement\n\t\t\t  Format must be -\t<Expr> <CondOp> <Expr> ",1);
                return NULL;
        }
        else return new WhileStatement(temp);
}
IfStatement* Line::createIfStatement(){
        if(tokens.back().first!="then"){
                error("Missing 'then' token in 'if' Statement. ",tokens.size()-1);
                return NULL;
        }
        vector<string> expr;
        for(unsigned int i=1;i<tokens.size()-1;++i){
                expr.push_back(tokens[i].first);
        }
        CondExpr* temp = parseCondExpr(expr);
        if(temp==NULL){
                error("Incorrect Conditional Expr. in 'if' Statement\n\t\t\t  Format must be -\t<Expr> <CondOp> <Expr> ",1);
                return NULL;
        }
        else return new IfStatement(temp);
}
Statement* Line::createAssgStatement(){
        if(tokens.size()<3){
                error("Syntax Error in Assignment.");
                return NULL;

        }
        else if(!(tokens[1].first==":=")){
                error("Syntax Error in Assignment - No Assigment Operator ':='",1);
                return NULL;
        }
        else {
                vector<string> expr;
                for(unsigned int i=2;i<tokens.size();++i){
                        expr.push_back(tokens[i].first);
                }
                Expr* temp= parseExpr(expr);
                if(temp==NULL){
                        error("Incorrect Expr. in Assignment",2);
                        return NULL;
                }
                else return new AssgStatement( new VarExpr(tokens[0].first), temp );
        }
}


//int main(){
//        State S;
//        vector<string> temp;
//        temp.push_back("(");
//        temp.push_back("8");
//        temp.push_back("-");
//        temp.push_back("7");
//        temp.push_back(")");
//        Expr* t=parseExpr(temp);
//        cout<<t->eval(S);
//        cout<<endl;
//        return 0;
//}
