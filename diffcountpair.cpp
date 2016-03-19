#include <cstdint>

/**
 * count number of non-zero bitpairs (0,1) (2,3) ... (30,31)
 * @param n value
 * @return number of non-zero bit pairs
 **/
inline static unsigned int bitcountpair(uint32_t const n)
{
	return popcount8(((n >> 1) | n) & 0x55555555ul);
}

/**
 * count number of differing bitpairs (0,1) (2,3) ... (30,31)
 * @param a first value
 * @param b first value
 * @return number of differing bit pairs
 **/
inline static unsigned int diffcountpair(uint32_t const a, 
		uint32_t const b)
{
	return bitcountpair( a ^ b );
}
