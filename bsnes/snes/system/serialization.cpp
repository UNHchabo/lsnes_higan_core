#ifdef SYSTEM_CPP

serializer System::serialize() {
  serializer s(serialize_size);

  unsigned signature = 0x31545342, version = Info::SerializerVersion, crc32 = cartridge.crc32();
  char description[512], profile[16];
  memset(&description, 0, sizeof description);
  memset(&profile, 0, sizeof profile);
  strmcpy(profile, Info::Profile, sizeof profile);

  s.integer(signature);
  s.integer(version);
  s.integer(crc32);
  s.array(description);
  s.array(profile);

  serialize_all(s);
  return s;
}

bool System::unserialize(serializer &s) {
  unsigned signature, version, crc32;
  char description[512], profile[16];

  s.integer(signature);
  s.integer(version);
  s.integer(crc32);
  s.array(description);
  s.array(profile);

  if(signature != 0x31545342) return false;
  if(version != Info::SerializerVersion) return false;
//if(crc32 != cartridge.crc32()) return false;
  if(strcmp(profile, Info::Profile)) return false;

  power();
  serialize_all(s);
  return true;
}

//========
//internal
//========

void System::serialize(serializer &s) {
  s.integer((unsigned&)region);
  s.integer((unsigned&)expansion);
}

void System::serialize_all(serializer &s) {
  cartridge.serialize(s);
  system.serialize(s);
  random.serialize(s);
  cpu.serialize(s);
  smp.serialize(s);
  ppu.serialize(s);
  dsp.serialize(s);
  input.serialize(s);

  if(cartridge.mode() == Cartridge::Mode::SufamiTurbo) sufamiturbo.serialize(s);
  if(cartridge.mode() == Cartridge::Mode::SuperGameBoy) icd2.serialize(s);
  if(cartridge.has_superfx()) superfx.serialize(s);
  if(cartridge.has_sa1()) sa1.serialize(s);
  if(cartridge.has_necdsp()) necdsp.serialize(s);
  if(cartridge.has_hitachidsp()) hitachidsp.serialize(s);
  if(cartridge.has_srtc()) srtc.serialize(s);
  if(cartridge.has_sdd1()) sdd1.serialize(s);
  if(cartridge.has_spc7110()) spc7110.serialize(s);
  if(cartridge.has_obc1()) obc1.serialize(s);
  if(cartridge.has_msu1()) msu1.serialize(s);
}

//perform dry-run state save:
//determines exactly how many bytes are needed to save state for this cartridge,
//as amount varies per game (eg different RAM sizes, special chips, etc.)
void System::serialize_init() {
  serializer s;

  unsigned signature = 0, version = 0, crc32 = 0;
  char profile[16], description[512];

  s.integer(signature);
  s.integer(version);
  s.integer(crc32);
  s.array(profile);
  s.array(description);

  serialize_all(s);
  serialize_size = s.size();
}

#endif
