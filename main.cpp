#include "lazy.hpp"

int main() {

  lazy l;

  auto const commands = std::vector<command_modes>{
      command_modes::status, command_modes::add,  command_modes::commit,
      command_modes::status, command_modes::pull, command_modes::push};

  for (auto cmd : commands) {
    auto result = l.exec(cmd);
    std::cout << result << std::endl;
    std::cout << "\n\n ****************************** \n\n";
  }

  return 0;
}
