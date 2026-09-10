#ifndef EventNtuple_rooutil_TimeCluster_hh_
#define EventNtuple_rooutil_TimeCluster_hh_

#include <functional>
#include "EventNtuple/inc/TimeClusterInfo.hh"

namespace rooutil {
  struct TimeCluster {
    TimeCluster(mu2e::EventNtupleTimeClusterInfo* tc)
      : timecluster(tc) {
    }

    void Update(bool debug = false) {
    }

    //-------------------------------------------------
    // Accessors

    int        NHits()      const { return (timecluster) ? timecluster->nhits      : 0    ; }
    int        NStrawHits() const { return (timecluster) ? timecluster->nStrawHits  : 0    ; }
    float      T0()         const { return (timecluster) ? timecluster->t0          : 0.f  ; }
    XYZVectorF Pos()        const { return (timecluster) ? timecluster->pos         : XYZVectorF(); }
    float      ECalo()      const { return (timecluster) ? timecluster->ecalo       : -1.f ; }
    float      TCalo()      const { return (timecluster) ? timecluster->tcalo       : 0.f  ; }
    bool       HasCalo()    const { return ECalo() >= 0.f; }

    // Pointers to the data
    mu2e::EventNtupleTimeClusterInfo* timecluster = nullptr;
  };

  typedef std::function<bool(TimeCluster&)> TimeClusterCut;
  typedef std::vector<TimeCluster> TimeClusters;
} // namespace rooutil
#endif
