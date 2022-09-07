#include "System.hpp"

namespace Engine {
  class System;
}

typedef struct test_component
{
  int z;
}test_component_t;

struct warhouse
{
  int i;
  float time;
  int index;
};

class testing : public Engine::System
{
public:
  testing(std::string name);
  ~testing();

  //  void update(float dt);
private:

};
