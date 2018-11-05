/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module Antlr4.Runtime;
#else
#include "tree/ParseTree.h"
#include "tree/Trees.h"

#include "tree/xpath/XPathRuleAnywhereElement.h"
#endif

using namespace antlr4::tree;
using namespace antlr4::tree::xpath;

XPathRuleAnywhereElement::XPathRuleAnywhereElement(const std::string &ruleName, int ruleIndex) : XPathElement(ruleName) {
  _ruleIndex = ruleIndex;
}

std::vector<ParseTree *> XPathRuleAnywhereElement::evaluate(ParseTree *t) {
  return Trees::findAllRuleNodes(t, _ruleIndex);
}
