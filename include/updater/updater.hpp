#ifndef OSRM_UPDATER_UPDATER_HPP
#define OSRM_UPDATER_UPDATER_HPP

#include "updater/updater_config.hpp"

#include "extractor/edge_based_edge.hpp"

#include <chrono>
#include <vector>

namespace osrm
{
namespace updater
{
class Updater
{
  public:
    Updater(UpdaterConfig config_) : config(std::move(config_)) {}

    using NumNodesAndEdges =
        std::tuple<EdgeID, std::vector<extractor::EdgeBasedEdge>, std::uint32_t>;
    NumNodesAndEdges LoadAndUpdateEdgeExpandedGraph() const;

    EdgeID
    LoadAndUpdateEdgeExpandedGraph(std::vector<extractor::EdgeBasedEdge> &edge_based_edge_list,
                                   std::vector<EdgeWeight> &node_weights,
                                   std::uint32_t &connectivity_checksum) const;

  private:
    UpdaterConfig config;
};
}
}

#endif
