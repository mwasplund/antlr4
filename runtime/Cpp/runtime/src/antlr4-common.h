/* Copyright (c) 2012-2018 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

// TODO: Warning unsafe method
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS

// Use the module std library in soup builds
#ifndef SOUP_BUILD
#include <algorithm>
#include <assert.h>
#include <atomic>
#include <codecvt>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <limits.h>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <mutex>
#include <exception>
#include <bitset>
#include <condition_variable>
#include <functional>
#endif

// Defines for the Guid class and other platform dependent stuff.
#ifdef SOUP_BUILD
  #define ANTLR4CPP_EXPORT export
#else
  #define ANTLR4CPP_EXPORT
#endif

#ifdef _WIN32
  #ifdef _MSC_VER
    #pragma warning (disable: 4250) // Class inherits by dominance.
    #pragma warning (disable: 4512) // assignment operator could not be generated

    #if _MSC_VER < 1900
      // Before VS 2015 code like "while (true)" will create a (useless) warning in level 4.
      #pragma warning (disable: 4127) // conditional expression is constant
    #endif
  #endif

  #define GUID_WINDOWS

  #ifdef _WIN64
    typedef __int64 ssize_t;
  #else
    typedef __int32 ssize_t;
  #endif

  #if _MSC_VER >= 1900 && _MSC_VER < 2000
    // VS 2015 has a known bug when using std::codecvt_utf8<char32_t>
    // so we have to temporarily use __int32 instead.
    // https://connect.microsoft.com/VisualStudio/feedback/details/1403302/unresolved-external-when-using-codecvt-utf8
    typedef std::basic_string<__int32> i32string;

    typedef i32string UTF32String;
  #else
    typedef std::u32string UTF32String;
  #endif

  #ifdef ANTLR4CPP_EXPORTS
    #define ANTLR4CPP_PUBLIC __declspec(dllexport)
  #else
    #if defined(ANTLR4CPP_STATIC) || defined(SOUP_BUILD)
      #define ANTLR4CPP_PUBLIC
    #else
      #define ANTLR4CPP_PUBLIC __declspec(dllimport)
    #endif
  #endif

  #ifndef SOUP_BUILD
  namespace std 
  {
    ANTLR4CPP_EXPORT class ANTLR4CPP_PUBLIC exception; // Needed for VS 2015.
  }
  #endif

#elif defined(__APPLE__)
  typedef std::u32string UTF32String;

  #define GUID_CFUUID
  #if __GNUC__ >= 4
    #define ANTLR4CPP_PUBLIC __attribute__ ((visibility ("default")))
  #else
    #define ANTLR4CPP_PUBLIC
  #endif
#else
  typedef std::u32string UTF32String;

  #define GUID_LIBUUID
  #if __GNUC__ >= 6
    #define ANTLR4CPP_PUBLIC __attribute__ ((visibility ("default")))
  #else
    #define ANTLR4CPP_PUBLIC
  #endif
#endif

#include "support/guid.h"
#include "support/Declarations.h"

#if !defined(HAS_NOEXCEPT)
  #if defined(__clang__)
    #if __has_feature(cxx_noexcept)
      #define HAS_NOEXCEPT
    #endif
  #else
    #if defined(__GXX_EXPERIMENTAL_CXX0X__) && __GNUC__ * 10 + __GNUC_MINOR__ >= 46 || \
      defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023026
      #define HAS_NOEXCEPT
    #endif
  #endif

  #ifdef HAS_NOEXCEPT
    #define NOEXCEPT noexcept
  #else
    #define NOEXCEPT
  #endif
#endif

// We have to undefine this symbol as ANTLR will use this name for own members and even
// generated functions. Because EOF is a global macro we cannot use e.g. a namespace scope to disambiguate.
#ifdef EOF
#undef EOF
#endif

#if SOUP_BUILD
// Allow modules to have a single definition for this global
const size_t INVALID_INDEX = std::numeric_limits<size_t>::max();
#else
#define INVALID_INDEX std::numeric_limits<size_t>::max()
#endif
template<class T> using Ref = std::shared_ptr<T>;
