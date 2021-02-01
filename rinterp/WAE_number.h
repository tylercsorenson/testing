//
// Created by Tyler Sorenson on 2/1/21.
//

#ifndef RUDIMENTARY_INTERPRETER_WAE_NUMBER_H
#define RUDIMENTARY_INTERPRETER_WAE_NUMBER_H

#include "WAE.h"

class WAE_number : public WAE {
private:
  double number;

public:
  explicit WAE_number(double number);
  bool operator==(const WAE &other) const override;
  [[nodiscard]] double get_number() const;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_NUMBER_H
