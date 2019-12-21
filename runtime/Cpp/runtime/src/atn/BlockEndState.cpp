/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module;
#include <memory>
module Antlr4Runtime;
#else
#include "atn/BlockEndState.h"
#endif

using namespace antlr4::atn;

BlockEndState::BlockEndState() : startState(nullptr) {
}

size_t BlockEndState::getStateType() {
  return BLOCK_END;
}
