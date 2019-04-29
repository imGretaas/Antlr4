
// Generated from tinyrexx.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "tinyrexxListener.h"


/**
 * This class provides an empty implementation of tinyrexxListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  tinyrexxBaseListener : public tinyrexxListener {
public:

  virtual void enterProgram(tinyrexxParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(tinyrexxParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(tinyrexxParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(tinyrexxParser::StatementContext * /*ctx*/) override { }

  virtual void enterAssign(tinyrexxParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(tinyrexxParser::AssignContext * /*ctx*/) override { }

  virtual void enterPrint(tinyrexxParser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(tinyrexxParser::PrintContext * /*ctx*/) override { }

  virtual void enterInput(tinyrexxParser::InputContext * /*ctx*/) override { }
  virtual void exitInput(tinyrexxParser::InputContext * /*ctx*/) override { }

  virtual void enterW_loop(tinyrexxParser::W_loopContext * /*ctx*/) override { }
  virtual void exitW_loop(tinyrexxParser::W_loopContext * /*ctx*/) override { }

  virtual void enterF_loop(tinyrexxParser::F_loopContext * /*ctx*/) override { }
  virtual void exitF_loop(tinyrexxParser::F_loopContext * /*ctx*/) override { }

  virtual void enterI_t_e(tinyrexxParser::I_t_eContext * /*ctx*/) override { }
  virtual void exitI_t_e(tinyrexxParser::I_t_eContext * /*ctx*/) override { }

  virtual void enterTest(tinyrexxParser::TestContext * /*ctx*/) override { }
  virtual void exitTest(tinyrexxParser::TestContext * /*ctx*/) override { }

  virtual void enterA_expr(tinyrexxParser::A_exprContext * /*ctx*/) override { }
  virtual void exitA_expr(tinyrexxParser::A_exprContext * /*ctx*/) override { }

  virtual void enterA_op(tinyrexxParser::A_opContext * /*ctx*/) override { }
  virtual void exitA_op(tinyrexxParser::A_opContext * /*ctx*/) override { }

  virtual void enterR_op(tinyrexxParser::R_opContext * /*ctx*/) override { }
  virtual void exitR_op(tinyrexxParser::R_opContext * /*ctx*/) override { }

  virtual void enterB_op(tinyrexxParser::B_opContext * /*ctx*/) override { }
  virtual void exitB_op(tinyrexxParser::B_opContext * /*ctx*/) override { }

  virtual void enterGuardia(tinyrexxParser::GuardiaContext * /*ctx*/) override { }
  virtual void exitGuardia(tinyrexxParser::GuardiaContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

