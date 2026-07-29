#ifndef USER_H
#define USER_H

#include<string>
#include<iostream>

class User{
private:
  std::string username;
  std::string password_hash;
public:
User (const std::string& name,const std::string& password);
bool verifyPassword(const std::string &input_password) const;
static std::string hashPassword(const std::string& password);
const std::string& getUsername() const;
};
#endif
