//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "TestPrjTestApp.h"
#include "TestPrjApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
TestPrjTestApp::validParams()
{
  InputParameters params = TestPrjApp::validParams();
  return params;
}

TestPrjTestApp::TestPrjTestApp(InputParameters parameters) : MooseApp(parameters)
{
  TestPrjTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

TestPrjTestApp::~TestPrjTestApp() {}

void
TestPrjTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  TestPrjApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"TestPrjTestApp"});
    Registry::registerActionsTo(af, {"TestPrjTestApp"});
  }
}

void
TestPrjTestApp::registerApps()
{
  registerApp(TestPrjApp);
  registerApp(TestPrjTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TestPrjTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TestPrjTestApp::registerAll(f, af, s);
}
extern "C" void
TestPrjTestApp__registerApps()
{
  TestPrjTestApp::registerApps();
}
