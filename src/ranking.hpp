#ifndef _INCLUDE_RANKING_HPP
#define _INCLUDE_RANKING_HPP

#include "common.hpp"
#include "aco_parameters.hpp"
#include "ant.hpp"

class Ranking {
private:
  ACOParameters *params;
  vector<Ant *> ants;
  unsigned no_ranking_ants;

  void prepare_pheromones_for_one_ant(Ant *ant, unsigned ranking_position);
public:
  Ranking(ACOParameters *params, vector<Ant *> &ants);

  double calculate_additional_pheromones(Solution *solution, unsigned ranking_position);
  void prepare_pheromones();
  void update();

  static bool ants_comparator(Ant *a1, Ant *a2);
};

#endif
