/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#ifdef SOUP_BUILD
module Antlr4.Runtime;
#else
#include "SemanticContext.h"

#include "atn/PredicateEvalInfo.h"
#endif

using namespace antlr4;
using namespace antlr4::atn;

PredicateEvalInfo::PredicateEvalInfo(size_t decision, TokenStream *input, size_t startIndex, size_t stopIndex,
  Ref<SemanticContext> const& semctx, bool evalResult, size_t predictedAlt, bool fullCtx)
  : DecisionEventInfo(decision, nullptr, input, startIndex, stopIndex, fullCtx),
    semctx(semctx), predictedAlt(predictedAlt), evalResult(evalResult) {
}
