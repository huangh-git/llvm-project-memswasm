//===-- llvm/BinaryFormat/Wasm.cpp -------------------------------*- C++-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/BinaryFormat/Wasm.h"

std::string llvm::wasm::toString(wasm::WasmSymbolType Type) {
  switch (Type) {
  case wasm::WASM_SYMBOL_TYPE_FUNCTION:
    return "WASM_SYMBOL_TYPE_FUNCTION";
  case wasm::WASM_SYMBOL_TYPE_GLOBAL:
    return "WASM_SYMBOL_TYPE_GLOBAL";
  case wasm::WASM_SYMBOL_TYPE_TABLE:
    return "WASM_SYMBOL_TYPE_TABLE";
  case wasm::WASM_SYMBOL_TYPE_DATA:
    return "WASM_SYMBOL_TYPE_DATA";
  case wasm::WASM_SYMBOL_TYPE_SECTION:
    return "WASM_SYMBOL_TYPE_SECTION";
  case wasm::WASM_SYMBOL_TYPE_TAG:
    return "WASM_SYMBOL_TYPE_TAG";
  }
  llvm_unreachable("unknown symbol type");
}

std::string llvm::wasm::relocTypetoString(uint32_t Type) {
  switch (Type) {
#define WASM_RELOC(NAME, VALUE)                                                \
  case VALUE:                                                                  \
    return #NAME;
#include "llvm/BinaryFormat/WasmRelocs.def"
#undef WASM_RELOC
  default:
    llvm_unreachable("unknown reloc type");
  }
}

bool llvm::wasm::relocTypeHasAddend(uint32_t Type) {
  switch (Type) {
  case R_WASM_MEMORY_ADDR_LEB:
  case R_WASM_MEMORY_ADDR_LEB64:
  case R_WASM_MEMORY_ADDR_SLEB:
  case R_WASM_MEMORY_ADDR_SLEB64:
  case R_WASM_MEMORY_ADDR_REL_SLEB:
  case R_WASM_MEMORY_ADDR_REL_SLEB64:
  case R_WASM_MEMORY_ADDR_I32:
  case R_WASM_MEMORY_ADDR_I64:
  case R_WASM_MEMORY_ADDR_TLS_SLEB:
  case R_WASM_MEMORY_ADDR_TLS_SLEB64:
  case R_WASM_FUNCTION_OFFSET_I32:
  case R_WASM_FUNCTION_OFFSET_I64:
  case R_WASM_SECTION_OFFSET_I32:
  case R_WASM_MEMORY_ADDR_LOCREL_I32:
    return true;
  default:
    return false;
  }
}

//std::string llvm::wasm::toString(wasm::ValType Type) {
//  switch (Type) {
//  case wasm::ValType::I32:
//    return "I32";
//  case wasm::ValType::I64:
//    return "I64";
//  case wasm::ValType::MEMREF:
//    return "MEMREF";
//  case wasm::ValType::EXTERNREF:
//    return "EXTERNREF";
//  case wasm::ValType::FUNCREF:
//    return "FUNCREF";
//  case wasm::ValType::F32:
//    return "F32";
//  case wasm::ValType::F64:
//    return "F64";
//  case wasm::ValType::V128:
//    return "V128";
//  default:
//    llvm_unreachable("unknown wasm value type");
//  }
//}