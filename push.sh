#!/bin/bash
git add . && git add --all
echo 输入注释
read mycommit
git commit -m $mycommit
git push origin master && sh fuck.sh
