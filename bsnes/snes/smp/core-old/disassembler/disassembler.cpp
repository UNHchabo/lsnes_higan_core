#ifdef SMPCORE_CPP

uint8 SMPcore::disassemble_read(uint16 addr) {
  if(addr >= 0xffc0) return smp.iplrom[addr & 0x3f];
  return smp.apuram[addr];
}

uint16 SMPcore::relb(int8 offset, int op_len) {
  uint16 pc = regs.pc + op_len;
  return pc + offset;
}

void SMPcore::disassemble_opcode(char *output, uint16 addr) {
  char *s, t[512];
  uint8  op, op0, op1;
  uint16 opw, opdp0, opdp1;
  s = output;

  sprintf(s, "..%.4x ", addr);

  op  = disassemble_read(addr + 0);
  op0 = disassemble_read(addr + 1);
  op1 = disassemble_read(addr + 2);
  opw = (op0) | (op1 << 8);
  opdp0 = ((unsigned)regs.p.p << 8) + op0;
  opdp1 = ((unsigned)regs.p.p << 8) + op1;

  strcpy(t, "                       ");

  switch(op) {
    case 0x00: sprintf(t, "nop");                                        break;
    case 0x01: sprintf(t, "tcall 0");                                    break;
    case 0x02: sprintf(t, "set0  $%.3x", opdp0);                         break;
    case 0x03: sprintf(t, "bbs0  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x04: sprintf(t, "or    a,$%.3x", opdp0);                       break;
    case 0x05: sprintf(t, "or    a,$%.4x", opw);                         break;
    case 0x06: sprintf(t, "or    a,(x)");                                break;
    case 0x07: sprintf(t, "or    a,($%.3x+x)", opdp0);                   break;
    case 0x08: sprintf(t, "or    a,#$%.2x", op0);                        break;
    case 0x09: sprintf(t, "or    $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0x0a: sprintf(t, "or1   c,$%.4x:%d", opw & 0x1fff, opw >> 13);  break;
    case 0x0b: sprintf(t, "asl   $%.3x", opdp0);                         break;
    case 0x0c: sprintf(t, "asl   $%.4x", opw);                           break;
    case 0x0d: sprintf(t, "push  p");                                    break;
    case 0x0e: sprintf(t, "tset  $%.4x,a", opw);                         break;
    case 0x0f: sprintf(t, "brk");                                        break;
    case 0x10: sprintf(t, "bpl   $%.4x", relb(op0, 2));                  break;
    case 0x11: sprintf(t, "tcall 1");                                    break;
    case 0x12: sprintf(t, "clr0  $%.3x", opdp0);                         break;
    case 0x13: sprintf(t, "bbc0  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x14: sprintf(t, "or    a,$%.3x+x", opdp0);                     break;
    case 0x15: sprintf(t, "or    a,$%.4x+x", opw);                       break;
    case 0x16: sprintf(t, "or    a,$%.4x+y", opw);                       break;
    case 0x17: sprintf(t, "or    a,($%.3x)+y", opdp0);                   break;
    case 0x18: sprintf(t, "or    $%.3x,#$%.2x", opdp1, op0);             break;
    case 0x19: sprintf(t, "or    (x),(y)");                              break;
    case 0x1a: sprintf(t, "decw  $%.3x", opdp0);                         break;
    case 0x1b: sprintf(t, "asl   $%.3x+x", opdp0);                       break;
    case 0x1c: sprintf(t, "asl   a");                                    break;
    case 0x1d: sprintf(t, "dec   x");                                    break;
    case 0x1e: sprintf(t, "cmp   x,$%.4x", opw);                         break;
    case 0x1f: sprintf(t, "jmp   ($%.4x+x)", opw);                       break;
    case 0x20: sprintf(t, "clrp");                                       break;
    case 0x21: sprintf(t, "tcall 2");                                    break;
    case 0x22: sprintf(t, "set1  $%.3x", opdp0);                         break;
    case 0x23: sprintf(t, "bbs1  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x24: sprintf(t, "and   a,$%.3x", opdp0);                       break;
    case 0x25: sprintf(t, "and   a,$%.4x", opw);                         break;
    case 0x26: sprintf(t, "and   a,(x)");                                break;
    case 0x27: sprintf(t, "and   a,($%.3x+x)", opdp0);                   break;
    case 0x28: sprintf(t, "and   a,#$%.2x", op0);                        break;
    case 0x29: sprintf(t, "and   $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0x2a: sprintf(t, "or1   c,!$%.4x:%d", opw & 0x1fff, opw >> 13); break;
    case 0x2b: sprintf(t, "rol   $%.3x", opdp0);                         break;
    case 0x2c: sprintf(t, "rol   $%.4x", opw);                           break;
    case 0x2d: sprintf(t, "push  a");                                    break;
    case 0x2e: sprintf(t, "cbne  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x2f: sprintf(t, "bra   $%.4x", relb(op0, 2));                  break;
    case 0x30: sprintf(t, "bmi   $%.4x", relb(op0, 2));                  break;
    case 0x31: sprintf(t, "tcall 3");                                    break;
    case 0x32: sprintf(t, "clr1  $%.3x", opdp0);                         break;
    case 0x33: sprintf(t, "bbc1  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x34: sprintf(t, "and   a,$%.3x+x", opdp0);                     break;
    case 0x35: sprintf(t, "and   a,$%.4x+x", opw);                       break;
    case 0x36: sprintf(t, "and   a,$%.4x+y", opw);                       break;
    case 0x37: sprintf(t, "and   a,($%.3x)+y", opdp0);                   break;
    case 0x38: sprintf(t, "and   $%.3x,#$%.2x", opdp1, op0);             break;
    case 0x39: sprintf(t, "and   (x),(y)");                              break;
    case 0x3a: sprintf(t, "incw  $%.3x", opdp0);                         break;
    case 0x3b: sprintf(t, "rol   $%.3x+x", opdp0);                       break;
    case 0x3c: sprintf(t, "rol   a");                                    break;
    case 0x3d: sprintf(t, "inc   x");                                    break;
    case 0x3e: sprintf(t, "cmp   x,$%.3x", opdp0);                       break;
    case 0x3f: sprintf(t, "call  $%.4x", opw);                           break;
    case 0x40: sprintf(t, "setp");                                       break;
    case 0x41: sprintf(t, "tcall 4");                                    break;
    case 0x42: sprintf(t, "set2  $%.3x", opdp0);                         break;
    case 0x43: sprintf(t, "bbs2  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x44: sprintf(t, "eor   a,$%.3x", opdp0);                       break;
    case 0x45: sprintf(t, "eor   a,$%.4x", opw);                         break;
    case 0x46: sprintf(t, "eor   a,(x)");                                break;
    case 0x47: sprintf(t, "eor   a,($%.3x+x)", opdp0);                   break;
    case 0x48: sprintf(t, "eor   a,#$%.2x", op0);                        break;
    case 0x49: sprintf(t, "eor   $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0x4a: sprintf(t, "and1  c,$%.4x:%d", opw & 0x1fff, opw >> 13);  break;
    case 0x4b: sprintf(t, "lsr   $%.3x", opdp0);                         break;
    case 0x4c: sprintf(t, "lsr   $%.4x", opw);                           break;
    case 0x4d: sprintf(t, "push  x");                                    break;
    case 0x4e: sprintf(t, "tclr  $%.4x,a", opw);                         break;
    case 0x4f: sprintf(t, "pcall $ff%.2x", op0);                         break;
    case 0x50: sprintf(t, "bvc   $%.4x", relb(op0, 2));                  break;
    case 0x51: sprintf(t, "tcall 5");                                    break;
    case 0x52: sprintf(t, "clr2  $%.3x", opdp0);                         break;
    case 0x53: sprintf(t, "bbc2  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x54: sprintf(t, "eor   a,$%.3x+x", opdp0);                     break;
    case 0x55: sprintf(t, "eor   a,$%.4x+x", opw);                       break;
    case 0x56: sprintf(t, "eor   a,$%.4x+y", opw);                       break;
    case 0x57: sprintf(t, "eor   a,($%.3x)+y", opdp0);                   break;
    case 0x58: sprintf(t, "eor   $%.3x,#$%.2x", opdp1, op0);             break;
    case 0x59: sprintf(t, "eor   (x),(y)");                              break;
    case 0x5a: sprintf(t, "cmpw  ya,$%.3x", opdp0);                      break;
    case 0x5b: sprintf(t, "lsr   $%.3x+x", opdp0);                       break;
    case 0x5c: sprintf(t, "lsr   a");                                    break;
    case 0x5d: sprintf(t, "mov   x,a");                                  break;
    case 0x5e: sprintf(t, "cmp   y,$%.4x", opw);                         break;
    case 0x5f: sprintf(t, "jmp   $%.4x", opw);                           break;
    case 0x60: sprintf(t, "clrc");                                       break;
    case 0x61: sprintf(t, "tcall 6");                                    break;
    case 0x62: sprintf(t, "set3  $%.3x", opdp0);                         break;
    case 0x63: sprintf(t, "bbs3  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x64: sprintf(t, "cmp   a,$%.3x", opdp0);                       break;
    case 0x65: sprintf(t, "cmp   a,$%.4x", opw);                         break;
    case 0x66: sprintf(t, "cmp   a,(x)");                                break;
    case 0x67: sprintf(t, "cmp   a,($%.3x+x)", opdp0);                   break;
    case 0x68: sprintf(t, "cmp   a,#$%.2x", op0);                        break;
    case 0x69: sprintf(t, "cmp   $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0x6a: sprintf(t, "and1  c,!$%.4x:%d", opw & 0x1fff, opw >> 13); break;
    case 0x6b: sprintf(t, "ror   $%.3x", opdp0);                         break;
    case 0x6c: sprintf(t, "ror   $%.4x", opw);                           break;
    case 0x6d: sprintf(t, "push  y");                                    break;
    case 0x6e: sprintf(t, "dbnz  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x6f: sprintf(t, "ret");                                        break;
    case 0x70: sprintf(t, "bvs   $%.4x", relb(op0, 2));                  break;
    case 0x71: sprintf(t, "tcall 7");                                    break;
    case 0x72: sprintf(t, "clr3  $%.3x", opdp0);                         break;
    case 0x73: sprintf(t, "bbc3  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x74: sprintf(t, "cmp   a,$%.3x+x", opdp0);                     break;
    case 0x75: sprintf(t, "cmp   a,$%.4x+x", opw);                       break;
    case 0x76: sprintf(t, "cmp   a,$%.4x+y", opw);                       break;
    case 0x77: sprintf(t, "cmp   a,($%.3x)+y", opdp0);                   break;
    case 0x78: sprintf(t, "cmp   $%.3x,#$%.2x", opdp1, op0);             break;
    case 0x79: sprintf(t, "cmp   (x),(y)");                              break;
    case 0x7a: sprintf(t, "addw  ya,$%.3x", opdp0);                      break;
    case 0x7b: sprintf(t, "ror   $%.3x+x", opdp0);                       break;
    case 0x7c: sprintf(t, "ror   a");                                    break;
    case 0x7d: sprintf(t, "mov   a,x");                                  break;
    case 0x7e: sprintf(t, "cmp   y,$%.3x", opdp0);                       break;
    case 0x7f: sprintf(t, "reti");                                       break;
    case 0x80: sprintf(t, "setc");                                       break;
    case 0x81: sprintf(t, "tcall 8");                                    break;
    case 0x82: sprintf(t, "set4  $%.3x", opdp0);                         break;
    case 0x83: sprintf(t, "bbs4  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x84: sprintf(t, "adc   a,$%.3x", opdp0);                       break;
    case 0x85: sprintf(t, "adc   a,$%.4x", opw);                         break;
    case 0x86: sprintf(t, "adc   a,(x)");                                break;
    case 0x87: sprintf(t, "adc   a,($%.3x+x)", opdp0);                   break;
    case 0x88: sprintf(t, "adc   a,#$%.2x", op0);                        break;
    case 0x89: sprintf(t, "adc   $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0x8a: sprintf(t, "eor1  c,$%.4x:%d", opw & 0x1fff, opw >> 13);  break;
    case 0x8b: sprintf(t, "dec   $%.3x", opdp0);                         break;
    case 0x8c: sprintf(t, "dec   $%.4x", opw);                           break;
    case 0x8d: sprintf(t, "mov   y,#$%.2x", op0);                        break;
    case 0x8e: sprintf(t, "pop   p");                                    break;
    case 0x8f: sprintf(t, "mov   $%.3x,#$%.2x", opdp1, op0);             break;
    case 0x90: sprintf(t, "bcc   $%.4x", relb(op0, 2));                  break;
    case 0x91: sprintf(t, "tcall 9");                                    break;
    case 0x92: sprintf(t, "clr4  $%.3x", opdp0);                         break;
    case 0x93: sprintf(t, "bbc4  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0x94: sprintf(t, "adc   a,$%.3x+x", opdp0);                     break;
    case 0x95: sprintf(t, "adc   a,$%.4x+x", opw);                       break;
    case 0x96: sprintf(t, "adc   a,$%.4x+y", opw);                       break;
    case 0x97: sprintf(t, "adc   a,($%.3x)+y", opdp0);                   break;
    case 0x98: sprintf(t, "adc   $%.3x,#$%.2x", opdp1, op0);             break;
    case 0x99: sprintf(t, "adc   (x),(y)");                              break;
    case 0x9a: sprintf(t, "subw  ya,$%.3x", opdp0);                      break;
    case 0x9b: sprintf(t, "dec   $%.3x+x", opdp0);                       break;
    case 0x9c: sprintf(t, "dec   a");                                    break;
    case 0x9d: sprintf(t, "mov   x,sp");                                 break;
    case 0x9e: sprintf(t, "div   ya,x");                                 break;
    case 0x9f: sprintf(t, "xcn   a");                                    break;
    case 0xa0: sprintf(t, "ei");                                         break;
    case 0xa1: sprintf(t, "tcall 10");                                   break;
    case 0xa2: sprintf(t, "set5  $%.3x", opdp0);                         break;
    case 0xa3: sprintf(t, "bbs5  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0xa4: sprintf(t, "sbc   a,$%.3x", opdp0);                       break;
    case 0xa5: sprintf(t, "sbc   a,$%.4x", opw);                         break;
    case 0xa6: sprintf(t, "sbc   a,(x)");                                break;
    case 0xa7: sprintf(t, "sbc   a,($%.3x+x)", opdp0);                   break;
    case 0xa8: sprintf(t, "sbc   a,#$%.2x", op0);                        break;
    case 0xa9: sprintf(t, "sbc   $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0xaa: sprintf(t, "mov1  c,$%.4x:%d", opw & 0x1fff, opw >> 13);  break;
    case 0xab: sprintf(t, "inc   $%.3x", opdp0);                         break;
    case 0xac: sprintf(t, "inc   $%.4x", opw);                           break;
    case 0xad: sprintf(t, "cmp   y,#$%.2x", op0);                        break;
    case 0xae: sprintf(t, "pop   a");                                    break;
    case 0xaf: sprintf(t, "mov   (x)+,a");                               break;
    case 0xb0: sprintf(t, "bcs   $%.4x", relb(op0, 2));                  break;
    case 0xb1: sprintf(t, "tcall 11");                                   break;
    case 0xb2: sprintf(t, "clr5  $%.3x", opdp0);                         break;
    case 0xb3: sprintf(t, "bbc5  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0xb4: sprintf(t, "sbc   a,$%.3x+x", opdp0);                     break;
    case 0xb5: sprintf(t, "sbc   a,$%.4x+x", opw);                       break;
    case 0xb6: sprintf(t, "sbc   a,$%.4x+y", opw);                       break;
    case 0xb7: sprintf(t, "sbc   a,($%.3x)+y", opdp0);                   break;
    case 0xb8: sprintf(t, "sbc   $%.3x,#$%.2x", opdp1, op0);             break;
    case 0xb9: sprintf(t, "sbc   (x),(y)");                              break;
    case 0xba: sprintf(t, "movw  ya,$%.3x", opdp0);                      break;
    case 0xbb: sprintf(t, "inc   $%.3x+x", opdp0);                       break;
    case 0xbc: sprintf(t, "inc   a");                                    break;
    case 0xbd: sprintf(t, "mov   sp,x");                                 break;
    case 0xbe: sprintf(t, "das   a");                                    break;
    case 0xbf: sprintf(t, "mov   a,(x)+");                               break;
    case 0xc0: sprintf(t, "di");                                         break;
    case 0xc1: sprintf(t, "tcall 12");                                   break;
    case 0xc2: sprintf(t, "set6  $%.3x", opdp0);                         break;
    case 0xc3: sprintf(t, "bbs6  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0xc4: sprintf(t, "mov   $%.3x,a", opdp0);                       break;
    case 0xc5: sprintf(t, "mov   $%.4x,a", opw);                         break;
    case 0xc6: sprintf(t, "mov   (x),a");                                break;
    case 0xc7: sprintf(t, "mov   ($%.3x+x),a", opdp0);                   break;
    case 0xc8: sprintf(t, "cmp   x,#$%.2x", op0);                        break;
    case 0xc9: sprintf(t, "mov   $%.4x,x", opw);                         break;
    case 0xca: sprintf(t, "mov1  $%.4x:%d,c", opw & 0x1fff, opw >> 13);  break;
    case 0xcb: sprintf(t, "mov   $%.3x,y", opdp0);                       break;
    case 0xcc: sprintf(t, "mov   $%.4x,y", opw);                         break;
    case 0xcd: sprintf(t, "mov   x,#$%.2x", op0);                        break;
    case 0xce: sprintf(t, "pop   x");                                    break;
    case 0xcf: sprintf(t, "mul   ya");                                   break;
    case 0xd0: sprintf(t, "bne   $%.4x", relb(op0, 2));                  break;
    case 0xd1: sprintf(t, "tcall 13");                                   break;
    case 0xd2: sprintf(t, "clr6  $%.3x", opdp0);                         break;
    case 0xd3: sprintf(t, "bbc6  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0xd4: sprintf(t, "mov   $%.3x+x,a", opdp0);                     break;
    case 0xd5: sprintf(t, "mov   $%.4x+x,a", opw);                       break;
    case 0xd6: sprintf(t, "mov   $%.4x+y,a", opw);                       break;
    case 0xd7: sprintf(t, "mov   ($%.3x)+y,a", opdp0);                   break;
    case 0xd8: sprintf(t, "mov   $%.3x,x", opdp0);                       break;
    case 0xd9: sprintf(t, "mov   $%.3x+y,x", opdp0);                     break;
    case 0xda: sprintf(t, "movw  $%.3x,ya", opdp0);                      break;
    case 0xdb: sprintf(t, "mov   $%.3x+x,y", opdp0);                     break;
    case 0xdc: sprintf(t, "dec   y");                                    break;
    case 0xdd: sprintf(t, "mov   a,y");                                  break;
    case 0xde: sprintf(t, "cbne  $%.3x+x,$%.4x", opdp0, relb(op1, 3));   break;
    case 0xdf: sprintf(t, "daa   a");                                    break;
    case 0xe0: sprintf(t, "clrv");                                       break;
    case 0xe1: sprintf(t, "tcall 14");                                   break;
    case 0xe2: sprintf(t, "set7  $%.3x", opdp0);                         break;
    case 0xe3: sprintf(t, "bbs7  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0xe4: sprintf(t, "mov   a,$%.3x", opdp0);                       break;
    case 0xe5: sprintf(t, "mov   a,$%.4x", opw);                         break;
    case 0xe6: sprintf(t, "mov   a,(x)");                                break;
    case 0xe7: sprintf(t, "mov   a,($%.3x+x)", opdp0);                   break;
    case 0xe8: sprintf(t, "mov   a,#$%.2x", op0);                        break;
    case 0xe9: sprintf(t, "mov   x,$%.4x", opw);                         break;
    case 0xea: sprintf(t, "not1  c,$%.4x:%d", opw & 0x1fff, opw >> 13);  break;
    case 0xeb: sprintf(t, "mov   y,$%.3x", opdp0);                       break;
    case 0xec: sprintf(t, "mov   y,$%.4x", opw);                         break;
    case 0xed: sprintf(t, "notc");                                       break;
    case 0xee: sprintf(t, "pop   y");                                    break;
    case 0xef: sprintf(t, "sleep");                                      break;
    case 0xf0: sprintf(t, "beq   $%.4x", relb(op0, 2));                  break;
    case 0xf1: sprintf(t, "tcall 15");                                   break;
    case 0xf2: sprintf(t, "clr7  $%.3x", opdp0);                         break;
    case 0xf3: sprintf(t, "bbc7  $%.3x,$%.4x", opdp0, relb(op1, 3));     break;
    case 0xf4: sprintf(t, "mov   a,$%.3x+x", opdp0);                     break;
    case 0xf5: sprintf(t, "mov   a,$%.4x+x", opw);                       break;
    case 0xf6: sprintf(t, "mov   a,$%.4x+y", opw);                       break;
    case 0xf7: sprintf(t, "mov   a,($%.3x)+y", opdp0);                   break;
    case 0xf8: sprintf(t, "mov   x,$%.3x", opdp0);                       break;
    case 0xf9: sprintf(t, "mov   x,$%.3x+y", opdp0);                     break;
    case 0xfa: sprintf(t, "mov   $%.3x,$%.3x", opdp1, opdp0);            break;
    case 0xfb: sprintf(t, "mov   y,$%.3x+x", opdp0);                     break;
    case 0xfc: sprintf(t, "inc   y");                                    break;
    case 0xfd: sprintf(t, "mov   y,a");                                  break;
    case 0xfe: sprintf(t, "dbnz  y,$%.4x", relb(op0, 2));                break;
    case 0xff: sprintf(t, "stop");                                       break;
  }

  t[strlen(t)] = ' ';
  strcat(s, t);

  sprintf(t, "A:%.2x X:%.2x Y:%.2x SP:01%.2x YA:%.4x ",
    regs.a, regs.x, regs.y, regs.sp, (uint16)regs.ya);
  strcat(s, t);

  sprintf(t, "%c%c%c%c%c%c%c%c",
    regs.p.n ? 'N' : 'n',
    regs.p.v ? 'V' : 'v',
    regs.p.p ? 'P' : 'p',
    regs.p.b ? 'B' : 'b',
    regs.p.h ? 'H' : 'h',
    regs.p.i ? 'I' : 'i',
    regs.p.z ? 'Z' : 'z',
    regs.p.c ? 'C' : 'c');
  strcat(s, t);
}

#endif
