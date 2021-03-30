#include "Util/CSVController.h"
#include <fstream>

namespace YanaPServer
{
namespace Util
{

// コンストラクタ
CCSVController::CCSVController()
{
}

// 読み込み
bool CCSVController::Load(const char *pFilePath)
{
	std::ifstream Stream(pFilePath);
	if (!Stream) { return false; }

	static const int BufferSize = 1024;
	char Buffer[BufferSize];

	while (Stream.getline(Buffer, BufferSize))
	{
		Columns Row;
		Split(Buffer, ",", Row);
		while (Row[Row.size() - 1] == "")
		{
			// 何故か空文字がブチ込まれている事がある。
			// Libre Officeの不具合か・・・？
			Row.erase(Row.end() - 1);
		}
		Rows.push_back(Row);
	}

	return true;
}

// 書き込み
bool CCSVController::Save(const char *pFilePath)
{
	std::ofstream Stream(pFilePath, std::ios::out);
	if (!Stream) { return false; }

	for (const auto &Row : Rows)
	{
		if (Row.size() == 0) { continue; }

		for (unsigned int i = 0; i < Row.size() - 1; i++)
		{
			Stream << Row[i];
			Stream << ",";
		}
		Stream << Row[Row.size() - 1];
		Stream << std::endl;
	}

	return true;
}

// 行データを取得.
bool CCSVController::GetRow(unsigned int Index, Columns &OutRow) const
{
	if (Index > Rows.size()) { return false; }

	OutRow.clear();
	for (const auto &Column : Rows[Index])
	{
		OutRow.push_back(Column);
	}

	return true;
}

// 行データを追加.
void CCSVController::AddRow(const Columns &Row)
{
	Rows.push_back(Row);
}

// 行データを更新.
void CCSVController::UpdateRow(unsigned int Index, const Columns &Row)
{
	if (Index >= Rows.size()) { return; }
	Rows[Index] = Row;
}


// Split
void CCSVController::Split(const char *pData, const std::string &Delimiter, std::vector<std::string> &OutResult)
{
	OutResult.clear();

	std::string Str = pData;
	if (Str.find_first_of(Delimiter) == std::string::npos)
	{
		// 区切り文字が見つからなかった場合はそのまま文字列をブチ込んで終了。
		OutResult.push_back(Str);
		return;
	}

	auto Offset = std::string::size_type(0);
	while (true)
	{
		auto Pos = Str.find(Delimiter, Offset);
		if (Pos == std::string::npos)
		{
			OutResult.push_back(Str.substr(Offset));
			break;
		}

		OutResult.push_back(Str.substr(Offset, Pos - Offset));
		Offset = Pos + Delimiter.length();
	}
}

}
}
