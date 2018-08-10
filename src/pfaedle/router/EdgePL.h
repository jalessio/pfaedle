// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Patrick Brosi <brosi@informatik.uni-freiburg.de>

#ifndef PFAEDLE_ROUTER_EDGEPL_H_
#define PFAEDLE_ROUTER_EDGEPL_H_

#include <map>
#include <string>
#include "pfaedle/router/Misc.h"
#include "util/geo/GeoGraph.h"
#include "util/geo/Geo.h"

using util::geograph::GeoEdgePL;
using util::geo::DPoint;
using util::geo::DLine;

namespace pfaedle {
namespace router {

class EdgePL : public GeoEdgePL<double> {
 public:
  EdgePL() : _cost(), _start(0), _end(0), _startE(0), _endE(0) {}
  const util::geo::DLine* getGeom() const;
  util::json::Dict getAttrs() const;
  router::EdgeList* getEdges();
  const router::EdgeList& getEdges() const;
  void setStartNode(const trgraph::Node* s);
  void setEndNode(const trgraph::Node* s);
  void setStartEdge(const trgraph::Edge* s);
  void setEndEdge(const trgraph::Edge* s);
  const router::EdgeCost& getCost() const;
  void setCost(const router::EdgeCost& c);
  const DPoint& frontHop() const;
  const DPoint& backHop() const;
  const trgraph::Node* frontNode() const;
  const trgraph::Node* backNode() const;

 private:
  router::EdgeCost _cost;
  // the edges are in this field in REVERSED ORDER!
  router::EdgeList _edges;
  const trgraph::Node* _start;
  const trgraph::Node* _end;
  const trgraph::Edge* _startE;
  const trgraph::Edge* _endE;
  mutable DLine _geom;
};
}  // namespace router
}  // namespace pfaedle

#endif  // PFAEDLE_ROUTER_EDGEPL_H_
