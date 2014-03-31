#ifndef __LINUX_FIB_RULES_H
#define __LINUX_FIB_RULES_H

#include <linux/types.h>
#include <linux/rtnetlink.h>

#define FIB_RULE_PERMANENT	0x00000001
#define FIB_RULE_INVERT		0x00000002
#define FIB_RULE_UNRESOLVED	0x00000004
#define FIB_RULE_IIF_DETACHED	0x00000008
#define FIB_RULE_DEV_DETACHED	FIB_RULE_IIF_DETACHED
#define FIB_RULE_OIF_DETACHED	0x00000010

#define FIB_RULE_FIND_SADDR	0x00010000

struct fib_rule_hdr {
	__u8		family;
	__u8		dst_len;
	__u8		src_len;
	__u8		tos;

	__u8		table;
	__u8		res1;	
	__u8		res2;	
	__u8		action;

	__u32		flags;
};

enum {
	FRA_UNSPEC,
	FRA_DST,	
	FRA_SRC,	
	FRA_IIFNAME,	
#define FRA_IFNAME	FRA_IIFNAME
	FRA_GOTO,	
	FRA_UNUSED2,
	FRA_PRIORITY,	
	FRA_UNUSED3,
	FRA_UNUSED4,
	FRA_UNUSED5,
	FRA_FWMARK,	
	FRA_FLOW,	
	FRA_UNUSED6,
	FRA_UNUSED7,
	FRA_UNUSED8,
	FRA_TABLE,	
	FRA_FWMASK,	
	FRA_OIFNAME,
	FRA_UID_START,	/* UID range */
	FRA_UID_END,
	__FRA_MAX
};

#define FRA_MAX (__FRA_MAX - 1)

enum {
	FR_ACT_UNSPEC,
	FR_ACT_TO_TBL,		
	FR_ACT_GOTO,		
	FR_ACT_NOP,		
	FR_ACT_RES3,
	FR_ACT_RES4,
	FR_ACT_BLACKHOLE,	
	FR_ACT_UNREACHABLE,	
	FR_ACT_PROHIBIT,	
	__FR_ACT_MAX,
};

#define FR_ACT_MAX (__FR_ACT_MAX - 1)

#endif
