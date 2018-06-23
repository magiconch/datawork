# 求两个文件的交集
# 并集
# 补集

# 1.读取两个文件。
cat data1.txt data2.txt | sort | uniq -d
cat data1.txt data2.txt | sort | uniq
cat data1.txt data2.txt | sort | uniq -u



