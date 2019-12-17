#!/usr/bin/expect

set timeout 3
spawn ssh nmiao@pc20.cs.ucdavis.edu
expect "*password*"
send "A6n-SLf-XD4-ZTA\r"
expect "$*"
send "pwd"
expect "/home/nmiao"
send "cd ecs60/p2"
expect "$*"


interact
