## BY Advitiya Brijesh ##
################################SHELL SCRIPT TO GENERATE INPUT OUTPUT AND MATCHING THEM #####################
#g++ should be installed in the linux system . compile files using "g++ xyz.cpp" 
#SET THE PARAMETERS BELOW WITH APPROPRIATE NAMES USED 
#SET THE EXECUTION TIMING ACCORDING TO YOUR PROBLEM , AND THE EXECTION TIME OF BRUTE TOO


a=0
generator_code="generate_my.cpp"
sleeping_time=1
input_file_name="inp"
number_of_files=10 
brute_code_name="brute.cpp"
main_code="one.cpp"
output_file="out"
execution_time=1
brute_execution_time=1
bruteout="bruteout"
execute="./a.out"

if g++ "$generator_code" ; then 
echo "compilation of generator code Success!";

else 
echo "compliation of generator code Failure"; 
exit 0	
fi
while [ "$a" -lt 1 ]   
do
   b=0

   while [ "$b" -lt "$number_of_files" ]
   do
	   ./"$execute">"$input_file_name$b"
   	   b=`expr $b + 1`
   	   sleep "$sleeping_time"
   	   echo "input file $b generated successfully"
   done
   echo "--------------------------------------All input files have been generated successfully---------------------"
   echo "--------------------------------------now validating for input files---------------------------------------"
   flag=0
   for ((i=1;i<"$number_of_files";i++))
   do
   		for((j=$i+1;j<"$number_of_files";j++))
   		do
			DIFF=$(diff "$input_file_name$i" "$input_file_name$j") 
			if [ "$DIFF" == "" ] 
			then
				echo "$i $j input file matched please increase the waiting time above"
			    flag=1
			    exit 0
			fi
   		done
   done
   a=`expr $a + 1`
done

if [ "$flag" == 0 ]
then
	echo "all the inputs are generated and checked"
fi

if g++ "$brute_code_name" -o xyz; then 
echo "compilation of brute code Success!";

else 
echo "compliation of brute code Failure"; 
exit 0
fi

if g++ "$main_code" -o xyz1; then 
echo "compilation of main code Success!";

else 
echo "compliation of brute code Failure"; 
exit 0
fi


echo "----------------------------compiling files--------------------------------------"


flag=0
for((i=0;i<"$number_of_files";i++))
do
	./xyz<"$input_file_name$i">"$bruteout"
	./xyz1<"$input_file_name$i" >"$output_file$i"
	DIFF=$(diff  "$bruteout" "$output_file$i")
	#echo $DIFF 
	if [ "$DIFF" != "" ] 
	then
		echo
		echo "$DIFF" | cut -c1-100
		echo "mismatch from brute code at file input $i"
	    flag=1
	    exit 0
	fi
	echo "file  $i matching done "

done

if [ "$flag" == 0 ]
then
	echo "all the inputs are matched with the output of brute code"
fi
	 
