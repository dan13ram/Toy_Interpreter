#ifndef _CONDEXPR_H
#define _CONDEXPR_H

#include"state.h"
#include"expression.h"
#include<iostream>

using namespace std;

class CondExpr{


        public :

        virtual bool eval(State& S) = 0;

};

class EqualExpr:public CondExpr{

        Expr* left;
        Expr* right;

        public:
        
        EqualExpr(){
                left=NULL;
                right=NULL;
        }
        EqualExpr(Expr* l, Expr* r){
                left = l;
                right = r;
        }
        bool eval(State& );
};

class NotEqualExpr:public CondExpr{

        Expr* left;
        Expr* right;

        public:

        NotEqualExpr(){
                left=NULL;
                right=NULL;
        }
        NotEqualExpr(Expr* l, Expr* r){
                left = l;
                right = r;
        }
        bool eval(State& );
};

class GEExpr:public CondExpr{

        Expr* left;
        Expr* right;

        public:
  
        GEExpr(){
                left=NULL;
                right=NULL;
        }
        GEExpr(Expr* l, Expr* r){
                left = l;
                right = r;
        }
        bool eval(State& );
};

class LEExpr:public CondExpr{
        
        Expr* left;
        Expr* right;

        public:

        LEExpr(){
                left=NULL;
                right=NULL;
        }
        LEExpr(Expr* l, Expr* r){
                left = l;
                right = r;
        }
        bool eval(State& );
};

class LessExpr:public CondExpr{

        Expr* left;
        Expr* right;

        public:
        LessExpr(){
                left=NULL;
                right=NULL;
        }
        LessExpr(Expr* l, Expr* r){
                left = l;
                right = r;
        }
        bool eval(State& );
};

class GreatExpr:public CondExpr{

        Expr* left;
        Expr* right;

        public:

        GreatExpr(){
                left=NULL;
                right=NULL;
        }
        GreatExpr(Expr* l, Expr* r){
                left = l;
                right = r;
        }
        bool eval(State& );
};

#endif //  _CONDEXPR_H
