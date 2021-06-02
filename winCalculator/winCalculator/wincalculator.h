#ifndef WINCALCULATOR_H
#define WINCALCULATOR_H
#pragma execution_character_set("utf-8") //支持汉字显示，主要解决图形界面中文显示乱码的问题
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

	bool  isEqual;  // 标记是否按下等于号，默认没有按下等于号

	private slots:

		// 清除内容
		void on_clearBtn_clicked();

		// 删除一个字符
		void on_delBtn_clicked();


		// 1点击函数
		void on_oneBtn_clicked();

		// 2点击函数
		void on_twoBtn_clicked();

		// 3点击函数
		void on_threeBtn_clicked();

		// 4点击函数
		void on_fourBtn_clicked();

		// 5点击函数
		void on_fiveBtn_clicked();

		// 6点击函数
		void on_sixBtn_clicked();

		// 7点击函数
		void on_sevenBtn_clicked();

		// 8点击函数
		void on_eightBtn_clicked();

		// 9点击函数
		void on_nineBtn_clicked();

		// 0点击函数
		void on_zeroBtn_clicked();

		// 小数点函数
		void on_pointBtn_clicked();


		// 乘函数
		void on_multiBtn_clicked();

		// 除函数
		void on_divBtn_clicked();

		// 加号
		void on_addBtn_clicked();

		// 减号
		void on_subBtn_clicked();

		// 等于号
		void on_equalBtn_clicked();

		// 取余函数
		void on_surplusBtn_clicked();
		
};

#endif // WINCALCULATOR_H
