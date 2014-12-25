
#ifndef _RTMP_AMF_H_
#define _RTMP_AMF_H_

/*
 The set of possible type markers are listed below (values are represented in hexadecimal format):
 number-marker =  0x00
 boolean-marker =  0x01
 string-marker =  0x02
 object-marker =  0x03
 movieclip-marker =  0x04	; reserved, not supported
 null-marker =  0x05
 undefined-marker =  0x06
 reference-marker =  0x07
 ecma-array-marker =  0x08
 object-end-marker =  0x09
 strict-array-marker =  0x0A
 date-marker =  0x0B
 long-string-marker =  0x0C
 unsupported-marker =  0x0D
 recordset-marker =  0x0E	; reserved, not supported
 xml-document-marker =  0x0F
 typed-object-marker =  0x10
NOTE: With the introduction of AMF 3 in Flash Player 9, a special type marker was added to AMF 0 to signal a switch to AMF 3 serialization. This allows NetConnection requests to start out in AMF 0 and switch to AMF 3 on the first complex type to take advantage of the more the efficient encoding of AMF 3.
avmplus-object-marker = 0x11
 */
typedef enum 
{
	V_NUMBER	= 0,
	V_BOOLEN	= 1,
	V_STRING	= 2,
	V_OBJECT	= 3,
	V_MOVIECLIP = 4,
	V_NULL		= 5,
	V_UNDEFINED = 6,
	V_REFERENCE = 7,
	V_ECMAARRAY = 8,
	V_OBJEND	= 9,
	V_ARRAY		= 10,
	V_TIMESTAMP = 11,
	V_LONGSTRING	= 12,
	V_UNSUPPORTED	= 13,
	V_RECORDSET		= 14,
	V_XML			= 15,
	V_TYPEDOBJ		= 16,
	V_AMF3			= 17
} amf0_variant_type;

typedef struct
{
	amf0_variant_type	type;	
	void*				value;
} amf0_variant;

/*
 * 
 */
int
amf0_read(const char*, amf0_variant*);

#endif //_RTMP_AMF_H_
