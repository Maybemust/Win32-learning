#pragma once
#include "stdafx.h"

// ��������
void Number(HWND, HWND, HWND, wstring, wstring, bool&);

// �������
void Operator(HWND, HWND, HWND, wstring, bool&);

// ������
void Equal(HWND, HWND, HWND, wstring, bool&);

// ����С����
// �ж�����Ļ���Ƿ���С����
void Dot(HWND, HWND, HWND, bool&);

// �������
void Sqrt(HWND, HWND, HWND, bool&);

// ���
void Clear(HWND, HWND, bool&);