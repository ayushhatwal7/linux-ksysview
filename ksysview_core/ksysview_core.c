#define pr_fmt(fmt) "%s: %s: %d: "fmt, KBUILD_MODNAME, __func__, __LINE__
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


MODULE_VERSION("0.1");
MODULE_AUTHOR("Ayush Hatwal");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("This is the core module containing the functions to support the proc module");

void ksysview_core_sysinfo(char* buf, size_t len)
{
	if (buf == NULL)
		return;

	memset(buf, 0, len);
	strlcat(buf, "Test system info", len);
}

EXPORT_SYMBOL(ksysview_core_sysinfo);

int __init ksysview_core_module_init(void)
{
       pr_info("Init");
       return 0;
}

void __exit ksysview_core_module_exit(void)
{
       pr_info("Exit");
}

module_init(ksysview_core_module_init);
module_exit(ksysview_core_module_exit);
