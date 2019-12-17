#!/usr/bin/expect

set timeout 3
spawn ssh nmiao@pc20.cs.ucdavis.edu
expect "*password*" 
send "A6n-SLf-XD4-ZTA\r"
interact
