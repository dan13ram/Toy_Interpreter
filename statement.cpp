#include<iostream>
#include"statement.h"

using namespace std;

void PrintExprStatement::exec(State &S){
        if(p!=NULL)cout<<p->eval(S);
}

void PrintlineStatement::exec(State &S){
        (void)S;
        cout<<endl;
}

void PrintStringStatement::exec(State &S){
        (void)S;
        cout<<p;
}

void AssgStatement::exec(State& S){
        if(left!=NULL&&right!=NULL)
                S.setVar(left->getName(),right->eval(S));
}

void CompStatement::appendStatement(Statement *s){
        if(first == NULL){
                first = s;
        }
        else if(second == NULL ) {
                second = new CompStatement(s);
        }
        else {
                second->appendStatement(s);
        }
}
void CompStatement::exec(State& S){
        if(first!=NULL){
                first->exec(S);
        }
        if(second!=NULL){
                second->exec(S);
        }
}



void IfStatement::ifAppend(Statement *s){
        if(iftrue == NULL ) iftrue = new CompStatement(s);
        else iftrue->appendStatement(s);
}
void IfStatement::elseAppend(Statement *s){
        if(iffalse == NULL ) iffalse = new CompStatement(s);
        else iffalse->appendStatement(s);
}
void IfStatement::exec(State& S){
        if( cond->eval(S) ) {
                if(iftrue!=NULL)        iftrue->exec(S);
        }
        else {
                if(iffalse!=NULL)       iffalse->exec(S);
        }
}

void WhileStatement::insideAppend(Statement *s){
        if(inside == NULL ) inside = new CompStatement(s);
        else inside->appendStatement(s);
}
void WhileStatement::exec(State& S){
        while( cond->eval(S) ) {
                if(inside!=NULL)       inside->exec(S);
        }
}



//int main(){
//
//        State S;
//        Expr* var= new VarExpr("x");
//        Expr* val= new ConstExpr(75);
//        cout<<val->eval(S)<<endl;
//        Statement* a1= new AssgStatement(var,val);
//        Statement* c1= new CompStatement(a1);
//        Statement* c2= new CompStatement(new AssgStatement(new VarExpr("y"),new PlusExpr(new ConstExpr(5),new ConstExpr(6)) ),c1);
//        Statement* a2= new AssgStatement(var,new ConstExpr(88));
//        S.print();
//        c2->exec(S);
//        S.print();
//        a2->exec(S);
//        S.print();
//        return 0;
//}
