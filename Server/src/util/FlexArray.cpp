#include "FlexArray.h"

template <>
void FlexArray<char>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<byte>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<short>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<ushort>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<int>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<uint>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<string>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}

template <>
void FlexArray<float>::Serialize(IMemoryStream *pStream)
{
    pStream->Serialize(&CurrentSize);
    if (CurrentSize > CurrentCapacity)
    {
        Reallocate(CurrentSize);
    }
    for (int i = 0; i < CurrentSize; i++)
    {
        pStream->Serialize(&pArray[i]);
    }
}
