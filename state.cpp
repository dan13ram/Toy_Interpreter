#include"state.h"
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<cstdlib>

using namespace std;

int State::getVal(string nm){
	for(unsigned int i=0;i<varCol.size();++i){
		if(nm==varCol[i].first)return varCol[i].second;
	}
	cerr<<"Runtime ERROR - Variable '"<<nm<<"' has not been declared."<<endl;
        exit(1);
}

bool State::exists(string nm){
        for(unsigned int i=0;i<varCol.size();++i){
                if(nm==varCol[i].first)return true;
        }
        return false;
} 


void State::setVar(string nm,int value){
        for(unsigned int i=0;i<varCol.size();++i){
                if(nm==varCol[i].first){
                        varCol[i].second = (value);
                        return;
                }
        }
        varCol.push_back(make_pair(nm,value));
}

void State::print(){
        if(varCol.empty()){
                cout<<"There are no variables in the state ! "<<endl;
        }
        else {
                for(unsigned int i=0;i<varCol.size();++i){
                        cout<<"Var "<<i+1<<" : "<<varCol[i].first<<" : "<<varCol[i].second<<endl;
                }
        }
}

//int main(){
//        State S;
//        S.print();
//        S.setVar("x",11);
//        S.setVar("y",1211);
//        S.setVar("a",114);
//        S.setVar("b",131);
//        S.print();
//        return 0;
//} 
