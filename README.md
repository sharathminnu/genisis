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
At first, we have to download kernel from ![kernel.org](https://kernel.org/) version 6.0.6.

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

* Now, we are transfering the file using the Network 
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
* some commands used 
```
insmod -> which is used to insert the module
rmmod -> which is used to remove the module
lsmod -> it lists the loaded modules
dmesg -> lists the log of messages
dmesg -c ->lists the log of messages and clears the log
```
## IN TREE KERNEL

## Dynamic Module
* Dynamic module is nothing but it can load and unload at runtime
* when we copy the kernel output to target board we can load the modules using ```insmod``` and can be unloaded with ```rmmod```

## Static Module 
* These are quite opposite to dynamic modules. 
* Static modules present within the kernel if we want we can enable and disable it but we can not load unload  like dynamic modules
