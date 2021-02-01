//
// Created by Tyler Sorenson on 2/1/21.
//

#ifndef RUDIMENTARY_INTERPRETER_WAE_X_H
#define RUDIMENTARY_INTERPRETER_WAE_X_H

#include "WAE.h"
#include <string>

using namespace std;

class WAE_x : public WAE {
private:
  std::string x;

public:
  explicit WAE_x(string x);
  bool operator==(const WAE &other) const override;
  [[nodiscard]] string get_x() const;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_X_H
