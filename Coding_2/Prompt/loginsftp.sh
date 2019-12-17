#!/usr/bin/expect

set timeout 3
spawn sftp nmiao@pc20.cs.ucdavis.edu
expect "*password*"
send "A6n-SLf-XD4-ZTA\r"
expect "$*"
send "pwd\r"
expect "/home/nmiao*"
send "cd ecs60/p2\r"
expect "$*"
send "pwd\r"
expect "/home/nmiao/ecs60/p2*"
send "cd src\r"
expect "$*"
send "put *\r"

interact
