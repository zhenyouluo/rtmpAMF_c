
#include <endian.h>
#include <stdio.h>
#include <stdint.h>
/*
#define htonll(x) \
	                    ((uint64_t)( \
							                    ((((uint64_t)(x)) & 0xff00000000000000LL) >> 56) | \
							                    ((((uint64_t)(x)) & 0x00ff000000000000LL) >> 40) | \
							                    ((((uint64_t)(x)) & 0x0000ff0000000000LL) >> 24) | \
							                    ((((uint64_t)(x)) & 0x000000ff00000000LL) >> 8) | \
							                    ((((uint64_t)(x)) & 0x00000000ff000000LL) << 8) | \
							                    ((((uint64_t)(x)) & 0x0000000000ff0000LL) << 24) | \
							                    ((((uint64_t)(x)) & 0x000000000000ff00LL) << 40) | \
							                    ((((uint64_t)(x)) & 0x00000000000000ffLL) << 56) \
							                    ))
#define ntohll(x)   htonll(x)
*/

#define swap(a,b)	\
do{ \
	a = a + b;  \
	b = a - b;  \
	a = a - b;  \
	}while(0);    

void
htonll(unsigned char *data)
{
	swap(data[0], data[7]);
	swap(data[1], data[6]);
	swap(data[2], data[5]);
	swap(data[3], data[4]);
}

int
main(int argc, char *argv[])
{
	char	buf[] = {0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	char	buf_rev[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f};
	double	*db;
	uint64_t	*num = buf;
	db = num;
	printf("%lf\n", *db);

	//*num = htonll(*num);
	*num = be64toh(*num);
	db = num;
	printf("%lf\n", *db);

	return 0;
}
