# [Classes and Objects] Bank Account

## Descrption
Implement the classes with given headers.

IMPORTANT explanations:  
Global:  
1. If any operation is invalid, return false and do nothing.  
2. All kind of accounts should at least keep _balance not less than 0.01
(expect for class 'Account'), all operations against this rule will be
invalid.     
3. vars like '_total_*_account' used to count the number of alive objects of
the class.  
4. reset() function means turn account into initial statement, but it would not
reset the '_id'.  
5. profile() function ask you to describe the object as a std::string  
   format for class 'Account': `"ID:%d\nBALANCE:%.6lf\nVALID:N\n"`      
   format for class 'PersonalAccount':
`"ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:PERSONAL\n"  `   
   format for class 'VIPAccount':
`"ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:VIP\nLOAN:%.6lf,LIMIT:%.6lf\n"`   
  
In class 'Account':  
1. Account is not for application so set _id=_balance=0 in Account::Account()
and _valid for 'Account' is always false.  
  
In class 'PersonalAccount':  
1. you should name _id as 12010000, 12010001, 12010002 .....with the static var
'_acc_id_ptr'  
2. _balance initial set as 10, _valid for true  
  
In class 'VIPAccount':  
1. you should name _id as 12050000, 12050001, 12050003 .....with the static var
'_acc_id_ptr'  
2. _balance initial set as 10, _valid for true  
3. VIP accounts can take loan(从银行贷款) with limit(we define it as 1000). Once an
account loan some money, the var _loan should add to it, then the money goes
into the _balance. No one can loan more money than the limit(not including
repaid).  
4. VIP accounts also can repay the debt with the money of his own balance
account. All or part of the debt are both ok.

中文描述摘要：  
1. 对于非法的操作，什么也不做然后返回false  
2. PersonalAccount和VIPAccount的余额要保证不低于0.01，违反此条的操作视为非法  
3. 类似于 _total_*_account 的变量用来计存活对象的个数  
4. profile方法是将对象描述为字符串。格式已给出（在上面）。  
5. Account类不直接应用，所以_id _balance _valid等属性均设为0  
6. PerosonalAccount 和 VIPAccount 对象的_id应为系统自动命名，照上面说明。  
7. VIP账号可以在不超过额度的范围内贷款和还贷，所贷款项存入balance账户并记录在_loan变量里，还贷也是从balance账户出钱。  
8. reset方法不会重置_id。  
9. 中文描述不能替代英文描述，仅辅助理解。  

**还款的金额的范围是0到balance-0.01，超过欠款则还清欠款**

*出题人：范子垚*
