//===-- EntryPointArgumentEmission.h - Emit function entries. -------------===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2020 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#pragma once

namespace llvm {
class Value;
}

namespace swift {
namespace irgen {

class Explosion;

class EntryPointArgumentEmission {

public:
  virtual ~EntryPointArgumentEmission() {}
  virtual bool requiresIndirectResult(SILType retType) = 0;
  virtual llvm::Value *getIndirectResultForFormallyDirectResult() = 0;
  virtual llvm::Value *getIndirectResult(unsigned index) = 0;
};

class NativeCCEntryPointArgumentEmission
    : public virtual EntryPointArgumentEmission {

public:
  virtual llvm::Value *getCallerErrorResultArgument() = 0;
  virtual llvm::Value *getContext() = 0;
  virtual Explosion getArgumentExplosion(unsigned index, unsigned size) = 0;
  virtual llvm::Value *getSelfWitnessTable() = 0;
  virtual llvm::Value *getSelfMetadata() = 0;
  virtual llvm::Value *getCoroutineBuffer() = 0;
};

} // end namespace irgen
} // end namespace swift
