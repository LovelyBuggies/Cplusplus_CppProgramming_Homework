# [STL]IP and QQ (eden)

## Descrption
An ip can login several qqs, and a qq can be logined by several ips.

Your task is to find which qqs have been logined by the ip and which ips have
logined the qq.

output format : qq ==> [ ip1 ip2 ... ]  and ip ==> [ qq1 qq2 ... ]

if no such qq or ip, output "no qq" and "no ip"

First input n, then n+2 lines follow..

n lines:

qq ip

2 lines:

ip  // find which qqs have been logined by the ip

qq  // find which ips have logined the qq.



## sample input:
```
5  
10258279649 192.168.1.45  
10258279649 192.168.1.45  
10258279643 192.168.1.40  
10258279640 192.168.1.45  
10258279641 192.168.1.30  
192.168.1.45  
10258279649  
```

## sample output:
```
192.168.1.45 ==> [ 10258279640 10258279649 ]  
10258279649 ==> [ 192.168.1.45 ]  
```


## Hint
map

set

From: *黄浩然*

