#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include<string>
#include"state.h"

using namespace std;

class Expr{
        public:
        virtual string getName(){ 
                return "";
        }
        virtual void setExpr(Expr* l, Expr* r){
                (void)l;
                (void)r;
        }
        virtual int eval(State& S)=0;				//evaluates the expression and returns integer value
};


class PlusExpr:public Expr{

	Expr* left;
	Expr* right;

	public:

	PlusExpr(){
		left=NULL;
		right=NULL;
	}
	PlusExpr(Expr *l,Expr *r){
                left=l;
                right=r;
        }
        void setExpr(Expr* , Expr* );
	int eval(State& );
};

class MinusExpr:public Expr{

	Expr* left;
	Expr* right;

	public:

	MinusExpr(){
		left=NULL;
		right=NULL;
	}

	MinusExpr(Expr* l,Expr* r){ 
                left=l;
                right=r;
        }
        void setExpr(Expr* , Expr* );
        int eval(State& );
};

class StarExpr:public Expr{

	Expr* left;
	Expr* right;

	public:

	StarExpr(){
		left=NULL;
		right=NULL;
	}

	StarExpr(Expr *l,Expr *r){ 
                left=l;
                right=r;
        }
        void setExpr(Expr* , Expr* );
	int eval(State& );
};


class ConstExpr:public Expr{
        
        int value;

        public:

        ConstExpr(){
                value=0;
        }

        ConstExpr(int val){
                value=val ;
        }

        int eval(State& );
};


class VarExpr:public Expr{
        
        string name;

        public:

        VarExpr(){
                name="";
        }

        VarExpr(string nm){
                name=nm;
        }
        string getName();
        int eval(State& );
};

#endif // _EXPRESSION_H

