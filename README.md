# Mastering Linux Kernal Programming & Device Drivers

## INTRODUCTION
* Initiated by Linus Torvalds as a hobby project in 1991
* Inspired by Minix OS designed by Andrew S Tanenbaum
* Popular kernal for Free and Open Source Operating System, e.g. GNU Linux

## Advantages 
* Secure,Stable and Reliable
* Rich set of generic drivers
* Rich set of networking drivers & protocol stacks
* Upstream(mainline) and Downstream kernel
* Supported Languages - C and Assembly

## `Defining our Kernel`
At first, we have to download kernel from (https://kernel.org/) version 6.0.6.

* Create a clean Workspace
* Don't use Desktop,Downloads,Documents,Music,Videos,Pictures etc,which are meant for other purpose.
* Extract the downloaded kernel in your Workspace using following command:
```Defining our kernel
tar xvf filename
```

## Bulid Kernel
After Extract, navigate to the linux-6.0.6 folder and run the below commands 
* Follow the commands to build the kernel
```Build Kernel
make ARCH=arm mrproper
make ARCH=arm vexpress_defconfig
```
* Note: mrproper will remove built files,including the configuration.
* So run this only for any new build.

(OR) 

* customize kernal using menuconfig using following command:
```
make ARCH=arm menuconfig
```

* Now finally run this command for kernel to be bulid.
```
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
```

## Qemu setup
After kernel build, navigate to your workspace and follow commands
* Install Qemu,a full system emulator for ARM target architecture
```
sudo apt install qemu-system-arm
qemu-system-arm -version
qemu-system-arm -M ?
qemu-system-aarch64 -version
```

* Download core-image-minimal-qemuarm.ext4 using the below link
```
https://downloads.yoctoproject.org/releases/yocto/yocto-2.5/machines/qemu/qemuarm/
```
* Rename the file into rootfs.img and resize it using following commands
```
e2fsck -f rootfs.img
resize2fs rootfs.img 16M
```

* Install the requried toolchain
```
sudo apt install gcc-arm-linux-gnueabi
sudo apt install gcc-arm-linux-gnueabihf
```

## Qemu Run
Now you prepare yourself for the first boot 

* At first, in your workspace create a file called images/bootables
* Second, navigate to the ## linux-6.0.6/arch/arm/boot and copy the zImage file and paste it in the images/bootables folder
* Third, navigate to the ## linux-6.0.6/arch/arm/boot/dtb and copy the vexpress-v2p-ca9.dtb file and paste it in the images/bootables folder

* Now navigate to the images/bootables and type the following to make your first boot
```
qemu-system-arm -M vexpress-a9 -nographic -kernel zimage -dtb vexpess-v2p-ca9.dtb -sd rootfs.img -append "console=ttyAMA0 root=/dev/mmcblk0 ip=192.168.7.100" -net nic -net tap,ifname=tap0
```

* Login as root by typing "root"

* Now type this command to now the version of Qemu 
```
uname -r
uname -v

```

* command to know the login info 
```
uname -a
```

## Running program in Qemu 
Now create a sample hello_world.c to print hello world using printk

* Now, save and compile the program using the following command to run the program in arm architecture
```
gcc-arm-linux-gnueabi filename.c
```

* It will generate a a.out which will only excute in arm architecture

* Now, we are transfering the file using the Network or Mount Method

## Network Method

* In your folder where output file is generated, type the following command
```
ifconfig
```

* Previously we excuted the qemu command in which we set the ip address for qemu using name tap0
* In current directory, type the following commands
```
sudo ifconfig tap0 192.168.7.1
sudo cp a.out /srv/tftp/
```

* Now, navigate to Qemu terminal and type "ifconfig" and you can see a eth0 network with ip address set on it
* Type the following command in the qemu teminal
```
tftp -g 192.168.7.1 -r a.out
ls
```

* Now, by typing ls you can see the file a.out in the qemu terminal.
* Now type following commands to see the output in the qemu.
```
./a.out
```

* Now, you will see the output in the terminal.

##  Mount Method
* create a mounting named folder in images
* copy the a.out file to MountPoint/home/root/
* Unmount after copying
```
sudo mount rootfs.img MountPoint/
sudo cp a.out MountPoint/home/root
sudo umount Mountpoint
```

By typing ls command in qemu we can see a.out file 
then type ./a.out in qemu to get output of the file


## OUT TREE KERNEL

* out tree kernel is nothing but modules which are developed outside the source kernel
* create one folder outside the kernel directory then write a program as shown below
```
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static int __init hello_init(void){
   printk("Hello World..welcome\n");
   return 0;
}
static void __exit hello_exit(void){
   printk("Bye,Leaving the world\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENCE("GPL")
MODULE_AUTHOR("SHARATH");
MODULE_DESCRIPTION("A simple module");
```
* Now write a Makefile to compile and run the program 
* Make sure you CROSS COMPILE the program with this command ```ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-```
* Now after running the program you will get ```.ko``` file which means kernel output.
* Now copy this .ko file to target kernel either by using Mount Method or Network Method.
* After this login to Qemu when you do ls you will find .ko file.
* you can run this by using following commands.
```
insmod    -> which is used to insert the module
rmmod     -> which is used to remove the module
lsmod     -> it lists the loaded modules
dmesg     -> lists the log of messages
dmesg -c  -> lists the log of messages and clears the log
```
## IN TREE KERNEL

## Dynamic Module
* Dynamic module is nothing but it can load and unload at runtime
* when we copy the kernel output to target board we can load the modules using ```insmod``` and can be unloaded with ```rmmod```

## Static Module 
* These are quite opposite to dynamic modules. 
* Static modules present within the kernel if we want we can enable and disable it but we can not load unload  like dynamic modules

# gdb-debugger

## GDB installation

There are two ways you can install GDB on linux.

### Install pre-built gdb binaries

**On Debian and Ubuntu:**

```
sudo apt-get update
sudo apt-get install gdb
```

### compile gdb from source, compile and install

**On Debian and Ubuntu:**

Download source code.

```
wget "http://ftp.gnu.org/gnu/gdb/gdb-7.11.tar.gz"
```

Extract the source code.

```
tar -xvzf gdb-7.11.tar.gz
```

Configure, Compile, and install it.

```
cd gdb-7.11
./configure
make
make install
sudo make install (optional)
```
By default this will install gdb binaries in /usr/local/bin and libs in /usr/local/lib.

To check version and test whether gdb installed correctly.

```
gdb --version
```

## Example Debug C Program

Compile your C program with -g option. This allows the compiler to collect the debugging information.

```
cd gdb-debugger
gcc -g -o fibonacci fibonacci_naive.c
./fibonacci
```

Launch the C debugger (gdb).

```
gdb ./fibonacci
```

Set up a break point inside C program. The Syantx is `break line_number`

```
break 10
Breakpoint 1 at 0x400641: file fibonacci_naive.c, line 10.
```

Execute the C program in gdb debugger.

```
run
```

Once you executed the C program, it would execute until the first break point, and give you the prompt for debugging.

```
(gdb) run
Starting program: /home/arslan/github-repositories/gdb-debugger/fibonacci 

Breakpoint 1, main (argc=1, argv=0x7fffffffda48) at fibonacci_naive.c:10
10	int main(int argc, char** argv) {
```

* For all the options available for gdb are seen in the below link 
*  gdb-cheatsheet = (https://gist.github.com/rkubik/b96c23bd8ed58333de37f2b8cd052c30)

## Core Dumps
* core dump files contatins the information why the program crashes
* Generally core dump files are generated due to segmentation faults
* To enable core dumps, first check the maximum core dump size ``` ulimit -c```
* If the result of this is zero set the limit to the maximum ```ulimit -c unlimited```
* ```ulimit -a``` used to check sizes of all features
* A core dump will now be generated and placed in the location specified by /proc/sys/kernel/core_pattern
* we can modifiy the path of core dumped files
```
echo "<desired-file-path>/<desired-file-name>" > /proc/sys/kernel/core_pattern
for ex: echo /var/crash/core-%e > /proc/sys/kernel/core_pattern
```
* Here %e is for excutable files
* you can also use ```man core``` so that which file you want to save
* Now after changing the run any program which generates the segmentation fault
```
compile -> gcc -g filename.c -o filename
run -> ./filename
```
* Now you check ```ls /var/crash/``` a core dump file will be generated
* Ater that you can start debugging with gdb
```
gdb binary-file core-dumpfile
```

# Kernel Debugging Methods

## Kernel logging with printk

* printk is a C function from the Linux kernel interface that prints messages to the kernel log.
* prink supports various log levels. These loglevels indicate the significance of the message being logged.
* checkout this link for loglevels (https://www.oreilly.com/library/view/linux-kernel-in/0596100795/re06.html)
* To view log settings login to qemu and type
```
$ cat /proc/sys/kernel/printk
4   4   1   7
```
* 1st field shows the current loglevel
* 2nd field shows default log level
* 3rd field shows minimum number of loglevel kernel supports
* 4th field shows maximum number of loglevel kernel supports
## Changing loglevels
* There are different ways to chang loglevels
* 1.Modify the /proc entry
```$ echo 6 > /proc/sys/kernel/printk```
* 2.dmesg
* ``` dmesg -n 6```
* 3. sysrq file
* ``` echo 4 > /proc.sysrq-trigger```
* These are different methods to change loglevels
* Remember kernel supports upto 7 loglevels.

## OOPS Crash

```
arm-linux-gnueabi-addr2line -f pc value -e filename.ko
```
* it gives information at which line programe is failing
* Or insted of Address to line we can go with gdb
```
arm-linux-gnueabi-gdb filename.o
```


