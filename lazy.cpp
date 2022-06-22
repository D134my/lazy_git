#include "lazy.hpp"
#include <array>
#include <random>

std::string lazy::exec(command_modes mode) noexcept {
  switch (mode) {
    using enum command_modes;

  case add: {
    auto add_result = exec_command("git add .");
    return add_result;
  } break;

  case status: {
    auto status_result = exec_command("git status");
    return status_result;
  } break;

  case commit: {
    commit_str += rand_commit();
    commit_str += " \"";

    auto commit_result = exec_command(commit_str);
    return commit_result;
  } break;

  case reset: {
    auto reset_result = exec_command("git reset --soft HEAD~1");
  } break;

  case log: {
    auto log_result = exec_command("git log");
    return log_result;
  } break;

  case show: {
    auto show_result = exec_command("git show");
    return show_result;
  } break;

  case pull: {
    auto pull_result = exec_command("git pull");
    return pull_result;
  } break;

  case push: {
    auto push_result = exec_command("git push");
    return push_result;
  } break;
  }
}

std::string lazy::rand_commit() noexcept {
  std::random_device rd;
  auto to = commits.size() - 1;
  std::uniform_int_distribution<int> dist(0, to);
  return commits.at(dist(rd));
}

std::string lazy::exec_command(std::string const &cmd) {
  std::array<char, 256> buffer;
  std::string popen_result{};
  auto pipe = popen(cmd.data(), "r");
  if (!pipe)
    throw std::runtime_error("popen failed !");
  try {
    while (fgets(buffer.data(), buffer.size(), pipe) != NULL)
      popen_result += buffer.data();
  } catch (...) {
    pclose(pipe);
    throw;
  }

  pclose(pipe);
  return popen_result;
}