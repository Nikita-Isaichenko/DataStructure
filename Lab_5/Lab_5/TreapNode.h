#pragma once

/**
 * \brief ������������ ���������� �� ������������� �������� ��������� ������.
 */
struct TreapElement
{
	/**
	 * \brief ��������� �� ����� �������.
	 */
	TreapElement* Left;

	/**
	 * \brief ��������� �� ������ �������.
	 */
	TreapElement* Right;

	/**
	 * \brief ��������.
	 */
	int Data;

	/**
	 * \brief ���������.
	 */
	int Priority;
};