#ifndef _STATEMENT_H
#define _STATEMENT_H

#include"expression.h"
#include"condexpr.h"

class Statement{

        public:
        virtual void exec (State& S) = 0;
};

class PrintExprStatement:public Statement{
        Expr *p;
        public :
        
        PrintExprStatement(){
                p=NULL;
        }
        PrintExprStatement(Expr *print){
                p=print;
        }
        void exec(State&);
};

class PrintlineStatement:public Statement {
        public :
        void exec(State&);
};

class PrintStringStatement:public Statement{
        string p;
        public :

        PrintStringStatement(){
                p="";
        }
        PrintStringStatement(string print){
                p=print;
        }
        void exec(State&);
};

class AssgStatement: public Statement {
        Expr *left;
        Expr *right;
        public :
        AssgStatement(){
                left=NULL;
                right=NULL;
        }
        AssgStatement(Expr* l,Expr* r){
                left=l;
                right=r;
        }
        void exec(State& );
};

class CompStatement: public Statement {
        Statement *first;
        CompStatement *second;
        public :
        CompStatement(){
                first = NULL;
                second = NULL;
        }
        CompStatement(Statement *f,Statement *s=NULL){
                first = f;
                if(s!=NULL){
                        second = new CompStatement(s);
                }
                else second = NULL;
        }
        void appendStatement(Statement*);
        void exec(State& );
};

class IfStatement: public Statement {
        CompStatement *iftrue;
        CompStatement *iffalse;
        CondExpr* cond;
        public :
        IfStatement(){
                iftrue=NULL;
                iffalse=NULL;
                cond=NULL;
        }
        IfStatement(CondExpr* c){
                iftrue=NULL;
                iffalse=NULL;
                cond=c;
        }
        void ifAppend(Statement*);
        void elseAppend(Statement*);
        void exec(State& );
};

class WhileStatement: public Statement {
        CompStatement *inside;
        CondExpr* cond;
        public :
        WhileStatement(){
                inside=NULL;
                cond=NULL;
        }
        WhileStatement(CondExpr* c){
                inside=NULL;
                cond=c;
        }
        void insideAppend(Statement*);
        void exec(State& );
};

#endif //  _STATEMENT_H

