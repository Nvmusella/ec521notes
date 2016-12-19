#!/bin/bash


host="10.241.13.199"

for x in 7000-7009
do
	for y in 8000-8009
	do
		for z in 9000-9009
		do
			knock 10.241.13.199 $x:tcp $y:tcp $z:tcp
			sleep 1
			nmap -Pn -T4 --host_timeout 100 --max-retries 0 $host
		done
	done
done
