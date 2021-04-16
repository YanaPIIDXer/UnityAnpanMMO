
#ifndef FLEXARRAY_H
#define FLEXARRAY_H

#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "YanaPOnlineUtil/Serializable/Serializable.h"
#include "type.h"
using namespace YanaPOnlineUtil::Stream;
using namespace YanaPOnlineUtil::Serializable;

template <typename T>
class FlexArray : public ISerializable
{

public:
    // コンストラクタ
    FlexArray(int DefaultCapacity = 20)
        : CurrentSize(0), CurrentCapacity(DefaultCapacity)
    {
        pArray = new T[DefaultCapacity];
    }

    // コピーコンストラクタ
    FlexArray(const FlexArray &Arg)
    {
        CurrentSize = Arg.CurrentSize;
        CurrentCapacity = Arg.CurrentCapacity;
        pArray = new T[CurrentCapacity];
        for (int i = 0; i < CurrentSize; i++)
        {
            pArray[i] = Arg[i];
        }
    }

    // 代入演算子
    void operator=(const FlexArray &Arg)
    {
        CurrentSize = Arg.CurrentSize;
        CurrentCapacity = Arg.CurrentCapacity;
        pArray = new T[CurrentCapacity];
        for (int i = 0; i < CurrentSize; i++)
        {
            pArray[i] = Arg[i];
        }
    }

    // デストラクタ
    ~FlexArray()
    {
        delete[] pArray;
    }

    // 追加.
    void PushBack(T NewItem)
    {
        if (CurrentSize + 1 > CurrentCapacity)
        {
            Reallocate(CurrentCapacity * 2);
        }

        pArray[CurrentSize] = NewItem;
        CurrentSize++;
    }

    // 挿入.
    void Insert(T NewItem, int Index)
    {
        if (CurrentSize + 1 > CurrentCapacity)
        {
            Reallocate(CurrentCapacity * 2);
        }

        for (int i = CurrentSize; i > Index; i--)
        {
            pArray[i] = pArray[i - 1];
        }
        pArray[Index] = NewItem;
        CurrentSize++;
    }

    // リアロケート
    void Reallocate(int Capacity)
    {
        CurrentCapacity = Capacity;
        T *pTmp = new T[Capacity];
        if (CurrentSize > Capacity)
        {
            CurrentSize = Capacity;
        }
        for (int i = 0; i < CurrentSize; i++)
        {
            pTmp[i] = pArray[i];
        }
        delete[] pArray;
        pArray = pTmp;
    }

    // 現在の要素数を取得.
    int GetCurrentSize() const { return CurrentSize; }

    // 指定した要素を消去.
    void Remove(T Item)
    {
        for (int i = 0; i < CurrentSize; i++)
        {
            if (Item == pArray[i])
            {
                for (int j = i; j < CurrentSize - 1; j++)
                {
                    pArray[j] = pArray[j + 1];
                }
                CurrentSize--;
                return;
            }
        }
    }

    // オペレータオーバーロード
    T operator[](int Index) const
    {
        return pArray[Index];
    }

    // シリアライズ
    virtual bool Serialize(IMemoryStream *pStream) override;

private:
    // 配列領域.
    T *pArray;

    // 現在の要素数.
    int CurrentSize;

    // 配列のキャパシティ
    int CurrentCapacity;
};

template <>
bool FlexArray<char>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<byte>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<short>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<ushort>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<int>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<uint>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<string>::Serialize(IMemoryStream *pStream);
template <>
bool FlexArray<float>::Serialize(IMemoryStream *pStream);

template <typename T>
bool FlexArray<T>::Serialize(IMemoryStream *pStream)
{
    if (!pStream->Serialize(&CurrentSize))
    {
        return false;
    }
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        if (!pStream->Serialize(&pArray[i]))
        {
            return false;
        }
    }
    return true;
}

#endif // #ifndef FLEXARRAY_H
