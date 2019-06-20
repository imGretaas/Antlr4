#pragma once

#include "antlr4-runtime.h"
#include "tinyrexxParser.h"
#include "tinyrexxBaseListener.h"

/**
 * This class defines a concrete listener for a parse tree produced by tinyrexxParser.
 */
class  MyListener : public tinyrexxBaseListener {
private:
  int indent = 0;
  std::set<std::string> vars;

public:
  MyListener(const std::set<std::string> &ids);

  void enterProgram(tinyrexxParser::ProgramContext * ctx);
  void exitProgram(tinyrexxParser::ProgramContext * ctx);

  void enterAssign(tinyrexxParser::AssignContext * ctx);
  void exitAssign(tinyrexxParser::AssignContext * ctx);

  void enterPrint(tinyrexxParser::PrintContext * ctx);
  void exitPrint(tinyrexxParser::PrintContext * ctx);

  void exitInput(tinyrexxParser::InputContext * ctx);

  void enterW_loop(tinyrexxParser::W_loopContext * ctx);
  void exitW_loop(tinyrexxParser::W_loopContext * ctx);

  void enterTest(tinyrexxParser::TestContext * ctx);
  void exitTest(tinyrexxParser::TestContext * ctx);

  void enterA_expr(tinyrexxParser::A_exprContext * ctx);
  void exitA_expr(tinyrexxParser::A_exprContext * ctx);

  void exitA_op(tinyrexxParser::A_opContext * ctx);
  void exitR_op(tinyrexxParser::R_opContext * ctx);

  void enterTerminate(tinyrexxParser::TerminateContext * ctx);
  void exitTerminate(tinyrexxParser::TerminateContext * ctx);

  void enterI_t_e(tinyrexxParser::I_t_eContext * ctx);
  void exitI_t_e(tinyrexxParser::I_t_eContext * ctx);

  void enterI_e(tinyrexxParser::I_eContext * ctx);
  void exitI_e(tinyrexxParser::I_eContext * ctx);

  void enterB_op(tinyrexxParser::B_opContext * ctx);
  void exitB_op(tinyrexxParser::B_opContext * ctx);

  void enterF_loop(tinyrexxParser::F_loopContext * ctx);
  void exitF_loop(tinyrexxParser::F_loopContext * ctx);

  void enterF_test(tinyrexxParser::F_testContext * ctx);
  void exitF_test(tinyrexxParser::F_testContext * ctx);

  void enterF_expr(tinyrexxParser::F_exprContext * ctx);
  void exitF_expr(tinyrexxParser::F_exprContext * ctx);

  void enterI_assign(tinyrexxParser::I_assignContext * ctx);
  void exitI_assign(tinyrexxParser::I_assignContext * ctx);

  void enterGuardia(tinyrexxParser::GuardiaContext * ctx);
  void exitGuardia(tinyrexxParser::GuardiaContext * ctx);

  void enterW_test(tinyrexxParser::W_testContext * ctx);
  void exitW_test(tinyrexxParser::W_testContext * ctx);
};
