count=0
str=''
for i in {1..100}
do
  str=$str$i'+'
  #echo $count'+'$i'='
	((count = i + $count))
  #echo $count
done
echo $count"="$str
