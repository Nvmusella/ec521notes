import time
import os
import subprocess


timeout_start = time.time()

# timeout variable can be omitted, if you use specific value in the while condition
timeout = 60   # [seconds]
#seven = "[seven] [seven] [seven]\n"
count = 0

while time.time() < timeout_start + timeout:
	
	output = subprocess.check_output("./slots3", shell=True)
	#os.system("./slots3") > out
	#print(len(output))
	print(output)
	count+=1
	#print(output[1])
	#if (output == seven):
		#++count
		
print(count)

