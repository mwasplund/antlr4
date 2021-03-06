/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module;
#include <memory>
module Antlr4Runtime;
#else
#include "tree/ParseTree.h"
#include "tree/Trees.h"

#include "XPathTokenAnywhereElement.h"
#endif

using namespace antlr4::tree;
using namespace antlr4::tree::xpath;

XPathTokenAnywhereElement::XPathTokenAnywhereElement(const std::string &tokenName, int tokenType) : XPathElement(tokenName) {
  this->tokenType = tokenType;
}

std::vector<ParseTree *> XPathTokenAnywhereElement::evaluate(ParseTree *t) {
  return Trees::findAllTokenNodes(t, tokenType);
}
