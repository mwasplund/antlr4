﻿/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "tree/TerminalNode.h"

namespace antlr4 {
namespace tree {

  ANTLR4CPP_EXPORT class ANTLR4CPP_PUBLIC ErrorNode : public virtual TerminalNode {
  public:
    ~ErrorNode() override;
  };

} // namespace tree
} // namespace antlr4
