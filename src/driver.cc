#include "illini_book.hpp"
#include <iostream>

int main() {

  IlliniBook test("/home/vagrant/src/mp11-illini-book-seanguno/example/persons.csv", "/home/vagrant/src/mp11-illini-book-seanguno/example/relations.csv");
  // if (test.AreRelated(22, 23, "124")) {
  //   std::cout << "true" << std::endl;
  // }
  // if (test.AreRelated(22, 24, "128")) {
  //   std::cout << "true" << std::endl;
  // }
  // if (test.AreRelated(24, 23, "173")) {
  //   std::cout << "true" << std::endl;
  // }
  // if (!test.AreRelated(22, 23, "128")) {
  //   std::cout << "false" << std::endl;
  // }
  // if (!test.AreRelated(24, 23, "128")) {
  //   std::cout << "false" << std::endl;
  // }

  // std::vector<int> steps = test.GetSteps(1, 6);
  // for (size_t i = 0; i < steps.size(); ++i) {
  //   std::cout << steps.at(i) << std::endl;
  // }
  
  // if (!test.AreRelated(1, 1)) {
  //   std::cout << "false" << std::endl;
  // }
  // if (test.AreRelated(1, 2)) {
  //   std::cout << "true" << std::endl;
  // }

  // if (test.AreRelated(3, 2)) {
  //   std::cout << "true" << std::endl;
  // }

  // if (!test.AreRelated(1,9)) {
  //   std::cout << "false" << std::endl;
  // }

  // if (test.AreRelated(1, 2, "128")) {
  //   std::cout << "true" << std::endl;
  // }

  // if (!test.AreRelated(1, 2, "124")) {
  //   std::cout << "false" << std::endl;
  // }

  // if (test.AreRelated(1, 6, "128")) {
  //   std::cout << "true8" << std::endl;
  // }

  // if (test.AreRelated(1, 6, "124")) {
  //   std::cout << "true4" << std::endl;
  // }

  // std::cout << test.GetRelated(1, 2) << std::endl;
  // std::cout << test.GetRelated(3, 2) << std::endl;
  // std::cout << test.GetRelated(1, 9) << std::endl;
  // std::cout << test.GetRelated(1, 2, "128") << std::endl;
  // std::cout << test.GetRelated(1, 2, "124") << std::endl;
  // std::cout << test.GetRelated(1, 6, "128") << std::endl;
  // std::cout << test.GetRelated(1, 6, "124") << std::endl;
  // steps = test.GetSteps(1, 1);
  // for (size_t i = 0; i < steps.size(); ++i) {
  //   std::cout << steps.at(i) << std::endl;
  // }
  // steps = test.GetSteps(1, 2);
  // for (size_t i = 0; i < steps.size(); ++i) {
  //   std::cout << steps.at(i) << std::endl;
  // }
  // steps = test.GetSteps(1, 3);
  // for (size_t i = 0; i < steps.size(); ++i) {
  //   std::cout << steps.at(i) << std::endl;
  // }
  // steps = test.GetSteps(9, 1);
  // for (size_t i = 0; i < steps.size(); ++i) {
  //   std::cout << steps.at(i) << std::endl;
  // }
  // std::cout << test.CountGroups() << std::endl;
  // std::cout << test.CountGroups("128") << std::endl;
  // std::cout << test.CountGroups("124") << std::endl;
  // std::cout << test.CountGroups("173") << std::endl;
  // std::cout << test.CountGroups(std::vector<std::string>{"128", "173"}) << std::endl;
  std::cout << test.CountGroups(std::vector<std::string>{"128", "124", "173"}) << std::endl;
  return 0;
}

// 22,23,124
// 22,24,128
// 24,23,173
// 8,25,128
// 25,26,128
// 26,27,128
// 27,28,128

// 22
// 23
// 24
// 25
// 26
// 27
// 28
