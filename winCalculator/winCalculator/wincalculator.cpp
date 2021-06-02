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

	// �����һ��Ԫ��Ϊ������ʱ��Ҫ�ų��׸�Ԫ����0�����
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
	QStack<double> numberStack;			// ��¼��ֵ��ջ
	QStack<QChar> charStack;			// ��¼�������ջ
	QString originStr = str;
	
	QString tmpStr;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%')
		{
			// ��tmpStr��Ӧ���ַ���ת��Ϊ��������,����������ջ
			// ���ж��Ƿ�Ϊ������
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
			
			// �����ǰ������������ȼ����ڷ���ջ�����������㼶����ǰ��������ջ
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
			// �����һ����ֵ����ջ
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



	//�������ջ��ֻ��һ�������������
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


// ��ȡ������
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
		ui.showResult->setText("��������Ϊ0");
	}
}

