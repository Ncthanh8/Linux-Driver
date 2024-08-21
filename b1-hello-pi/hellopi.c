#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("HI LINUX DRIVER");


/*
 * Ham khoi tao se duoc goi khi kernel load module
 */

static int __init my_init(void){
	printk("Hello, kernel \n");
	return 0;
}

/*
 * Ham duoc goi khi kernel go bo module
 */

static void __exit my_exit(void){
	printk("Bye, Kernel \n");
}

module_init(my_init);
module_exit(my_exit);


