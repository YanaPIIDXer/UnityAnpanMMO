#ifndef __ENDIANCONVERTER_H__
#define __ENDIANCONVERTER_H__

namespace YanaPOnlineUtil
{

/**
 * @class CEndianConverter
 * @brief エンディアン変換
 */
class CEndianConverter
{

public:

	/**
	 * @fn static bool IsLittleEndian()
	 * @brief リトルエンディアン？
	 * @return リトルエンディアンならtrueを返す。
	 */
	static bool IsLittleEndian()
	{
		int x = 1;
		char ch = (*(char *)&x);
		return (ch != 0);
	}

	/**
	 * @fn static short Convert(short Value, bool bForce = false)
	 * @brief short型変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
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
	 * @brief unsigned short変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
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
	 * @brief int変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
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
	 * @brief unsigned int変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
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
	 * @brief float変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
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

	//暗黙で定義されるものの封印
	CEndianConverter();
	CEndianConverter(const CEndianConverter &Arg);
	CEndianConverter operator =(const CEndianConverter &Arg);

};

}

#endif		//#ifndef __ENDIANCONVERTER_H__
