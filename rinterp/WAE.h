#ifndef RUDIMENTARY_INTERPRETER_WAE_H
#define RUDIMENTARY_INTERPRETER_WAE_H

class WAE {
public:
    virtual ~WAE() = default;;

    virtual bool operator==(const WAE &other) const = 0;

    virtual unsigned solve() = 0;

    virtual WAE *subst(WAE *id, WAE *what) = 0;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_H
