#!/bin/bash

ports="7001 8003 9009"
host="10.241.13.199"

for x in $ports
do
    hping3 -S -V -p $x $host
    sleep 1
done

hping3 -a $fakeaddr -S -V -c 3 -p 7001,8003,9009 $addr

hping3 -c 1 -S $addr -p $port; ... ; ...; 
nmap -n -Pn $addr -p  1-100 --max-rtt-timeout=50ms
10103
