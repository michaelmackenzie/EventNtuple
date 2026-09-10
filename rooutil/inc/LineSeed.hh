#ifndef LineSeed_hh_
#define LineSeed_hh_

#include <functional>
#include "EventNtuple/inc/LineSeedInfo.hh"

namespace rooutil {
  struct LineSeed {
    LineSeed(mu2e::LineSeedInfo* ls)
      : lineseed(ls) {
    }

    void Update(bool debug = false) {
    }

    // Pointers to the data
    mu2e::LineSeedInfo* lineseed = nullptr;
  };

  typedef std::function<bool(LineSeed&)> LineSeedCut;
  typedef std::vector<LineSeed> LineSeeds;
} // namespace rooutil
#endif
