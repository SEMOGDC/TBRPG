#include <random>
#include <iostream>
#include <chrono>
#include "rng.h"
using std::cout;
using std::endl;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(seed);

int rng(int lower, int upper){
  std::uniform_int_distribution<int> dist(lower, upper);
  return dist(gen);
}
