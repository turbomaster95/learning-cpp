#pragma once

#include <string>
#include <vector>

#ifdef FURL_GLUE
    #include <fvmglue.h>
#else
    #include "fglue.hpp"
#endif

#define MAX_STRING_TABLE_SIZE 512

namespace Furl {
  typedef struct __attribute__((packed)) Inst {
      u8       opcode;
      u8       dest;
      u8       src;
      u8       reserved;
      sword imm;
  } Inst;

  typedef struct Memory {
      Inst rom[ROM_SIZE];
      u8   ram[RAM_SIZE];
  } Memory;


  typedef struct StringTable {
      std::vector<std::string> strings[MAX_STRING_TABLE_SIZE];
      word count;
  } StringTable;
  
  struct Furs {
    word regs[REGS] = {0};
    word pc = 0;
    Memory memory{};
    StringTable strtbl{};
    bool halted = false;
  };

  
}
