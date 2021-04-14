#include "FlexArray.h"

template <>
bool FlexArray<char>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<byte>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<short>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<ushort>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<int>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<uint>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<string>::Serialize(IMemoryStream *pStream)
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

template <>
bool FlexArray<float>::Serialize(IMemoryStream *pStream)
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
