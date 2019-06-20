// Generated from tinyrexx.g4 by ANTLR 4.7
#include <iostream>
#include "MyListener.h"

using namespace std;

MyListener::MyListener(const std::set<std::string> &ids) {
  vars = ids;
}

void MyListener::enterProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
    // Dichiara le variabili
    for (auto name : vars) {
        cout << string(indent, ' ') << "int " << name << " = 0;" << endl;
    }

}

void MyListener::exitProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "}" << endl;
}

void MyListener::enterAssign(tinyrexxParser::AssignContext * ctx) {
    string name = ctx->ID()->getText();
    cout << string(indent, ' ') << name << " = " ;
}

void MyListener::exitAssign(tinyrexxParser::AssignContext * ctx) {
    cout << ";" << endl;
}

void MyListener::enterPrint(tinyrexxParser::PrintContext * ctx) {
    cout << string(indent, ' ') << "cout << " ;
}

void MyListener::exitPrint(tinyrexxParser::PrintContext * ctx) {
    cout << " << endl;" << endl;
}


void MyListener::exitInput(tinyrexxParser::InputContext * ctx) {
    string name = ctx->ID()->getText();
    cout << string(indent, ' ') << "cin >> " << name << ";" << endl;
}


void MyListener::enterA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() !=NULL) {
        // caso ID semplice
        cout << ctx->ID()->getText();
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
        cout << ctx->NUMBER()->getText();
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
        cout << "-" ;
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da enterA_op
    } else {
        // caso parentesi
        cout << "(" ;
    }
}

void MyListener::exitA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da exitA_op
    } else {
        // caso parentesi
        cout << ")" ;
    }
}

void MyListener::exitA_op(tinyrexxParser::A_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->PLUS() != NULL) {
        cout << " + ";
    } else if(ctx->MINUS() != NULL) {
        cout << " - ";
    } else if(ctx->MUL() != NULL) {
        cout << " * ";
    } else if(ctx->DIV() != NULL) {
        cout << " / ";
    }
}

void MyListener::exitR_op(tinyrexxParser::R_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->EQUAL() != NULL) {
        cout << " == ";
    } else if(ctx->LT() != NULL) {
        cout << " < ";
    } else if(ctx->LEQ() != NULL) {
        cout << " <= ";
    } else if(ctx->GT() != NULL) {
        cout << " > ";
    } else if(ctx->GEQ() != NULL) {
        cout << " >= ";
    }
}


void MyListener::enterW_loop(tinyrexxParser::W_loopContext * ctx){
    cout << string(indent, ' ') << "while ";
    indent += 4;

}


void MyListener::exitW_loop(tinyrexxParser::W_loopContext * ctx){
    indent -= 4;
    cout << string(indent, ' ') << "}" << endl;
}


void MyListener::enterTest(tinyrexxParser::TestContext * ctx){
    cout << "(";
}

void MyListener::exitTest(tinyrexxParser::TestContext * ctx){
    //cout << ") {" << endl;
    cout << ")";
}

  void MyListener::enterTerminate(tinyrexxParser::TerminateContext * ctx){
    cout << string(indent, ' ')<< "return ";
}

  void MyListener::exitTerminate(tinyrexxParser::TerminateContext * ctx){
    cout << ";" << endl;
}

  void MyListener::enterI_t_e(tinyrexxParser::I_t_eContext * ctx){
    cout << string(indent, ' ') << "if ";
    indent +=4;
}

  void MyListener::exitI_t_e(tinyrexxParser::I_t_eContext * ctx){
    indent-=4;
    cout << string(indent, ' ') << "}" << endl;
}

  void MyListener::enterB_op(tinyrexxParser::B_opContext * ctx){
	if(ctx->AND() !=NULL){
	   cout << " && ";
	}
	else if(ctx->OR() !=NULL){
	   cout << " || ";
	}
	else if(ctx->NOT() !=NULL){
	   cout << " !"; 
	}
}

  void MyListener::exitB_op(tinyrexxParser::B_opContext * ctx){
}

  void MyListener::enterF_loop(tinyrexxParser::F_loopContext * ctx){
    //indent-=2   
    cout << string(indent, ' ') << "for"; 
    //indent-=4; 
    cout << string(indent, ' ')<< '(';
    indent-=2;
}

  void MyListener::exitF_loop(tinyrexxParser::F_loopContext * ctx){
	indent-=2;
	cout << string(indent, ' ') << "}" << endl;
	//indent-=2;
}

  void MyListener::enterF_test(tinyrexxParser::F_testContext * ctx){
	string name=static_cast<tinyrexxParser::F_loopContext *>(ctx->parent)->i_assign()->ID()->getText();
	//cout << "<";
	//indent-=4;
	cout << string(indent, ' ');
	cout << " " << name << "<";
}

  void MyListener::exitF_test(tinyrexxParser::F_testContext * ctx){
	string name= static_cast<tinyrexxParser::F_loopContext *>(ctx->parent)->i_assign()->ID()->getText();
	//cout  << "++; }";
	//indent-=4;
	cout << ";" << " "<< name << "++)"<<"{" << endl;
}

  void MyListener::enterI_assign(tinyrexxParser::I_assignContext * ctx){
	string name=ctx->ID()->getText();
	cout << string(indent, ' ') << name << "=";  
}

  void MyListener::exitI_assign(tinyrexxParser::I_assignContext * ctx){
	cout << ";";
	indent+=4;
}

  void MyListener::enterI_e(tinyrexxParser::I_eContext * ctx){
	indent-=4;
	cout << string(indent, ' ') << "} else {\n";
	indent+=4;
}

  void MyListener::exitI_e(tinyrexxParser::I_eContext * ctx){
}

  void MyListener::enterGuardia(tinyrexxParser::GuardiaContext * ctx){
	cout << "(";
}

  void MyListener::exitGuardia(tinyrexxParser::GuardiaContext * ctx){
	cout << ") {\n";
}

  void MyListener::enterF_expr(tinyrexxParser::F_exprContext * ctx){
	cout << "(";
}

  void MyListener::exitF_expr(tinyrexxParser::F_exprContext * ctx){
	cout << ") {\n";
}

  void MyListener::enterW_test(tinyrexxParser::W_testContext * ctx){
}

  void MyListener::exitW_test(tinyrexxParser::W_testContext * ctx){
	cout << "{ \n";
}
