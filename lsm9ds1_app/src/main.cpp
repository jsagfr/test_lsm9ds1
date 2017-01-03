#include "Lsm9ds1.h"
#include "Config.h"
#include "Param.h"
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
  Config config{};
  config.fsXl = ParamFsXl{FsXl::Fs2g};
  // config.odrG = ParamOdrG{DataRate::DR119Hz};
  config.odrXl = ParamOdrXl{OdrXl::F50Hz};
  // config.outputDataRate = ParamOutputDataRate{OutputDataRate::Odr10Hz};
  // config.md = ParamMd{Md::Continuous};

  unsigned long i = 0;
  float freq = 0;
  float duration;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  
  Lsm9ds1 lsm9ds1{"/dev/i2c-2", config};
  // std::cout << "l=" << lsm9ds1.lx() << "," << lsm9ds1.ly() << "," << lsm9ds1.lz() << std::endl;
  // auto l = lsm9ds1.l();
  // std::cout << "l=" << l[0] << "," << l[1] << "," << l[2] << std::endl;

  start = std::chrono::system_clock::now();
  for(;;) {
    ++i;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "l=[" << lsm9ds1.lx() << "," << lsm9ds1.ly() << "," << lsm9ds1.lz() << "]m/s⁻² ";
  // auto l = lsm9ds1.l();
  // std::cout << "l=[" << l[0] << "," << l[1] << "," << l[2] << "]m/s⁻² ";
  if (i % 1000 == 0) {
    end = std::chrono::system_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>
      (end-start).count();
    freq = 1000 * 1000 / duration;
    start = std::chrono::system_clock::now();
  }
  std::cout << " fps=" << freq << ", " << duration;
    
    // std::cout << "g=[" << lsm9ds1.gx() << "," << lsm9ds1.gy() << "," << lsm9ds1.gz() << "]°/s⁻² ";
    // std::cout << "m=[" << lsm9ds1.mx() << "," << lsm9ds1.my() << "," << lsm9ds1.mz() << "]gauss";
    std::cout << "\r";
  }
}
