#ifndef __CSVCONTROLLER_H__
#define __CSVCONTROLLER_H__

#include <vector>
#include <string>

namespace YanaPServer
{
namespace Util
{

typedef std::vector<std::string> Columns;

/**
 * @class CCSVController
 * @brief CSV制御
 */
class CCSVController
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CCSVController();

	/**
	 * @brief デストラクタ
	 */
	~CCSVController() {}

	/**
	 * @fn bool Load(const char *pFilePath)
	 * @brief 読み込み
	 * @param[in] pFilePath ファイルパス
	 * @return 成功したらtrueを返す
	 */
	bool Load(const char *pFilePath);

	/**
	 * @fn bool Save(const char *pFilePath)
	 * @brief 書き込み
	 * @param[in] pFilePath ファイルパス
	 * @return 成功したらtrueを返す
	 */
	bool Save(const char *pFilePath);

	/**
	 * @fn bool GetRow(unsigned int Index, Columns &OutRow) const
	 * @brief 行データを取得
	 * @param[in] Index インデックス
	 * @param[out] OutRow 行データ
	 * @return 成功したらtrueを返す
	 */
	bool GetRow(unsigned int Index, Columns &OutRow) const;

	/**
	 * @fn unsigned int GetRowCount() const
	 * @brief 行数を取得
	 * @return 行数
	 */
	unsigned int GetRowCount() const { return Rows.size(); }

	/**
	 * @fn void AddRow(const Columns &Row)
	 * @brief 行データを末尾に追加
	 * @param[in] Row 行データ
	 */
	void AddRow(const Columns &Row);

	/**
	 * @fn void UpdateRow(unsigned int Index, const Columns &Row)
	 * @brief 行データを更新
	 * @param[in] Index 更新する行のインデックス
	 * @param[in] Row 行データ
	 */
	void UpdateRow(unsigned int Index, const Columns &Row);

private:

	// 行データ
	std::vector<Columns> Rows;


	// Split
	static void Split(const char *pData, const std::string &Delimiter, std::vector<std::string> &OutResult);

};

}
}

#endif		// #ifndef __CSVCONTROLLER_H__
