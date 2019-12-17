#!/usr/bin/expect
  
set timeout 3
spawn sftp nmiao@pc20.cs.ucdavis.edu
expect "*password*"
send "A6n-SLf-XD4-ZTA\r"
send "cd ecs60/p1/Final"
send "put *"

interact
