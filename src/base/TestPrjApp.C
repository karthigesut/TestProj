#include "TestPrjApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
TestPrjApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

TestPrjApp::TestPrjApp(InputParameters parameters) : MooseApp(parameters)
{
  TestPrjApp::registerAll(_factory, _action_factory, _syntax);
}

TestPrjApp::~TestPrjApp() {}

void
TestPrjApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"TestPrjApp"});
  Registry::registerActionsTo(af, {"TestPrjApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TestPrjApp::registerApps()
{
  registerApp(TestPrjApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TestPrjApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TestPrjApp::registerAll(f, af, s);
}
extern "C" void
TestPrjApp__registerApps()
{
  TestPrjApp::registerApps();
}
