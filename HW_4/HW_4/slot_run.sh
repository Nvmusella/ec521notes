#!/bin/bash

end=$((SECONDS+60))
counter=0

while [ $SECONDS -lt $end ]; do
	./slots3 >> slot_out_bash.txt
	((counter++))
    :
done

echo $counter
