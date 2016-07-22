#include<iostream>
#include<cstdlib>
#include<vector>
#include"state.cpp"
#include"line.cpp"
#include"impfunc.cpp"
#include"statement.cpp"
#include"expression.cpp"
#include"condexpr.cpp"
#include"otherfunc.cpp"

using namespace std;


int main(int argc,char *argv[]){
	if(argc != 2){
		cerr<<"Error! Format should be :"<<endl<<'\t'<<argv[0]<<" <file-name>.my"<<endl;
		exit(1);
	}
	else if(checkfiletype(argv[1])){
		cerr<<"Error! File type must be .my"<<endl;
		exit(1);
	}
        else {
                        cout<<"---------------------------- File Input Success ----------------------------------- " <<endl;
                State S;
                CompStatement *program = process(argv[1]);
                if(program!=NULL){
                        cout<<"---------------------------- Program Compiled Successfully ------------------------ " <<endl;
                        program->exec(S);
                        cout<<"---------------------------- Program Ran Successfully ----------------------------- " <<endl;
                }
                else {
                        cout<<"---------------------------- Errors in Program ------------------------------------ " <<endl;
                }
//                        S.print();
        }
        return 0;
}

//int main(){
//
//                State S;
//                S.setVar("n",5);
//        vector<string> temp;
//        temp.push_back("n");
//        temp.push_back(">");
//        temp.push_back("0");
//        CondExpr* t=parseCondExpr(temp);
//                cout<<" start --------"<<endl;
//                WhileStatement *t2 = new WhileStatement(t);
//                Statement *print = new PrintStringStatement("\"test\"" );
//                Statement *sub = new AssgStatement(new VarExpr("n"),new MinusExpr(new VarExpr("n"),new ConstExpr(1)));
//                t2->insideAppend(print);
//                t2->insideAppend(sub);
//                
//                t2->exec(S);
//                cout<<" enend --------"<<endl;
//
//
//return 0;
//
//}
