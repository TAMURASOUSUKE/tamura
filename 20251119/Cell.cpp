#include "Cell.h"


// Cellどうしの加算
Cell Cell::operator +(const Cell& other) const {
	return Cell(x + other.x, y + other.y);
}


// Cellどうしの減算
Cell Cell::operator -(const Cell& other) const {
	return Cell(x - other.x, y - other.y);
}


// 加算の二項演算子
Cell& Cell::operator +=(const Cell& other) {
	x += other.x;
	y += other.y;
	return *this;
}

// 減算の二項演算子
Cell& Cell::operator -=(const Cell& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}


// 等価比較
bool Cell::operator== (const Cell& other) const {
	return (x == other.x && y == other.y);
}


// 非等価比較
bool Cell::operator!= (const Cell& other) const {
	return (x != other.x || y != other.y);
}