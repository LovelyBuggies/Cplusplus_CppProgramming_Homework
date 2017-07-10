# [STL] DNS (eden)

## Descrption
>  DNS, Domain Name System, is a very complicated system.
  It help people get rid of typing ip address to visit internet.
 When you open _www.baidu.com _on your web browser, you actually open 123.125.114.144, (the root server of www.baidu.com).
 DNS links one domain name(域名) to many ip address(ip 地址).
 
Please implement the dns system.   
To simplify the problem, we use _**map< string, vector<string  **_to store the relationship between domain name and ip addresses

## Note
 **Read dns.h for more details!**

## Sample Input

    
    
    dns dns114("114.114.114.114");
    dns114["www.baidu.com"].push_back("123.125.114.144");
    dns114["www.baidu.com"].push_back("220.181.57.217");
    dns114["www.baidu.com"].push_back("180.149.132.47");
    dns114.nslookup("www.baidu.com");
    dns114.nslookup("www.google.com");

## Sample Output

    
    
    Server: 114.114.114.114
    Name: www.baidu.com
    Address: 123.125.114.144
    Name: www.baidu.com
    Address: 220.181.57.217
    Name: www.baidu.com
    Address: 180.149.132.47
    Server: 114.114.114.114
    Server can't find www.google.com