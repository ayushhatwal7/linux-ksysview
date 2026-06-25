#define pr_fmt(fmt) "%s: %s: %d: "fmt, KBUILD_MODNAME, __func__, __LINE__
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_VERSION("0.1");
MODULE_AUTHOR("Ayush Hatwal");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("This is the proc module which act as the main interface to proc filesystem and displaying all the details.");

extern void ksysview_core_sysinfo(char* buf, size_t len);

int __init ksysview_proc_module_init(void)
{
	char buf[256] = {0};
	pr_info("Init");

	ksysview_core_sysinfo(buf, 256);
	pr_info("System Info: %s", buf);
	return 0;
}

void __exit ksysview_proc_module_exit(void)
{
       pr_info("Exit");
}

module_init(ksysview_proc_module_init);
module_exit(ksysview_proc_module_exit);
