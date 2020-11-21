/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __BRCMSTB_SOC_H
#define __BRCMSTB_SOC_H

static inline u32 BRCM_ID(u32 reg)
{
	return reg >> 28 ? reg >> 16 : reg >> 8;
}

static inline u32 BRCM_REV(u32 reg)
{
	return reg & 0xff;
}

/*
 * Helper functions for getting family or product id from the
 * SoC driver.
 */
u32 brcmstb_get_family_id(void);
u32 brcmstb_get_product_id(void);

int brcmstb_regsave_init(void);

#ifdef CONFIG_BRCMSTB_MEMORY_API
int brcmstb_memory_phys_addr_to_memc(phys_addr_t pa);
u64 brcmstb_memory_memc_size(unsigned int memc);
#else
static inline int brcmstb_memory_phys_addr_to_memc(phys_addr_t pa)
{
	return -EINVAL;
}

static inline u64 brcmstb_memory_memc_size(int memc)
{
	return -1;
}
#endif

#endif /* __BRCMSTB_SOC_H */
