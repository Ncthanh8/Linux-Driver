#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

MODULE_LICENCE("GPL");
MODULE_AUTHOR("ME");
MODULE_DISCRIPTION("READ WRITE");

static char buffer[255];
static int buffer_pointer =0;

static dev_t my_device_nr;
static struct class *my_class;
static struct cdev device;

#define DRIVER_NAME "dummydriver"
#define DRIVER_CLASS "MyModuleClass"

/**
 * @brief read data out of buffer
 */

static ssize_t driver_read (struct file *File,char *user _buffer,size_t cnt , loff_t *off){
	int to_copy, not_copy, data;

	to_copy=min(count, buffer_pointer);

	not_copy=copy_to_user(user_buffer,buffer,to_copy);

	data= to_copy-not_copy;

	return data;
}

static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_nr - open was call");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance){
	printk("dev_nr - close was call");
	return 0;
}

static struct file_operations fops = {
	.ower = THIS_MODULE,
	.open = driver_open,
	.release = driver_close,
	.read = driver_read,
	.write = driver_write
};

static int __init ModuleInit(void){
	int retval;
	printk("He
