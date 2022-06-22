#include "lazy.hpp"

int main() {
  lazy l;

  auto result = l.exec(command_modes::status);
  std::cout << "status result : " << result << std::endl;

  std::cout << "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

  result = l.exec(command_modes::add);
  std::cout << "add result : " << result << " Ok " << std::endl;

  std::cout << "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

  result = l.exec(command_modes::status);
  std::cout << "status result : " << result << std::endl;

  std::cout << "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

  result = l.exec(command_modes::commit);
  std::cout << "commit result : " << result << std::endl;

  std::cout << "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

  result = l.exec(command_modes::pull);
  std::cout << "pull result : " << result << std::endl;
  std::cout << "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

  result = l.exec(command_modes::push);
  std::cout << "push result : " << result << " Ok " << std::endl;

  return 0;
}
