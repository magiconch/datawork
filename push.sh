#!/bin/bash
git add .
echo 输入注释
read mycommit
git commit -m $mycommit
git push origin master
