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
#include "Exceptions.h"

#include "tree/pattern/TextChunk.h"
#endif

using namespace antlr4::tree::pattern;

TextChunk::TextChunk(const std::string &text) : text(text) {
  if (text == "") {
    throw IllegalArgumentException("text cannot be nul");
  }

}

TextChunk::~TextChunk() {
}

std::string TextChunk::getText() {
  return text;
}

std::string TextChunk::toString() {
  return std::string("'") + text + std::string("'");
}
