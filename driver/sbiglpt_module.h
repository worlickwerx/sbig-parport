/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef _SBIGLPT_MODULE_H
#define _SBIGLPT_MODULE_H

#include <linux/parport.h>

#define DRIVER_VERSION_BCD	0x0435
#define DRIVER_VERSION_STRING	"4.35"

struct sbig_client {
	u8 control_out;
	u8 imaging_clocks_out;
	u16 last_error;
	u16 buffer_size;
	char *buffer;
	struct device *dev;
	struct parport *port;
};

static inline void sbig_outb(struct sbig_client *pd, u8 data)
{
	pd->port->ops->write_data(pd->port, data);
}

static inline u8 sbig_inb(struct sbig_client *pd)
{
	return pd->port->ops->read_status(pd->port);
}

#define sbig_dbg(pd, fmt, arg...) do { \
	if ((pd) && (pd)->dev) \
		dev_dbg((pd)->dev, fmt, ##arg); \
	else \
		pr_debug("sbiglpt: " fmt, ##arg); \
} while (0)

#define sbig_info(pd, fmt, arg...) do { \
	if ((pd) && (pd)->dev) \
		dev_info((pd)->dev, fmt, ##arg); \
	else \
		pr_info("sbiglpt: " fmt, ##arg); \
} while (0)

#define sbig_err(pd, fmt, arg...) do { \
	if ((pd) && (pd)->dev) \
		dev_err((pd)->dev, fmt, ##arg); \
	else \
		pr_err("sbiglpt: " fmt, ##arg); \
} while (0)

long sbig_ioctl(struct sbig_client *pd, unsigned int cmd, unsigned long arg,
		spinlock_t *spin_lock);

#endif /* !_SBIGLPT_MODULE_H */
