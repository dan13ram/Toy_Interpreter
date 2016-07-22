#include<iostream>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include"expression.h"
#include"condexpr.h"
#include"impfunc.h"

using namespace std;

int getNum(string num){
        stringstream ss;
        ss<<num;
        int temp=0;
        ss>>temp;
        return temp;
}

bool isKey(string token){
	for(unsigned int i=0;i<NUMKEYS;i++){
		if(token==keys[i])return true;
	}
	return false;
}	

bool isOp(string token){
	for(unsigned int i=0;i<NUMOPS;i++){
		if(token==operators[i])return true;
	}
	return false;
}	
bool isNum(string name){
	if(!((name[0]>='0'&&name[0]<='9')||(name[0]=='-')))return false;
	for(unsigned int i=1;i<name.size();++i){
	if(!(name[i]>='0'&&name[i]<='9'))return false;
	}
        if(name=="-")return false;
	return true;
}


bool isIden(string name){
	if(!((name[0]>='A'&&name[0]<='Z')||(name[0]>='a'&&name[0]<='z')||name[0]=='_'))return false;
	else for(unsigned int i=1;i<name.size();++i){
	if(!((name[i]>='A'&&name[i]<='Z')||(name[i]>='0'&&name[i]<='9')||(name[i]>='a'&&name[i]<='z')||name[i]=='_'))return false;
	}
	return !isKey(name);
}

bool correctToken(string token){
	return isKey(token)||isOp(token)||isIden(token)||isNum(token);
}


bool checkfiletype(char *a){
        int pos=-5;
        int len=0;
        for(len=0;a[len]!='\0';len++){
                if(a[len]=='.')pos=len;
        }
        pos++;
        if(pos!=len-2)return true;
        else if(a[pos]=='m'&&a[pos+1]=='y')return false;
        else return true;
}

Expr* parseExpr(vector<string> expression){
        stack<Expr* > temp;
        for(unsigned int i=0;i<expression.size();++i){
                if(expression[i]!="("){
                        if(expression[i]==")"){
                                Expr* b=temp.top();
                                temp.pop();
                                Expr* op=temp.top();
                                temp.pop();
                                Expr* a=temp.top();
                                temp.pop();
                                op->setExpr(a,b);
                                temp.push(op);
                        }
                        else {
                                string &t=expression[i];
                                if(isIden(t)){
                                      temp.push(new VarExpr(t));
                                }
                                else if(isNum(t)){
                                      temp.push(new ConstExpr(getNum(t)));
                                }
                                else if(t=="+"){
                                      temp.push(new PlusExpr());
                                }
                                else if(t=="-"){
                                      temp.push(new MinusExpr());
                                }
                                else if(t=="*"){
                                      temp.push(new StarExpr());
                                }
                                else {
                                        return NULL;
                                }
                        }
                }
        }
        return temp.top();
}

CondExpr* parseCondExpr(vector<string> expression){
        vector<string> exp1;
        unsigned int ind=-1;
        for(unsigned int i=0;i<expression.size();++i){
                if(expression[i]=="!=" || expression[i]=="==" || expression[i]==">=" 
                        || expression[i]=="<=" || expression[i]=="<" || expression[i]==">") {
                        ind = i;
                        break;
                }
                else exp1.push_back(expression[i]);
        }
        if( ind<=0 || ind>=expression.size()-1 ){
                return NULL;
        }
        else    {
                string op=expression[ind];
                expression.erase(expression.begin(),expression.begin()+ind+1);
                Expr *A=parseExpr(exp1);
                Expr *B=parseExpr(expression);
                if(op=="==")return new EqualExpr(A,B);
                else if(op=="<=")return new LEExpr(A,B);
                else if(op=="!=")return new NotEqualExpr(A,B);
                else if(op==">=")return new GEExpr(A,B);
                else if(op==">")return new GreatExpr(A,B);
                else if(op=="<")return new LessExpr(A,B);
                else {
                        return NULL;
                }
                
        }
}

