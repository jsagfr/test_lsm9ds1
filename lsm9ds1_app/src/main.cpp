#include "Lsm9ds1.h"
#include <iostream>
#include <iomanip>

int main() {
  Lsm9ds1Config lsm9ds1Config{};
  lsm9ds1Config.fsXl = ParamFsXl{FsXl::Fs8g};
  // lsm9ds1Config.odrG = ParamOdrG{DataRate::DR119Hz};
  lsm9ds1Config.odrXl = ParamOdrXl{OdrXl::F119Hz};
  // lsm9ds1Config.outputDataRate = ParamOutputDataRate{OutputDataRate::Odr10Hz};
  // lsm9ds1Config.md = ParamMd{Md::Continuous};

  Lsm9ds1 lsm9ds1{"/dev/i2c-2", lsm9ds1Config};
  // std::cout << "lx=" << lsm9ds1.lx() << std::endl;
  for(;;) {
    std::cout << "l=[" << std::fixed << std::setprecision(2) << lsm9ds1.lx() << "," << lsm9ds1.ly() << "," << lsm9ds1.lz() << "]m/s⁻² ";
    std::cout << "g=[" << lsm9ds1.gx() << "," << lsm9ds1.gy() << "," << lsm9ds1.gz() << "]°/s⁻² ";
    std::cout << "m=[" << lsm9ds1.mx() << "," << lsm9ds1.my() << "," << lsm9ds1.mz() << "]gauss\r";
 }
}
