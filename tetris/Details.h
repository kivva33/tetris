#pragma once

#include "kivva's_func.h"

ref class Detail {
protected:
	PointF center;
	array<float, 2>^ detail_mat;
	int Size;
	virtual void fill() = 0;
public:
	Detail() {
		detail_mat = gcnew array<float, 2>(Size, Size);
	}
	virtual void rotate(float phi);
	void mirror();
	array<float, 2>^ Get_mat() {
		return detail_mat;
	}
	int GetSize() {
		return Size;
	}
};

ref class Zulul : public Detail {//неправильный поворот детали зигзаг
public:
	Zulul() {
		Size = 3;
		center.X = 1;
		center.Y = 1;
		detail_mat = gcnew array<float, 2>(Size, Size);
		fill();
	}
	void rotate(float phi) override;
protected:
	void fill() override;
};

ref class lalala_xz : public Detail {
public:
	lalala_xz() {
		Size = 3;
		center.X = 1;
		center.Y = 1;
		detail_mat = gcnew array<float, 2>(Size, Size);
		fill();
	}
	void rotate(float phi) override;
protected:
	void fill() override;
};

ref class Square : public Detail {
public:
	Square() {
		Size = 2;
		detail_mat = gcnew array<float, 2>(Size, Size);
		fill();
	}
	void rotate(float phi) override;
protected:
	void fill() override;
};

ref class Cornered : public Detail {
public:
	Cornered() {
		Size = 3;
		center.X = 1;
		center.Y = 1;
		detail_mat = gcnew array<float, 2>(Size, Size);
		fill();
	}
	void rotate(float phi) override;
protected:
	void fill() override;
};
ref class Stick : public Detail {
public:
	Stick() {
		Size = 4;
		center.X = 1;//где центр?
		center.Y = 1;
		detail_mat = gcnew array<float, 2>(Size, Size);
		fill();
	}
	void rotate(float phi) override;
protected:
	void fill() override;

};

Detail^ generate_detail();