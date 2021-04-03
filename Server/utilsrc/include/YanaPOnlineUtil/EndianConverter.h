#ifndef __ENDIANCONVERTER_H__
#define __ENDIANCONVERTER_H__

namespace YanaPOnlineUtil
{

/**
 * @class CEndianConverter
 * @brief �G���f�B�A���ϊ�
 */
class CEndianConverter
{

public:

	/**
	 * @fn static bool IsLittleEndian()
	 * @brief ���g���G���f�B�A���H
	 * @return ���g���G���f�B�A���Ȃ�true��Ԃ��B
	 */
	static bool IsLittleEndian()
	{
		int x = 1;
		char ch = (*(char *)&x);
		return (ch != 0);
	}

	/**
	 * @fn static short Convert(short Value, bool bForce = false)
	 * @brief short�^�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
	 */
	static short Convert(short Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			Value = (((Value << 8) & 0xFF00) | ((Value >> 8) & 0x00FF));
		}
		return Value;

	}

	/**
	 * @fn static unsigned short Convert(unsigned short Value, bool bForce = false)
	 * @brief unsigned short�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
	 */
	static unsigned short Convert(unsigned short Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			Value = (((Value << 8) & 0xFF00) | ((Value >> 8) & 0x00FF));
		}
		return Value;

	}

	/**
	 * @fn static int Convert(int Value, bool bForce = false)
	 * @brief int�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
	 */
	static int Convert(int Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			short Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low, bForce) << 16) | Convert(High, bForce);
		}
		return Value;

	}

	/**
	 * @fn static unsigned int Convert(unsigned int Value, bool bForce = false)
	 * @brief unsigned int�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
	 */
	static unsigned int Convert(unsigned int Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			unsigned short Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low, bForce) << 16) | Convert(High, bForce);
		}
		return Value;
	}

	/**
	 * @fn static float Convert(float Value, bool bForce = false)
	 * @brief float�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
	 */
	static float Convert(float Value, bool bForce = false)
	{
		union FloatConv
		{
			unsigned int u;
			float f;
		};

		FloatConv Conv;

		Conv.f = Value;
		Conv.u = Convert(Conv.u, bForce);

		return Conv.f;
	}

private:

	//�ÖقŒ�`�������̂̕���
	CEndianConverter();
	CEndianConverter(const CEndianConverter &Arg);
	CEndianConverter operator =(const CEndianConverter &Arg);

};

}

#endif		//#ifndef __ENDIANCONVERTER_H__
