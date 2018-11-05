/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module Antlr4.Runtime;
#else
#include "atn/DecisionState.h"
#endif

using namespace antlr4::atn;

void DecisionState::InitializeInstanceFields() {
  decision = -1;
  nonGreedy = false;
}

std::string DecisionState::toString() const {
  return "DECISION " + ATNState::toString();
}
