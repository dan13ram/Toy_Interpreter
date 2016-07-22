#include<iostream>
#include<cstdlib>
#include"expression.h"

using namespace std;

void PlusExpr::setExpr(Expr* l, Expr* r){
        left=l;
        right=r;
}

int PlusExpr::eval(State& S){
	if(left!=NULL&&right!=NULL)
                return left->eval(S) + right->eval(S);
        else {
                cerr<<"Runtime ERROR - Segmentation Fault"<<endl;
                exit(1);
        }
}



void MinusExpr::setExpr(Expr* l, Expr* r){
        left=l;
        right=r;
}

int MinusExpr::eval(State& S){
	if(left!=NULL&&right!=NULL)
	        return left->eval(S) - right->eval(S);
        else {
                cerr<<"Runtime ERROR - Segmentation Fault"<<endl;
                exit(1);
        }
}

void StarExpr::setExpr(Expr* l, Expr* r){
        left=l;
        right=r;
}

int StarExpr::eval(State& S){
	if(left!=NULL&&right!=NULL)
	        return left->eval(S) * right->eval(S);
        else {
                cerr<<"Runtime ERROR - Segmentation Fault"<<endl;
                exit(1);
        }
}

int ConstExpr::eval(State& S){
        (void)S;
        return (int)value;
}

string VarExpr::getName(){
        return name;
}

int VarExpr::eval(State& S){
        return S.getVal(name);
}


//int main(){
//        State S;
//        Expr* plus = new MinusExpr(new ConstExpr(7),new ConstExpr(8));
//        int value=plus->eval(S);
//        cout<<value;
//        return 0;
//}


