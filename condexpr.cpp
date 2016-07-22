#include"condexpr.h"

using namespace std;

bool EqualExpr::eval(State& S){
        if(left!=NULL&&right!=NULL)return ( left->eval(S) == right->eval(S) );
        else return false;
}       

bool NotEqualExpr::eval(State& S){
        if(left!=NULL&&right!=NULL)return ( left->eval(S) != right->eval(S) );
        else return false;
}

bool GEExpr::eval(State& S){
        if(left!=NULL&&right!=NULL)return ( left->eval(S) >= right->eval(S) );
        else return false;
}

bool LEExpr::eval(State& S){
        if(left!=NULL&&right!=NULL)return ( left->eval(S) <= right->eval(S) );
        else return false;
}

bool LessExpr::eval(State& S){
        if(left!=NULL&&right!=NULL)return ( left->eval(S) < right->eval(S) );
        else return false;
}

bool GreatExpr::eval(State& S){
        if(left!=NULL&&right!=NULL)return ( left->eval(S) > right->eval(S) );
        else return false;
}

//int main(){
//        State S;
//        Expr * a = new ConstExpr(7);
//        Expr * b = new ConstExpr(5);
//        CondExpr * c = new GEExpr(a,b);
//        if(c->eval(S)) cout <<a->eval(S)<<" is greater than or equal to "<<b->eval(S)<<endl;
//        else cout <<a->eval(S)<<" is less than or equal to "<<b->eval(S)<<endl;
//        return 0;
//
//}
