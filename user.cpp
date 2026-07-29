#include "user.h"
#include <functional> // 用于 std::hash 进行密码哈希运算

// 1. 构造函数：初始化用户名，并将传入的明文密码转为哈希值保存
User::User(const std::string& name, const std::string& password)
    : username(name), password_hash(hashPassword(password)) {}

// 2. 静态哈希函数：将传入的字符串密码计算成哈希字符串
std::string User::hashPassword(const std::string& password) {
    std::size_t hashValue = std::hash<std::string>{}(password);
    return std::to_string(hashValue);
}

// 3. 验证密码：对输入的密码重新计算哈希，并与存好的密码哈希进行比对
bool User::verifyPassword(const std::string& input_password) const {
    return hashPassword(input_password) == password_hash;
}

// 4. 获取用户名
const std::string& User::getUsername() const {
    return username;
}
