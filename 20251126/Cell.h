#pragma once

struct Cell
{
    Cell(int _x, int _y);
    int x{0}, y{0};


    // 演算子のオーバーロード
    // Cellどうしの加算
    Cell operator +(const Cell& other) const;
    //  Cellどうしの減算
    Cell operator -(const Cell& other) const;
    // Cellどうしの加算代入
    Cell& operator +=(const Cell& other);
    // Cellどうしの減算代入
    Cell& operator -=(const Cell& other);
    // Cellどうしの等価比較
    bool operator ==(const Cell& other) const;
    // Cellどうしの非等価比較
    bool operator !=(const Cell& other) const;
};

