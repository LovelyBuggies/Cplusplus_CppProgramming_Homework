# [Classes and Objects]Product and Factory

## Introdution
在软件设计中，一个对象的创建可能没有它看上去那么容易。比如课程管理系统中，一个课程的创建依赖于许多业务逻辑。    
某些情况下，将对象的创建和使用分离开来，是一个不错的选择，这让我们可以更优雅地组织代码，降低各模块的耦合性。    
我们将使用Product和Factory的概念：    
- 当客户端需要某个Product时，并不直接拿到它，而是通过一个Factory拿到
- 只有Factory关心如何创建这个Product，而客户端无需关心
- 客户端拿到Product，即可使用它支持的各种方法  

## Task
依次阅读Links中给出的三个链接，理解这三种模式和它们之间的关系，理解“产品等级结构”、“产品族”。    
根据给出的信息，应用“抽象工厂模式”，完成该程序。    
## Hints
- 关键知识点：抽象类（接口继承）、多态
- Laptop可以compileCppProgram，MobilePhone可以sendShortMessage
- 想要AppleLaptop或AppleMobilePhone，去找AppleFactory
- 想要XiaomiLaptop或XiaomiMobilePhone，去找XiaomiFactory

```
Input0:
0

Output0:
Apple Laptop compiles a cpp program.
Apple MobilePhone sends a short message.

/*======*/
Input1:
1

Output1:
Xiaomi Laptop compiles a cpp program.
Xiaomi MobilePhone sends a short message.

```
## One more step
面向对象设计的“SOLID原则”：    
- S	单一功能原则：对象应该仅具有一种单一功能。
- O	开闭原则：软件体应该是对于扩展开放的，但是对于修改封闭的。
- L	里氏替换原则：程序中的对象应该是可以在不改变程序正确性的前提下被它的子类所替换的。
- I	接口隔离原则：多个特定客户端接口要好于一个宽泛用途的接口。 
- D	依赖反转原则：一个方法应该遵从“依赖于抽象而不是一个实例”。   

## Links
- [简单工厂模式](http://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/simple_factory.html)
- [工厂方法模式](http://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/factory_method.html)
- [抽象工厂模式](http://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/abstract_factory.html)
