#ifndef _IMPFUNC_H
#define _IMPFUNC_H

#include<string>
#include<vector>
#include"expression.h"
#include"condexpr.h"

#define NUMKEYS 9
#define NUMOPS 10

const string keys[]={"print","println","while","do","done","if","else","fi","skip"};
const string operators[]={"+","-","*","==", "!=", "<", "<=", ">", ">=",":="};

int getNum(string num);
bool isKey(string token);
bool isOp(string token);
bool isNum(string name);
bool isIden(string name);
bool correctToken(string token);
bool checkfiletype(char *a);
Expr* parseExpr(vector<string> expression);
CondExpr* parseCondExpr(vector<string> expression);

#endif //  _IMPFUNC_H
