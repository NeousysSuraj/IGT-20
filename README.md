# IGT-20
IGT-20 is an ARM-based fanless industrial IoT(Internet of Things) and automation gateway.
The purpose of this repository is to introduce the user with programming the IGT-20
IGT-20 configuration of GPIO, connecting 4G, connecting to Wifi

GPIO
gpio.c file purpose is to provide visulization of inner mapping of GPIO pins in IGT-20.


Compile program in IGT-20
For example we can create a simple hello.c file in the root folder 
Create a file hello.c for sample purpose. After creating the file we can compile using following command
gcc -o hello hello.c

To execute the file run following command
./hello

To automatically Start the program, add these two line in /etc/rc.local file, where program name is the program you want to run as soon as the IGT-20 boots
 cd /root
/root/program_name
/*add those two-above line in /etc/rc.local*/
 exit 0
