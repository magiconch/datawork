#!/bin/bash
cd /home/master/datawork
git add . || git add --all
echo 输入注释
read mycommit
git commit -m $mycommit
echo 是否需要提交github"(y/n)"
read stat

[ 'X'$stat == 'X'"y" ] && git push origin master || sh fuck.sh
