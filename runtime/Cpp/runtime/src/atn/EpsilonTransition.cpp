/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module;
#include <memory>
#include <string>
module Antlr4Runtime;
#else
#include "atn/EpsilonTransition.h"
#endif

using namespace antlr4::atn;

EpsilonTransition::EpsilonTransition(ATNState *target) : EpsilonTransition(target, INVALID_INDEX) {
}

EpsilonTransition::EpsilonTransition(ATNState *target, size_t outermostPrecedenceReturn)
  : Transition(target), _outermostPrecedenceReturn(outermostPrecedenceReturn) {
}

size_t EpsilonTransition::outermostPrecedenceReturn() {
  return _outermostPrecedenceReturn;
}

Transition::SerializationType EpsilonTransition::getSerializationType() const {
  return EPSILON;
}

bool EpsilonTransition::isEpsilon() const {
  return true;
}

bool EpsilonTransition::matches(size_t /*symbol*/, size_t /*minVocabSymbol*/, size_t /*maxVocabSymbol*/) const {
  return false;
}

std::string EpsilonTransition::toString() const {
  return "EPSILON " + Transition::toString() + " {}";
}
