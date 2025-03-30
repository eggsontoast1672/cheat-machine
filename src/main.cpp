#include "cmac/window.hpp"

int main() {
  CMac::Window window{800, 800};

  while (!window.should_close()) {
    window.clear();
    window.display();
  }
}
