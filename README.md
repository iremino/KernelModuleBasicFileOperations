# Welcome to the basic kernel module file operations example

Uses kernel file_operations struct, defines open/release/write/read functionalities

# How to Build
* Give necessary permissions to run.sh file
```
sudo chmod 777 run.sh
```

* Run run.sh file
```
./run.sh
```

* open syslog and check major and minor numbers of your module, change line 12 with the mknod command that you see in the syslog
```
tail /var/log/syslog
ubuntu kernel: I was assigned major number 240. To talk to
ubuntu kernel: the driver, create a dev file with
ubuntu kernel: 'mknod /dev/mychardev c 240 0'.
```
you must change line 12 of run.sh with this 'mknod /dev/mychardev c 240 0'

* then remove comment lines of 12,15,18 and 19, and run ./run.sh again
```
./run.sh
```

# Notes

* test.c file tests the open/release/write and read functionalities of our module
* With the mknod command, a character device was crated with the given name (here is mychardev) under the /dev directory
