#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <float.h>

// ベクトルクラス
class Vector
{

public:
    // コンストラクタ
    Vector()
        : X(0.0f), Y(0.0f), Z(0.0f) {}

    Vector(float InX, float InY, float InZ)
        : X(InX), Y(InY), Z(InZ) {}

    Vector(const Vector &Arg)
        : X(Arg.X), Y(Arg.Y), Z(Arg.Z) {}

    // 座標.
    float X;
    float Y;
    float Z;

    // サイズを取得.
    float GetSize() const
    {
        return sqrt(GetSizeSq());
    }

    // サイズの二乗を取得.
    float GetSizeSq() const
    {
        return ((X * X) + (Y * Y) + (Z * Z));
    }

    // 正規化したものを取得.
    Vector GetNormalized() const
    {
        float Size = GetSize();
        Vector Vec;
        Vec.X = X / Size;
        Vec.Y = Y / Size;
        Vec.Z = Z / Size;
        return Vec;
    }

    // 正規化.
    void Normalize()
    {
        Vector Vec = GetNormalized();
        *this = Vec;
    }

    // オペレータオーバーロード
    Vector operator+(const Vector &Arg) const
    {
        Vector Vec;
        Vec.X = X + Arg.X;
        Vec.Y = Y + Arg.Y;
        Vec.Z = Z + Arg.Z;
        return Vec;
    }

    Vector operator-(const Vector &Arg) const
    {
        Vector Vec;
        Vec.X = X - Arg.X;
        Vec.Y = Y - Arg.Y;
        Vec.Z = Z - Arg.Z;
        return Vec;
    }

    void operator+=(const Vector &Arg)
    {
        X += Arg.X;
        Y += Arg.Y;
        Z += Arg.Z;
    }

    void operator-=(const Vector &Arg)
    {
        X -= Arg.X;
        Y -= Arg.Y;
        Z -= Arg.Z;
    }

    Vector operator*(float Arg) const
    {
        Vector Vec;
        Vec.X = X * Arg;
        Vec.Y = Y * Arg;
        Vec.Z = Z * Arg;
        return Vec;
    }

    Vector operator/(float Arg) const
    {
        Vector Vec;
        Vec.X = X / Arg;
        Vec.Y = Y / Arg;
        Vec.Z = Z / Arg;
        return Vec;
    }

    void operator*=(float Arg)
    {
        X *= Arg;
        Y *= Arg;
        Z *= Arg;
    }

    void operator/=(float Arg)
    {
        X /= Arg;
        Y /= Arg;
        Z /= Arg;
    }

    bool operator==(const Vector &Arg) const
    {
        return (fabsf(X - Arg.X) < FLT_EPSILON && fabsf(Y - Arg.Y) < FLT_EPSILON && fabsf(Z - Arg.Z) < FLT_EPSILON);
    }

    bool operator!=(const Vector &Arg) const
    {
        return (fabsf(X - Arg.X) >= FLT_EPSILON || fabsf(Y - Arg.Y) >= FLT_EPSILON || fabsf(Z - Arg.Z) >= FLT_EPSILON);
    }

    // ゼロベクトル
    static const Vector Zero;
};

#endif // #ifndef VECTOR_H
