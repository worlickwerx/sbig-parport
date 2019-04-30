/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef _KSBIGLPTMAIN_H_
#define _KSBIGLPTMAIN_H_

#include <linux/parport.h>

#define DRIVER_VERSION 0x0435 // BCD version
#define DRIVER_STRING "4.35"

// The buffer may be resized via IOCTL_SET_BUFFER_SIZE call
#define LDEFAULT_BUFFER_SIZE 4096

struct sbig_client {
	unsigned long flags;
	unsigned long value;
	unsigned char control_out;
	unsigned char imaging_clocks_out;
	unsigned char noBytesRd;
	unsigned char noBytesWr;
	unsigned short state;
	unsigned short buffer_size;
	char *buffer;
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

#define sbig_dbg(pd, fmt, arg...) \
	dev_dbg((pd)->port->dev, fmt, ##arg)

#define sbig_info(pd, fmt, arg...) \
	dev_info((pd)->port->dev, fmt, ##arg)

#define sbig_err(pd, fmt, arg...) \
	dev_err((pd)->port->dev, fmt, ##arg)

long sbig_ioctl(struct sbig_client *pd, unsigned int cmd, unsigned long arg,
		spinlock_t *spin_lock);

#endif
