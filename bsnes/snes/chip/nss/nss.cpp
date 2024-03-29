#include <snes/snes.hpp>

#define NSS_CPP
namespace SNES {

NSS nss;

void NSS::init() {
}

void NSS::load() {
  dip = 0x0000;
  bus.map(Bus::MapMode::Direct, 0x00, 0x3f, 0x4100, 0x4101, 0, { &NSS::read, this }, { &NSS::write, this });
  bus.map(Bus::MapMode::Direct, 0x80, 0xbf, 0x4100, 0x4101, 0, { &NSS::read, this }, { &NSS::write, this });
}

void NSS::unload() {
}

void NSS::power() {
}

void NSS::reset() {
}

void NSS::set_dip(uint16 dip) {
  this->dip = dip;
}

uint8 NSS::read(unsigned addr) {
  if((addr & 0x40ffff) == 0x004100) return dip >> 0;
  if((addr & 0x40ffff) == 0x004101) return dip >> 8;
  return cpu.regs.mdr;
}

void NSS::write(unsigned addr, uint8 data) {
}

}
