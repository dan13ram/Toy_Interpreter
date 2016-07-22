#ifndef _LINE_H
#define _LINE_H

#include<vector>
#include<utility>
#include<string>
#include"statement.h"

class Line{
        vector<pair<string,int> > tokens;
        int lineNum;

        public :
        Line (){
                lineNum=0;
        }
        Line (vector<pair<string,int> > temp, int n){
                tokens=temp;
                lineNum=n;
        }
        int numTokens();
        int getLine();
        void print();
        string getFirst();
        void error( );
        void error(string );
        void error(string , int );
        bool checkToken();
        Statement* createPrintStatement();
        Statement* createPrintlineStatement();
        Statement* createAssgStatement();
        IfStatement* createIfStatement();
        WhileStatement* createWhileStatement();

};


#endif // _LINE_H
