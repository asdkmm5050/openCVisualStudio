#pragma once
class Box
{
public:
	int top;
	int down;
	int left;
	int right;
	Box(int, int, int, int);
	~Box();
};