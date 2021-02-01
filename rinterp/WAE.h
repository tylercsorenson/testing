//
// Created by Tyler Sorenson on 2/1/21.
//

#ifndef RUDIMENTARY_INTERPRETER_WAE_H
#define RUDIMENTARY_INTERPRETER_WAE_H

class WAE {
public:
  virtual ~WAE() = default;;
  virtual bool operator==(const WAE &other) const = 0;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_H
