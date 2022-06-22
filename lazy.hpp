#ifndef lazy_Header
#define lazy_Header

#include "types.hpp"
#include <iostream>
#include <string_view>
#include <vector>

class lazy {
public:
  std::string exec(command_modes mode) noexcept;

private:
  std::string commit_str{"git commit -m \" "};
  std::string rand_commit() noexcept;
  std::string exec_command(std::string const &cmd);
  std::vector<std::string> const commits{
      "updated", "new commit", "more more commit", "commits everywhere"};
};

#endif