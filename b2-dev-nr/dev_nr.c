#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("DANG KI MOT DRIVER NR VA TRIEN KHAI HAM GOI LAI (CALLBACK FUNCTION)");

static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_nr - open was called ! \n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance){
	printk("dev_nr - close was called ! \n");
	return 0;
}


static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 64

static int __init ModuleInit(void){
	int retval;
	printk("Hello, Kernel! \n");

	retval = register_chrdev(MYMAJOR,"my_deb_nr", &fops);

	if(retval ==0){
		printk("dev_nr - resgister device number major : %d, minor : %d\n",MYMAJOR,0);
	}
	else if(retval > 0){
		printk("dev_nr - resgister device number major : %d, minor : %d\n",retval>>20, retval&0xfffff);
	}
	else{
		printk("Could not register device number!\n");
		return -1;
	}
	return 0;
}

static void __exit ModuleExit(void){
	unregister_chrdev(MYMAJOR,"my_dev_nr");
	printk("Bye , kernel !\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

