#to clean
sudo rmmod basicChardev
sudo rm -r /dev/mychardev

#build char dev module
make

#insmod module
sudo insmod basicChardev.ko

#create a device
#sudo mknod /dev/mychardev c 240 0

#give related permissions
#sudo chmod 777 /dev/mychardev

#test read/write/open/close functionalities
#gcc test.c -o test
#./test
