
#include <endian.h>
#include "rtmpAMF.h"

/*
 * amf0 decode
 * [IN]	buf : amf0 data to be decoded
 * [IN] buf_len : data length
 * [OUT] amf0_variant : pointer to decede result 
 * return: failure: -1
 *		   succeed: amf0 variable number of the result
 */
int
amf0_read(const char *buf, uint32_t buf_len, amf0_variant *result)
{
	char	*pos = buf;
	while(pos - buf > buf_len){
		;
	}
}

int
amf0_read_double(const char *buf, uint32_t buf_len, double *value)
{
	uint64_t	val
	if(buf_len < 8)
		return -1;
	memcpy(&val, buf, 8);
	//if network byte order is big endian
	val = be64toh(val);
	value = (double *)&val;
	return 0;
}

int
amf0_read_int(const char *buf, uint32_t buf_len, unsigned short *value)
{
	if(buf_len < 4)
		return -1;
	memcpy(&value, buf, 4);
	*value = be32toh(*value);
	return 0;
}

int
amf0_read_short(const char *buf, uint32_t buf_len, unsigned short *value)
{
	if(buf_len < 2)
		return -1;
	memcpy(&value, buf, 2);
	*value = be16toh(*value);
	return 0;
}

int
amf0_read_one(const char *buf, uint32_t buf_len, amf0_variant *result)
{
	char	*pos = buf;
	amf0_variant_type	type = (amf0_variant_type)*pos;
	pos++;
	switch(amf0_variant_type)
	{
	case V_NUMBER:
		amf0_read_double();
	}
}

void
amf0_object_destroy(amf0_object *obj)
{
	for(int i = 0; i < obj.num; i++){
		free(obj->item[i].name);
		amf0_variant_destroy(&(obj->property[i].value));
	}
	free(item);
}

void
amf0_variant_destroy(amf0_variant *var)
{
	switch(var->type)
	{
	case V_NUMBER:
	case V_BOOLEN:
	case V_STRING:
	case V_LONGSTRING:
		free(var->value);
		break;
	case V_OBJECT:
		amf0_object_destroy(var->value);
		break;

	default:
		;
	};
}
