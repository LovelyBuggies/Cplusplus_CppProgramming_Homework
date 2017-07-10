# [Classes and Objects]The Werewolves of Miller's Hollow

## Task
实现一个简单的“狼人游戏”通知机制  
  
## Details
角色有：村民，狼人，预言家，女巫，猎人*（Uninitialized只用于默认构造函数）*  
法官呼叫“狼人/预言家/女巫/猎人”，相应角色进行回答  
法官呼叫“村民”，**全体角色回答**  
  
## Hints
`objA.on(objB)`表示将objB作为objA的监听者（事件订阅者）  
知识点：
- 观察者模式
- 类与类的关系：关联
- C++ enum
- 类静态变量   
  
## One more step
- 将构造函数和初始化操作（`Player();`和`void init(std::string name, Role role);`）分离出来有何优缺点？  
- `judge.hpp`中`const Player*`能改为`const Player&`吗？为什么？  
- enum类型Role定义在Player类的public部分有何好处？  
- Role为什么定义成enum类型？定义成string数组合适吗？  
- `kMaxCountOfPlayers`为什么要作为类静态变量？如果类静态变量为double类型，还能在类定义中初始化吗？  
  
## Links
- [《Google cpp style guide》--3.2. 初始化](http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/classes/)  
- [C++ initialize static variables in class?](http://stackoverflow.com/questions/5019856/c-initialize-static-variables-in-class)