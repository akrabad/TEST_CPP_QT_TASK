#ifndef USER_H
#define USER_H

enum class USER_LEVEL
{
    OPERATOR,
    TECHNIC,
    ENGINEER
};

class User
{

public:
    explicit User(USER_LEVEL lvl = USER_LEVEL::OPERATOR);

    USER_LEVEL getUserLevel() {return user_level;}
private:
    USER_LEVEL user_level = USER_LEVEL::OPERATOR;


};

#endif // USER_H
