# Alipay System 1 User (eden)


### Introduction

#### You must have heard alipay("Zhi Fu Bao" for Chinese). Now in this topic, we will do a series of practice to develop such a online payment system. This Time we are going to focus on the core of the system, the user part. If you have an account in alipay, you will have some basic knowledge about the architecture of the class, user.

 

### Requirements

#### I have already build a hpp file for the class architecture, and your job is to implement the specific functions.

#### In order to prevent name conflicts, I have already declared a namespace for alipay. You should notice that while you are going to coding.

### There will be some more details:
```
 // username should be a combination of letters and numbers and the length should be in [6,20]
 // correct: ["Alice1995", "Heart2you", "love2you", "5201314"]
 // incorrect: ["222@_@222", "12306", "abc12?"]
std::string username;

// password should be a combination of letters and numbers and the length should be in [8,20]
// correct: ["12345678", "abc00000000"]
// incorrect: ["123", "21?=_=?12"]
std::string password;

// phone should be a number and the length should be fixed 13
// correct: ["8618819473230"]
// incorrect: ["110", "330"]
std::string phone;

Gender::Gender gender;

// because soil-rich use this system, so no decimal.
long long int balance;

// auxiliary function for format checking
inline bool verifyPasswordFormat(const std::string & password);
inline bool verifyUsernameFormat(const std::string & username);
inline bool verifyPhoneFormat(const std::string & phone);
// Because of the mistake of the architect of alibaba,
// all the parameters of these function use c strings(char *).
// you are smart, the transformation is not a problem

// if the input is a valid username, set it and return true
bool setUsername(const char * username);

// You should confirm the old password and the new_password's format
bool setPassword(const char * new_password, const char * old_password);

bool setPhone(const char * new_phone);

// You can not set the Gender to unknown again
bool setGender(Gender::Gender gender);

std::string getUsername(void);
std::string getPhone(void);
alipay::Gender::Gender getGender(void);

long long int getMoneyAmount(const char * password);

bool deposit(long long int amount);

// password check is needed when withdraw
bool withdraw(long long int amount, const char * password);
```
### Deep Thinking and Discuss

#### What's the disadvantages of this design?
#### Why "using namespace std" is not a good way in c++ programming?
 

### More
#### Next we will have some practice which is more detailed with the teaching process.

### Hint
#### 建议大家好好复习上学期c语言有关函数原型的相关知识，么么哒。

*Source Author：叶嘉祺*