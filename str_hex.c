#include <stdio.h>
#include <string.h>

int HexToStr(unsigned char *hex, int length, char *str)
{
	if(length <= 0 )
	{
		return 0;
	}
	int i = 0, j = 0; 
	unsigned char *p = hex;
	unsigned char tmp = 0;
	for(i = 0; i < length;i++)
	{
		tmp = ( p[i] >> 4 )&0xf;
		if( tmp <= 9)
		{
			str[j] = tmp + '0';
		}else
		{
			str[j] = tmp + 'A' - 0x0a;
		} 
		j++;
		tmp = p[i]&0xf;
		if( tmp <= 9)
		{
			str[j] = tmp + '0';
		}else
		{
			str[j] = tmp + 'A' - 0x0a;
		} 
		j++;
	}
	return j;
} 



void StrToHex(unsigned char *pbDest, char *pbSrc, unsigned int nLen)

{

	char h1, h2;

	char s1, s2;

	int i;

	for (i = 0; i < nLen; i++)

	{

		if (pbSrc[2 * i] >= 'a' && pbSrc[2 * i] <= 'z')

		{

			pbSrc[2 * i] -= 'a' - 'A';
		}

		if (pbSrc[2 * i + 1] >= 'a' && pbSrc[2 * i + 1] <= 'z')

		{

			pbSrc[2 * i + 1] -= 'a' - 'A';
		}

		h1 = pbSrc[2 * i];

		h2 = pbSrc[2 * i + 1];

		s1 = h1 - 0x30;

		if (s1 > 9)

			s1 -= 7;

		s2 = h2 - 0x30;

		if (s2 > 9)

			s2 -= 7;

		pbDest[i] = s1 * 16 + s2;
	}
}

void main()
{
	unsigned char a[] = {0x1a, 0x2b, 0x3c, 0x4d, 0x5e};
	//unsigned char a[] = {0x12, 0x34, 0x56, 0x4d, 0x5e};
	unsigned char b[10] = {0};
	char a_str[20] = {0};
	int strLen = HexToStr(a, 5, a_str);
	printf("HexToStr strLen %d :%s\n", strLen, a_str);

	unsigned int hexLen = strLen/2;
	StrToHex(b, a_str, hexLen);
	int i = 0;
	for(i = 0; i < hexLen; i++)
	{
		printf("b[i] %02x\n", b[i]);
	}
}


