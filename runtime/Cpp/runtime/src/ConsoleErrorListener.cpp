﻿/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module;
#include <iostream>
#include <memory>
module Antlr4Runtime;
#else
#include "ConsoleErrorListener.h"
#endif

using namespace antlr4;

ConsoleErrorListener ConsoleErrorListener::INSTANCE;

void ConsoleErrorListener::syntaxError(Recognizer * /*recognizer*/, Token * /*offendingSymbol*/,
  size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr /*e*/)  {
  std::cerr << "line " << line << ":" << charPositionInLine << " " << msg << std::endl;
}
