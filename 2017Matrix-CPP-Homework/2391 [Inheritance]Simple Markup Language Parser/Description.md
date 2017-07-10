# [Inheritance]Simple Markup Language Parser

## Description
你一定见过HTML、XML等标记语言，如果没有，请按下`CTRL+U`。   
现在你已经知道了什么是标记语言，请应用所学的知识，做一个简单的标记语言解析器。    
这是一个很笨的解析器，不支持标签属性，容错能力弱，只接受形如`<TAGNAME>DATA</TAGNAME>`的输入，支持嵌套标签。   
基本思路：
- Parser有两种状态：DATA和TAGNAME
- Parser扫描输入，由"<"和“>”触发状态切换
- 扫描到的内容会存进每个State的cache里
- 切换状态时向Bulider发射一个Token（可以理解为一个词）
- Bulider处理接受到的Token，建立起一棵文档树后打印（参照“括号匹配算法”）
- 如果出现错误（闭合标签与开放标签不匹配等），打印`INVALID INPUT`
## Hints
### 设计模式：
- 状态模式：用“标记化算法”进行解析
- 单例模式：Parser、Builder、各种State均分别只能有一个实例
- 观察者模式：发射Token到Builder可以视为“通知观察者Builder”     
### 细节说明：
- 对DATA做trim处理——去除头尾的空格，对TAGNAME则不做trim处理
- （trim后的）cache为空，则不发射Token     
- 请把题目下载到本地查看标准测例
## One more step
- 试着让你的解析器解析HTML，并让它变得更聪明
- 为什么需要使用单例模式？
- 这是使用了面向对象的编程范式解决问题，如果改为面向过程，代码如何组织，是否容易造成混乱？
- 若仍采用面向对象编程范式，有更好的设计方式吗？
## Links
- [状态模式](http://design-patterns.readthedocs.io/zh_CN/latest/behavioral_patterns/state.html)
- [标记化算法](https://www.html5rocks.com/zh/tutorials/internals/howbrowserswork/#The_tokenization_algorithm)