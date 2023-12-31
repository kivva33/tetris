#pragma once

using namespace System::Drawing;

void clear(Image^ img, Brush^ b);
//������������ ������
void multiply(array<float, 2>^ A, array<float, 2>^ B, array<float, 2>^ C);
//��������� �������
void identity_mat(array<float, 2>^ M);
//������� ������
void move_mat(float dx, float dy, array<float, 2>^ T);
//������� ���������������
void scale_mat(float kx, float ky, array<float, 2>^ S);
//������� ��������
void rotate_mat(float phi, array<float, 2>^ R);

PointF apply(PointF p, array<float, 2>^ M);

void scale_mat(PointF c, float kx, float ky, array<float, 2>^ S);

void rotate_mat(PointF c, float phi, array<float, 2>^ R);