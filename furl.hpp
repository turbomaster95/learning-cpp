#pragma once

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#ifdef FURL_GLUE
    #include <fvmglue.h>
#else
    #include "fglue.hpp"
#endif

namespace Furl {
  typedef struct Inst {
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
      std::vector<std::string> strings;
      word count;
  } StringTable;
  
  struct Furs {
    word regs[REGS] = {0};
    word pc = 0;
    word sp = 0;
    bool halted = false;
  };

  enum class Opcode : u8 {
      NOP = 0x00,
      MOV,
      ADD,
      HALT = 0xFF
  };
  
  class VM {
    private:
      Memory memory_;
      StringTable strtbl_;
      Furs ctx_;
      
    public: 
      explicit VM(Memory mem) : memory_(mem) {
        reset();
      }
      
      void reset() {
        ctx_ = Furs{}; 
      }

      void run(const Inst *program, size_t progsize) {
        if (!program || !progsize) return;

        std::memcpy(memory_.rom, program, progsize);

        while (!ctx_.halted && ctx_.pc < ROM_SIZE) {
          Inst inst = memory_.rom[ctx_.pc++];

          switch (static_cast<Opcode>(inst.opcode)) {
              case Opcode::NOP:
                break;

              case Opcode::MOV:
                if (inst.dest < REGS) ctx_.regs[inst.dest] = inst.imm;
                break;

              case Opcode::ADD:
                if (inst.dest < REGS) ctx_.regs[]
              default:
                std::cout << "Error! Invalid Opcode" << std::endl;
                exit(-1);
          }
        }
      }
  };
  
}
