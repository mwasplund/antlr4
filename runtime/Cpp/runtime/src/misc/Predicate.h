/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "antlr4-common.h"

namespace antlr4 {
namespace misc {

  ANTLR4CPP_EXPORT class ANTLR4CPP_PUBLIC Predicate {
  public:
    virtual ~Predicate();

    virtual bool test(tree::ParseTree *t) = 0;
  };

} // namespace tree
} // namespace antlr4
