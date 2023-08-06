#include "Details.h"
#include "kivva's_func.h"
#include <cmath>
#include <ctime>


void Detail::rotate(float phi) {
	array<float, 2>^ A = gcnew array<float, 2>(3, 3);
	array<float, 2>^ C = gcnew array<float, 2>(Size, Size);

	rotate_mat(center, phi, A);
	PointF k;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (detail_mat[i, j]) {
				k.X = i;
				k.Y = j;
				k = apply(k, A);
				C[(int)(round(k.X)), (int)(round(k.Y))] = detail_mat[i, j];
			}
		}
	}
	array<float, 2>::Copy(C, detail_mat, C->Length);
}
void Detail::mirror() {
	array<float, 2>^ C = gcnew array<float, 2>(Size, Size);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			C[i, j] = detail_mat[Size - i - 1, j];
		}
	}
	array<float, 2>::Copy(C, detail_mat, C->Length);
}

void Zulul::fill() {
	detail_mat[0, 0] = 0;
	detail_mat[1, 0] = 1;
	detail_mat[2, 0] = 1;
	detail_mat[0, 1] = 1;
	detail_mat[1, 1] = 1;
	detail_mat[2, 1] = 0;
	detail_mat[0, 2] = 0;
	detail_mat[1, 2] = 0;
	detail_mat[2, 2] = 0;
}
void Zulul::rotate(float phi) {
	array<float, 2>^ A = gcnew array<float, 2>(3, 3);
	array<float, 2>^ C = gcnew array<float, 2>(Size, Size);

	bool need = false;
	for (int i = 0; i < Size; i++)
		if (detail_mat[0, i]) {
			need = true;
			break;
		}

	if (need) 
		rotate_mat(center, phi, A);
	else 
		rotate_mat(center, (-1) * phi, A);
	PointF k;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (detail_mat[i, j]) {
				k.X = i;
				k.Y = j;
				k = apply(k, A);
				C[(int)(round(k.X)), (int)(round(k.Y))] = detail_mat[i, j];
			}
		}
	}
	array<float, 2>::Copy(C, detail_mat, C->Length);
}

void lalala_xz::fill(){
	detail_mat[0, 0] = 0;
	detail_mat[1, 0] = 1;
	detail_mat[2, 0] = 0;
	detail_mat[0, 1] = 1;
	detail_mat[1, 1] = 1;
	detail_mat[2, 1] = 1;
	detail_mat[0, 2] = 0;
	detail_mat[1, 2] = 0;
	detail_mat[2, 2] = 0;
}
void lalala_xz::rotate(float phi) {
	array<float, 2>^ A = gcnew array<float, 2>(3, 3);
	array<float, 2>^ C = gcnew array<float, 2>(Size, Size);
	rotate_mat(center, phi, A);
	PointF k;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (detail_mat[i, j]) {
				k.X = i;
				k.Y = j;
				k = apply(k, A);
				C[(int)(round(k.X)), (int)(round(k.Y))] = detail_mat[i, j];
			}
		}
	}
	array<float, 2>::Copy(C, detail_mat, C->Length);
}

void Square::rotate(float phi) {
	return;
}
void Square::fill() {
	detail_mat[0, 0] = 1;
	detail_mat[0, 1] = 1; 
	detail_mat[1, 0] = 1;
	detail_mat[1, 1] = 1;
}

void Cornered::fill() {
	detail_mat[0, 0] = 1;
	detail_mat[1, 0] = 0;
	detail_mat[2, 0] = 0;
	detail_mat[0, 1] = 1;
	detail_mat[1, 1] = 1;
	detail_mat[2, 1] = 1;
	detail_mat[0, 2] = 0;
	detail_mat[1, 2] = 0;
	detail_mat[2, 2] = 0;
}
void Cornered::rotate(float phi) {
	array<float, 2>^ A = gcnew array<float, 2>(3, 3);
	array<float, 2>^ C = gcnew array<float, 2>(Size, Size);

	rotate_mat(center, phi, A);

	PointF k;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (detail_mat[i, j]) {
				k.X = i;
				k.Y = j;
				k = apply(k, A);
				C[(int)(round(k.X)), (int)(round(k.Y))] = detail_mat[i, j];
			}
		}
	}
	array<float, 2>::Copy(C, detail_mat, C->Length);
}

void Stick::fill() {
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			detail_mat[i, j] = 0;
	for (int i = 0; i < Size; i++)
		detail_mat[i, 1] = 1;
}
void Stick::rotate(float phi) {
	array<float, 2>^ A = gcnew array<float, 2>(3, 3);
	array<float, 2>^ C = gcnew array<float, 2>(Size, Size);

	bool need = false;
	for(int i = 0; i < Size; i++)
		if (detail_mat[0, i]) {
			need = true;
			break;
		}

	if (need) 
		rotate_mat(center, phi, A);
	else
		rotate_mat(center, (-1) * phi, A);
	PointF k;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (detail_mat[i, j]) {
				k.X = i;
				k.Y = j;
				k = apply(k, A);
				C[(int)(round(k.X)), (int)(round(k.Y))] = detail_mat[i, j];
			}
		}
	}
	array<float, 2>::Copy(C, detail_mat, C->Length);
}

Detail^ generate_detail() {
	int k = rand() % 7 + 1;
	Detail^ d;
	switch (k)
	{
	case 1:
	{
		d = gcnew Zulul;
		break;
	}
	case 2:
		d = gcnew Cornered;
		break;
	case 3:
		d = gcnew lalala_xz;
		break;
	case 4:
		d = gcnew Square;
		break;
	case 5:
		d = gcnew Stick;
		break;
	case 6:
		d = gcnew Cornered;
		d->mirror();
		break;
	case 7:
		d = gcnew Zulul;
		d->mirror();
		break;
	default:
		d = gcnew Square;
		break;
	}
	return d;
}

