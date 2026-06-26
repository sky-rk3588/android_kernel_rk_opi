// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * iDroid remote keymap
 *
 * Used on Orange Pi 5 Plus
 */

#include <media/rc-map.h>
#include <linux/module.h>

static struct rc_map_table idroid[] = {
	{ 0x4cb3, KEY_POWER },
	{ 0xccb3, KEY_HOME },
	{ 0x2cb3, KEY_MENU },
	{ 0xacb3, KEY_BACK },

	{ 0x0cb3, KEY_UP },
	{ 0x8cb3, KEY_DOWN },
	{ 0x44b3, KEY_LEFT },
	{ 0xc4b3, KEY_RIGHT },
	{ 0x24b3, KEY_OK },

	{ 0xa4b3, KEY_VOLUMEUP },
	{ 0x64b3, KEY_VOLUMEDOWN },
};

static struct rc_map_list idroid_map = {
	.map = {
		.scan = idroid,
		.size = ARRAY_SIZE(idroid),
		.rc_proto = RC_PROTO_NEC,
		.name = RC_MAP_IDROID,
	}
};

static int __init init_rc_map_idroid(void)
{
	return rc_map_register(&idroid_map);
}

static void __exit exit_rc_map_idroid(void)
{
	rc_map_unregister(&idroid_map);
}

module_init(init_rc_map_idroid);
module_exit(exit_rc_map_idroid);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Orange Pi Community");
