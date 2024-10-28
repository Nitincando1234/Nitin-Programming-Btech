echo "============================================================================================"
printf "              CPU usage printer (updates in 1 min interval)\n"
echo "============================================================================================"
i=1
while [ $i -le 5 ]
do 
	cpu_util=$(top -bn 1 | grep "Cpu(s)" | awk '{print $2 + $4}')
	printf "Cpu utilization at minute %d: %.2f%%\n" $i $cpu_util
	i=$((i + 1))
	sleep 60 
done
echo "Exiting..."
sleep 2
