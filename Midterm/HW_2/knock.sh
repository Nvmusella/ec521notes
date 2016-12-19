#!/bin/bash


host="10.241.13.199"

for x in 7000-7009
do
	for y in 8000-8009
	do
		for z in 9000-9009
		do
    			nmap -Pn --host_timeout 100 --max-retries 0 -p $x $host
			sleep 1
			nmap -Pn --host_timeout 100 --max-retries 0 -p $y $host
			sleep 1
			nmap -Pn --host_timeout 100 --max-retries 0 -p $z $host
    			sleep 1
			nmap -Pn -v --host_timeout 200 --max-retries 0 $host
		done
	done
done
7001
8003
9009

nmap -Pn --host_timeout 100 --max-retries 0 -p $x $hostnmap 
nmap -T5 -Pn --max-rtt-timeout=5ms -p100-600 10.241.13.199
