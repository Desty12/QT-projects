#ifndef WINCALCULATOR_H
#define WINCALCULATOR_H
#pragma execution_character_set("utf-8") //֧�ֺ�����ʾ����Ҫ���ͼ�ν���������ʾ���������
#include <QtGui/QMainWindow>
#include "ui_wincalculator.h"
#define maxCharNum 20

class winCalculator : public QMainWindow
{
	Q_OBJECT

public:
	winCalculator(QWidget *parent = 0, Qt::WFlags flags = 0);
	~winCalculator();

private:
	Ui::winCalculatorClass ui;

	bool  isEqual;  // ����Ƿ��µ��ںţ�Ĭ��û�а��µ��ں�

	private slots:

		// �������
		void on_clearBtn_clicked();

		// ɾ��һ���ַ�
		void on_delBtn_clicked();


		// 1�������
		void on_oneBtn_clicked();

		// 2�������
		void on_twoBtn_clicked();

		// 3�������
		void on_threeBtn_clicked();

		// 4�������
		void on_fourBtn_clicked();

		// 5�������
		void on_fiveBtn_clicked();

		// 6�������
		void on_sixBtn_clicked();

		// 7�������
		void on_sevenBtn_clicked();

		// 8�������
		void on_eightBtn_clicked();

		// 9�������
		void on_nineBtn_clicked();

		// 0�������
		void on_zeroBtn_clicked();

		// С���㺯��
		void on_pointBtn_clicked();


		// �˺���
		void on_multiBtn_clicked();

		// ������
		void on_divBtn_clicked();

		// �Ӻ�
		void on_addBtn_clicked();

		// ����
		void on_subBtn_clicked();

		// ���ں�
		void on_equalBtn_clicked();

		// ȡ�ຯ��
		void on_surplusBtn_clicked();
		
};

#endif // WINCALCULATOR_H
