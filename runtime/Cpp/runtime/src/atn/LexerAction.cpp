/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module Antlr4Runtime;
#else
#include "LexerAction.h"
#endif

antlr4::atn::LexerAction::~LexerAction() {
}
