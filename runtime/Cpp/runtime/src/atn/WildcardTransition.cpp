/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module Antlr4Runtime;
#else
#include "atn/ATNState.h"

#include "atn/WildcardTransition.h"
#endif

using namespace antlr4::atn;

WildcardTransition::WildcardTransition(ATNState *target) : Transition(target) {
}

Transition::SerializationType WildcardTransition::getSerializationType() const {
  return WILDCARD;
}

bool WildcardTransition::matches(size_t symbol, size_t minVocabSymbol, size_t maxVocabSymbol) const {
  return symbol >= minVocabSymbol && symbol <= maxVocabSymbol;
}

std::string WildcardTransition::toString() const {
  return "WILDCARD " + Transition::toString() + " {}";
}
