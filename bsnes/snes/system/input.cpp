#ifdef SYSTEM_CPP

Input input;

void Input::connect(bool port, Input::Device id) {
  Controller *&controller = (port == Controller::Port1 ? port1 : port2);
  if(controller) {
    delete controller;
    controller = nullptr;
  }

  switch(id) { default:
  case Device::None: controller = new Controller(port); break;
  case Device::Joypad: controller = new Gamepad(port); break;
  case Device::Multitap: controller = new Multitap(port); break;
  case Device::Mouse: controller = new Mouse(port); break;
  case Device::SuperScope: controller = new SuperScope(port); break;
  case Device::Justifier: controller = new Justifier(port, false); break;
  case Device::Justifiers: controller = new Justifier(port, true); break;
  case Device::Serial: controller = new Serial(port); break;
  }

  switch(port) {
  case Controller::Port1: config.controller_port1 = id; break;
  case Controller::Port2: config.controller_port2 = id; break;
  }
}

void Input::serialize(serializer &s)
{
  int p1, p2;
  p1 = (int)config.controller_port1;
  p2 = (int)config.controller_port2;
  s.integer(p1);
  s.integer(p2);
  if(s.mode() == nall::serializer::Load) {
    connect(Controller::Port1, (Device)p1);
    connect(Controller::Port2, (Device)p2);
  }
  port1->serialize(s);
  port2->serialize(s);
}


Input::Input() : port1(nullptr), port2(nullptr) {
  connect(Controller::Port1, Input::Device::Joypad);
  connect(Controller::Port2, Input::Device::Joypad);
}

Input::~Input() {
  if(port1) delete port1;
  if(port2) delete port2;
}

#endif
