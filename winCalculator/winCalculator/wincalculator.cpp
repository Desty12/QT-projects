#include "wincalculator.h"
#include<QStack>


winCalculator::winCalculator(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

winCalculator::~winCalculator()
{
	isEqual = false;
}

void winCalculator::on_clearBtn_clicked()
{
	ui.showLab->setText("0");
}

void winCalculator::on_delBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}

	if(str.size() == 1)
	{
		ui.showLab->setText("0");
		return;
	}

	QString str1;
	for(int i=0; i<(str.size()-1); i++)
	{
		str1.append(str[i]);
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_oneBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('1');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('1');
		str1 = str;
	}else
	{
		str1 = str + "1";
	}

	ui.showLab->setText(str1);
}

void winCalculator::on_twoBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('2');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('2');
		str1 = str;
	}else
	{
		str1 = str + "2";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_threeBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('3');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('3');
		str1 = str;
	}else
	{
		str1 = str + "3";
	}

	ui.showLab->setText(str1);
}

void winCalculator::on_fourBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('4');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('4');
		str1 = str;
	}else
	{
		str1 = str + "4";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_fiveBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('5');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('5');
		str1 = str;
	}else
	{
		str1 = str + "5";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_sixBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('6');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('6');
		str1 = str;
	}else
	{
		str1 = str + "6";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_sevenBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('7');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('7');
		str1 = str;
	}else
	{
		str1 = str + "7";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_eightBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('8');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('8');
		str1 = str;
	}else
	{
		str1 = str + "8";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_nineBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('9');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	QString str1;
	if(str[0] == '0')
	{
		str[0] = QChar('9');
		str1 = str;
	}else
	{
		str1 = str + "9";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_zeroBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}

	if(str.size() >= maxCharNum) return;

	// 当最后一个元素为操作符时需要排除首个元素是0的情况
	//if((str.size() == 1 && str[0] == '0') || str[str.size()-1]=='+' || str[str.size()-1]=='-' ||
	//	str[str.size()-1]=='*' || str[str.size()-1]=='/' || str[str.size()-1]=='%')
	//	return;
	
	if(str.size() == 1 && str[0] == '0') return;

	QString str1;
	if(str[0] != '0')
	{
		str1 = str + "0";
	}
	ui.showLab->setText(str1);
}

void winCalculator::on_pointBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}

	if(str.size() >= maxCharNum) return;

	QString::iterator it=str.begin();
	for(;it!= str.end();++it)
	{
		if(*it == '.') return;
	}

	QString str1;
	if(str[0] != '0')
	{
		str1 = str + ".";
	}

	ui.showLab->setText(str1);
}

void winCalculator::on_multiBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}

	if(str.size() >= maxCharNum) return;

	if(str.size() > 1)
	{
		str = str + "*";
	}
	ui.showLab->setText(str);
}

void winCalculator::on_divBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}

	if(str.size() >= maxCharNum) return;

	if(str.size() > 1)
	{
		str = str + "/";
	}
	ui.showLab->setText(str);
}

void winCalculator::on_addBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}

	if(str.size() >= maxCharNum) return;

	if(str.size() > 1)
	{
		str = str + "+";
	}
	ui.showLab->setText(str);
}

void winCalculator::on_subBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	if(str.size() > 1)
	{
		str = str + "-";
	}
	ui.showLab->setText(str);
}

void winCalculator::on_surplusBtn_clicked()
{
	QString str = ui.showLab->text();
	if(isEqual)
	{
		str.clear();
		str.append('0');
		isEqual = false;
		ui.showLab->setText(str);
		ui.showResult->setText("");
		return;
	}
	if(str.size() >= maxCharNum) return;

	if(str.size() > 1)
	{
		str = str + "%";
	}
	ui.showLab->setText(str);
}

double getCalResult(QString str,bool &isNormal)
{
	QStack<double> numberStack;			// 记录数值的栈
	QStack<QChar> charStack;			// 记录运算符的栈
	QString originStr = str;
	
	QString tmpStr;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%')
		{
			// 将tmpStr对应的字符串转变为整数类型,并将该数入栈
			// 先判断是否为浮点数
			bool isDouble = tmpStr.contains('.');
			if(isDouble) 
			{
				double tmpValue = tmpStr.toDouble();
			    numberStack.push(tmpValue);
				tmpStr.clear();
			}else
			{
				double tmpValue = double(tmpStr.toInt()); 
				numberStack.push(tmpValue);
				tmpStr.clear();
			}
			
			// 如果当前操作符的运算等级大于符号栈顶操作符运算级别，则当前操作符入栈
			if(charStack.isEmpty())
			{
				QChar c = str.at(i);
				QChar *ss = str.data();
				
				charStack.push(ss[i]);
				
			}
			else
			{
				if(str[i]==QChar('+') || str[i]==QChar('-'))
				{
					while(charStack.size() > 0)
					{
						double reS;
						QChar operatorChar = charStack.top();
						charStack.pop();
						double value1 = numberStack.top();
						numberStack.pop();
						double value2 = numberStack.top();
						numberStack.pop();

						if(operatorChar=='+')
						{
							reS = value1 + value2;
							numberStack.push(reS);
						
						}else if(operatorChar == '-')
						{
							reS = value2 - value1;
							numberStack.push(reS);
						
						}else if(operatorChar =='*')
						{
							reS = value2 * value1;
							numberStack.push(reS);
						}else if(operatorChar =='/')
						{
							if(value1 != 0)
							{
								reS = value2 / value1;
								numberStack.push(reS);
							}else
							{
								isNormal=false;
								return 0;
							}
						}

					}// end while
					
					charStack.push(str[i]);

				}else if(str[i]=='*' || str[i]=='/')
				{
					double reS;
					QChar operatorChar = charStack.top();
					if(operatorChar=='*')
					{
						charStack.pop();
						double value1 = numberStack.top();
						numberStack.pop();
						double value2 = numberStack.top();
						numberStack.pop();
						reS = value1 * value2;
						numberStack.push(reS);
						charStack.push(str[i]);
					}else if(operatorChar == '/')
					{
						charStack.pop();
						double value1 = numberStack.top();
						numberStack.pop();
						double value2 = numberStack.top();
						numberStack.pop();

						if(value1 == 0) 
						{
							isNormal=false;
							return 0;
						}

						reS = value2 / value1;
						numberStack.push(reS);
						charStack.push(str[i]);
					}else if(operatorChar =='+' || operatorChar =='-')
					{
						charStack.push(str[i]);
					}
				}

			}//end if-else

		}else
		{
			tmpStr.append(str[i]);
			// 将最后一个数值存入栈
			if(i == str.size()-1)
			{
				bool isDouble = tmpStr.contains('.');
				if(isDouble) 
				{
					double tmpValue = tmpStr.toDouble();
					numberStack.push(tmpValue);
					tmpStr.clear();
				}else
				{
					double tmpValue = double(tmpStr.toInt()); 
					numberStack.push(tmpValue);
					tmpStr.clear();
				}
			}
		}

	}// end for



	//处理符号栈中只有一个操作符的情况
	while(charStack.size()>0)
	{
		double v1 = numberStack.top();
		numberStack.pop();
		double v2 = numberStack.top();
		numberStack.pop();

		QChar oper = charStack.top();
		charStack.pop();
		double S;
		if(oper == '+')
		{
			S = v1 + v2;
			numberStack.push(S);

		}else if(oper == '-')
		{
			S = v2 - v1;
			numberStack.push(S);
		}else if(oper == '*')
		{
			S = v1 * v2;
			numberStack.push(S);
		}else if(oper == '/')
		{
			if(v1 != 0)
			{
				S = v2/v1;
				numberStack.push(S);
			}else
			{
				isNormal=false;
				return 0;
			}
		}
	}// end while

	return numberStack.top();
}


// 获取计算结果
void winCalculator::on_equalBtn_clicked()
{
	isEqual = true;
	QString str = ui.showLab->text();

	QString resultStr = "=";
	bool isNor = true;
	double result = getCalResult(str,isNor);
	if(isNor)
	{
		resultStr = resultStr + str.sprintf("%.1f",result);

		ui.showResult->setText(resultStr);
	}else
	{
		ui.showResult->setText("除数不能为0");
	}
}

