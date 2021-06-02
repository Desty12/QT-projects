```C++
// 处理中文乱码显示的问题2（推荐使用）
#include<QTextCodec>
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));		// 放入main.cpp中
    
#pragma execution_character_set("utf-8") // 在实现文件需要显示的文件中需要引入中文的地方加入
```

# GUI应用程序设计基础

在qt create中创建了一个新项目之后一般会生产.pro文件、.ui文件、新建类的头文件和实现文件、main.cpp文件。

其中.pro是项目管理文件，其内容一般如下：

## 实例1：创建新窗体应用程序

```C++ Qt
QT       += core gui		# 将GUI设计的类库模块core gui加入项目中、如果需要用到sql数据库，则直接QT	+= sql就行
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets			#这个条件执行语句表示当Qt主版本大于4时，加入widgets模块
TARGET = samp2			# 表示生产目标可执行文件的名称为samp2.exe
TEMPLATE = app			# 表示项目使用的模板是一般应用程序app
DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += \
        main.cpp \			# 创建的main.cpp文件
        mainwindow.cpp		# 创建的qwdlgmanual类实现文件

HEADERS += \
        mainwindow.h		# 创建的类头文件
```

类mainwindow的头文件mainwindow.h：

```
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
namespace Ui {
	class MainWindow;		// 用于类的声明，因为之后的内需要用到这个类对象
}
class MainWindow : public QMainWindow
{
    Q_OBJECT			// 与信号和槽有关的宏定义
public:
    explicit MainWindow(QWidget *parent = 0);	//构造函数，Ui中的类MainWindow对象将在构造函数中实现初始化
    //构造函数前面添加关键字explicit，表示创建该类的对象以后不能发生对象的隐式转换
    ~MainWindow();
private:
    Ui::MainWindow *ui;		# 定义上述命名空间Ui中的类MainWindow对象指针ui,主要用于实现ui
};
#endif // MAINWINDOW_H
```

类mainwindow的实现文件mainwindow.cpp：

```
#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);		# 用于实现ui界面中相关组件的初始化工作
}

MainWindow::~MainWindow()
{
    delete ui;				# 释放UI类中使用new开辟的内存空间
}
```

mainwindow.ui主要是与界面相关的主键以XML形式存放：

```
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>400</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralWidget"/>
  <widget class="QMenuBar" name="menuBar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>400</width>
     <height>23</height>
    </rect>
   </property>
  </widget>
  <widget class="QToolBar" name="mainToolBar">
   <attribute name="toolBarArea">
    <enum>TopToolBarArea</enum>
   </attribute>
   <attribute name="toolBarBreak">
    <bool>false</bool>
   </attribute>
  </widget>
  <widget class="QStatusBar" name="statusBar"/>
 </widget>
 <layoutdefault spacing="6" margin="11"/>
 <resources/>
 <connections/>
</ui>
```

编译后生成的ui_mainwindow.h:（该文件一般在项目中被隐藏，需手动加载到项目中）

```
#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
QT_BEGIN_NAMESPACE
class Ui_MainWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        retranslateUi(MainWindow);
        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi
};
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_MAINWINDOW_H
```

ui_mainwindow.h文件中主要是界面中与主键相关的变量定义、窗体布局设置，该文件实在mainwindow.ui经过编译后生成的，一般修改该文件中的内容对界面内容没影响，只有手动修改mainwindow.ui界面中的相关内容才能实现组件的修改设置。

main.cpp文件内容如下：

```
#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);			# 定义应用程序对象
    MainWindow w;					   # 定义类MainWindow对象
    w.show();						   # 显示与类相关的主键 
    return a.exec();				   # 执行应用程序
}
```

信号与槽函数：

- 一个信号可以连接多个槽、同一个槽可以关联多个信号、一个信号可以连接另外一个信号

![1618835053733](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618835053733.png)

![1618835093905](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618835093905.png)

![1618835120112](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618835120112.png)

- 在使用信号与槽的类中需要加入Q_OBJECT宏定义
- 一般信号和槽中的变量个数需要一致，否则会出现错误
- 当一个信号被发射之后与之相关的槽函数会被立即执行

目前信号与槽函数有四种关联方式：

1、直接选中组件按钮，然后右键选择转到槽（go to slot）

![1618916791513](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618916791513.png)

2、在菜单栏中找到编辑，找到Edit Signals/SLots

![1618916979910](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618916979910.png)

![1618917015618](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618917015618.png)

3、使用代码自定义按钮组件，并实现相关槽函数，最后使用connect()函数实现信号与槽的关联

![1618917077823](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618917077823.png)

4、不写connect()关联函数，直接使用代码进行组件定义与槽函数实现，进行信号与槽函数的关联（**推荐这种方式**）

![1618917147758](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618917147758.png)

<!--在UI窗体设计时，创建对应的窗体objectName对应的ui_mainwindow.h中的ui相关的类名，窗体中属性objectName会在ui_mainwindow.h中生成相应变量-->

## UI界面的设置可以采用纯UI界面设置，但是该方法对有些组件不能设置

比如：工具栏上无法添加comboBox组件，这时就可以通过纯代码方式设置

纯代码方式虽然可以设置生成任何组件，但是该方法效率不高，过程繁琐

<u>因此可以采用UI+代码生成的混合设计方法进行设计。</u>

### 实例2 纯代码设计对话框应用程序

下面是纯代码设计如下内容：

![1618835432111](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618835432111.png)这是窗体界面

纯代码创建方式如下：主要需要两部分组成：定义窗体组件变量和函数相关的.h文件、对应的实现文件.cpp

其中qwdlgmanual.h内容如下：

```
#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H
#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
class QWDlgManual : public QDialog
{
    Q_OBJECT
private:
    QCheckBox       *chkBoxUnder;
    QCheckBox       *chkBoxItalic;
    QCheckBox       *chkBoxBold;
    QRadioButton    *rBtnBlack;
    QRadioButton    *rBtnRed;
    QRadioButton    *rBtnBlue;
    QPlainTextEdit  *txtEdit;
    QPushButton     *btnOk;
    QPushButton     *btnCancel;
    QPushButton     *btnClose;
    void    initUI();   // UI创建与初始化
    void    initSignalSlots();  // 初始化信号与槽的链接
private slots:
    void    on_chkBoxUnder(bool checked);   //underline的槽函数
    void    on_chkBoxItalic(bool checked);  //Italic的槽函数
    void    on_chkBoxBold(bool checked);    //Bold的槽函数
    void    setTextFontColor();             //设置字体颜色
public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();
};
#endif // QWDLGMANUAL_H
```

实现文件如下qwdlgmanual.cpp如下：

```
#pragma execution_character_set("utf-8") //支持汉字显示
#include "qwdlgmanual.h"
#include <QboxLayout.h>
QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    initUI();   //界面创建与布局
    initSignalSlots();  //信号与槽的关联
    setWindowTitle("Form created mannually");
}

QWDlgManual::~QWDlgManual()
{
}

void    QWDlgManual::on_chkBoxUnder(bool checked)
 {
     QFont font=txtEdit->font();
     font.setUnderline(checked);
     txtEdit->setFont(font);
 }
 void    QWDlgManual::on_chkBoxItalic(bool checked)
 {
     QFont font=txtEdit->font();
     font.setItalic(checked);
     txtEdit->setFont(font);
 }
 void    QWDlgManual::on_chkBoxBold(bool checked)
 {
     QFont font=txtEdit->font();
     font.setBold(checked);
     txtEdit->setFont(font);
 }
 void    QWDlgManual::setTextFontColor()
 {
        QPalette plet=txtEdit->palette();
         if(rBtnBlack->isChecked())
             plet.setColor(QPalette::Text,Qt::black);
         else if(rBtnRed->isChecked())
             plet.setColor(QPalette::Text,Qt::red);
         else if(rBtnBlue->isChecked())
             plet.setColor(QPalette::Text,Qt::blue);
         else
           plet.setColor(QPalette::Text,Qt::black);
        txtEdit->setPalette(plet);
 }

void QWDlgManual::initUI()
{
    //创建Underline、Italic、Bold 3个checkBox,并水平布局
    chkBoxUnder=new QCheckBox(tr("Underline"));
    chkBoxItalic=new QCheckBox(tr("Italic"));
    chkBoxBold=new QCheckBox(tr("Bold"));
    QHBoxLayout *HLay1=new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);
    // 创建Black、Red、Blue 3个RadioButton，并水平布局
    rBtnBlack =new QRadioButton(tr("Black"));
    rBtnBlue =new QRadioButton(tr("Blue"));
    rBtnRed =new QRadioButton(tr("Red"));
    QHBoxLayout *HLay2=new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlue);
    // 创建确定、取消、退出 3个PushButton,并水平布局
    btnOk = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));
    QHBoxLayout * HLay3 = new QHBoxLayout;
    HLay3->addWidget(btnOk);
    HLay3->addWidget(btnCancel);
    HLay3->addWidget(btnClose);
     //创建文本框，并设置初始字体
     txtEdit = new QPlainTextEdit;
     txtEdit->setPlainText("Hello World,It is my Demo");
     QFont font=txtEdit->font();    //  获取字体
     font.setPointSize(20);         //  修改字体
     txtEdit->setFont(font);        //  设置字体
     // 创建垂直布局，并设置为主布局
     QVBoxLayout *VLay=new QVBoxLayout;
     VLay->addLayout(HLay1);    //添加字体类形组
     VLay->addLayout(HLay2);    //添加字体颜色组
     VLay->addWidget(txtEdit);  //添加PlainTextEdit
     VLay->addLayout(HLay3);    //添加按键组
     setLayout(VLay);
}

void    QWDlgManual::initSignalSlots()
{
    //三个颜色QRadioButton的clicked()信号与setTextFontColor槽函数关联
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    //三个字体设置的CheckBox的click(bool)信号与相应槽函数关联
   connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxBold(bool)));
   connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic(bool)));
   connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder(bool)));
   //三个pushBotton的信号与槽函数关联
    connect(btnOk,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
}
```

其中主要是两个函数的实现：

一个 void    initUI();   // UI创建与初始化

一个 void    initSignalSlots();  // 初始化信号与槽的链接

### 实例3 借助界面UI与代码混合设计方法设计菜单栏、工具栏、状态栏

新建窗体类QWMainWind，该类继承自QMainWindow，具有菜单栏、工具栏和状态栏

​		点击qwmainwind.ui，在UI设计器打开此窗口，有Type Here的地方就是菜单栏，菜单栏下方就是工具栏，窗口最下方是状态栏。

​		在菜单栏显示Type Here的地方双击，出现一个编辑框，在编辑框输入需要显示的菜单项的名称然后回车，如输入“文件”并回车，这样就创建了一个文件菜单分组，按照同样的方法可以创建“编辑”、“格式”分组。

​		创建主菜单分组之后，从Action编辑器的列表里将一个Action拖放到菜单栏某个分组下面就创建好了一个菜单项，其他菜单项组件类似设置。新建一个Action的的图片如图所示：

![1618882446982](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618882446982.png)

![1618882484549](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618882484549.png)

这样就创建好了一个“打开”菜单项，其他菜单项的创建方法相同。

在菜单项设计后之后，由于部分ui组件不能直接在界面上进行设计（如在ui设计器方式下就无法将ComboBox放置到菜单栏中），因此还需要通过代码方式将该组件放入到菜单栏中。下面是用代码方式在菜单栏中创建设置字体大小的QSpinBox和设置字体类型的QFontComboBox，以及状态栏的QLabel创建：

现在qwmainwind.h中定义相关组件与方法，然后在qwmainwind.cpp进行实现

```
void QWMainWind::iniUI()
{
    fLabCurFile=new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusBar->addWidget(fLabCurFile);  //添加到状态栏
    progressBar1=new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusBar->addWidget(progressBar1);  //添加到状态栏
    //工具栏上添加组件
    spinFontSize=new QSpinBox;  //文字大小
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    ui->mainToolBar->addWidget(new QLabel("字体大小"));
    ui->mainToolBar->addWidget(spinFontSize);   //spinBox添加到工具栏
    ui->mainToolBar->addSeparator();    //分隔条
    ui->mainToolBar->addWidget(new QLabel("字体"));
    comboFont=new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->mainToolBar->addWidget(comboFont);  //添加到工具栏
    setCentralWidget(ui->txtEdit);
}
```

直接将这个iniUI()放到QWMainWind类的构造函数中就可以完成上述新建组件的初始化工作，最后创建结果显示如下：

![1618883030369](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618883030369.png)

上述界面设计完成之后就需要为相应的action添加功能。Action是一种不可见的界面元素，主要用于创建菜单项、工具栏按钮设计。Action的主要信号为trigger()，下面是其信号与槽函数的链接方式如下：

![1618883413416](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618883413416.png)

由于QTextEdit类本身就有相应的剪切、复制、黏贴和清除功能，因此只需要直接添加相应的槽函数就可。

其他action比如：字体粗细、下划线和斜体的相关代码设计如下：

```
void QWMainWind::on_actFontBold_triggered(bool checked)
{
   QTextCharFormat fmt;
   fmt=ui->txtEdit->currentCharFormat();
   if(checked)
       fmt.setFontWeight(QFont::Bold);
   else
       fmt.setFontWeight(QFont::Normal);
   ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontItalic(true);         // setFontItalic()设置字体为斜体
    else
        fmt.setFontItalic(false);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_actFontUnder_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontUnderline(true);   // setFontUnderline()设置字体下划线
    else
        fmt.setFontUnderline(false);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
```

通过上述函数，当用户勾选了加粗、斜体或者下划线后，菜单栏上面就会显示√

![1618885745999](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618885745999.png)

但此时，文本框QTextEdit中的内容还不能改变，因为此时只是对菜单栏进行了信号与槽函数的关联，并没有将菜单栏与QTextEdit进行关联，所以还需要通过菜单栏中的菜单项中的相关选项与QTextEdit中的粗体、斜体和下划线进行属性关联。在ui设计器中选择QTextEdit然后创建copyAvailable(bool)和selectChanged()信号，并添加相关代码：

![1618886012234](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618886012234.png)

```
void QWMainWind::on_txtEdit_copyAvailable(bool b)
{
    //更新cut、copy、pasted的enabled属性
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void QWMainWind::on_txtEdit_selectionChanged()
{	//设置QTextEdit中与Italic、Bold、Underline属性相关的checked属性
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();   //获取文本格式
    ui->actFontItalic->setChecked(fmt.fontItalic());    //设置是否为斜体
    ui->actFontBold->setChecked(fmt.font().bold());       //设置是否为粗体
    ui->actFontUnder->setChecked(fmt.fontUnderline());  //设置是否为下划线
}
```

​		到此，关于复制、黏贴、剪切、字体加粗、是否设置斜体、是否设置下划线的菜单项功能基本完成。

![1618886247772](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618886247772.png)

​		最后是手工创建的两个组件QSpinBox和QFontboBox，这两个手工创建的组件需要使用代码定义相关的槽函数来实现信号与槽的关联。对于SpinBox组件最适合使用valueChanged(int)，用于字体设置的FontComboBox组件适合使用currectIndexChanged(QString)信号。

下面是这两个槽函数的定义与使用：

```
    void            iniSignalSlots();   //关联信号与槽
```

```
    //自定义槽函数
    void on_spinBoxFontSize_valueChanged(int aFontSize);    //改变字体大小
    void on_comboFont_currentIndexChanged(const QString &arg1);//选择字体
```

下面是实现

```
void QWMainWind::iniSignalSlots()
{
    //信号与槽的关联
connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentTextChanged(const QString &)),this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
}
void QWMainWind::on_spinBoxFontSize_valueChanged(int aFontSize)
{//改变字体大小的SpinBox
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}
 void QWMainWind::on_comboFont_currentIndexChanged(const QString &arg1)
{//FontComboBox的相应、选择字体名称
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);    //设置字体名称
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
```

最后在构造函数中调用iniSignalSlots()函数就可以实现字体大小选择与字体设置的菜单栏功能。

最后如果创建的主菜单不适应默认图标，可以自己添加图标，操作如下：

1、先将图标文件(.ico)复制到源程序目录下

2、在项目配置文件里用RC_ICONS设置图标文件名，添加下面一行代码

RC_ICONS = AppIcon.ico

到此这个例子的全部功能已经实现。

![1618889336345](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618889336345.png)

C/C++中加入函数为：

```c++
int GetNestPlateNums(int *nestPlateNums)
{
	if (!gNestData || gIsStartNest) return -1;
	for (int i = 0; i < gNestData->mUsedPlateNums.count(); i++)
	{
		nestPlateNums[i] = gNestData->mUsedPlateNums[i];	
		// 本质还是取gNestData->mUsedPlateNums首地址的值进行赋值
	}
	return 0;
}
```

## QT类库概述与容器类

![1618919119978](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618919119978.png)

QT中的数据类型定义：

![1618919935198](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618919935198.png)

### 3 容器类

QT中常见的容器类：

1、顺序容器类：QList、QLinkedList、QVector、QStack和QQueue

QList是最常见的容器类，以数值列表(array-list)的形式实现，一般在QList的前面或者后面添加数据非常快，QList以下标索引方式进行访问。QList用于添加、插入、替换、移动、删除数据项的函数有：append()与prepend()、insert()、replace()、move()、swap()、removeFirst()和removeLast();另外QList还提供了下标索引访问方式的at()函数

QLinkList<T>是链式列表(linked-list)，数据项不适连续的内存存储，它基于迭代器访问数据项，并且插入和删除数据项的操作时间相同（注：由于是链表，所以不提供[]和at()的索引形式访问数据项）

QVector<T>提供动态数组的功能，以下标索引访问数据。QVector的函数接口与QList几乎完全相同，**QVector<T>的性能比QList<T>更高**，因为QVector<T>的数据项是连续存储的。另外QPolygon、QPolygonF是继承自QVector类

QStack<T>是提供类似于堆栈的后入先出操作容器类，void push(T)和T pop(void)是主要的接口函数.，另外一般以T top(void)函数返回栈顶元素。

QQueue<T>是提供类似于队列先入先出操作的容器类。enqueue()和dequeue()是主要的操作函数，例如

```
    //QQueue
    qDebug()<<"遍历队列";
    QQueue<int> que;
    for(int i=0;i<20;i++)
    {
        int temp = rand()%100;
        //que.enqueue(temp);    //进队
        //que.append(temp);     //在队后插入元素，出队元素与入队顺序相同
        que.prepend(temp);      //在队前插入元素，出队元素与入队元素相反
    }
    while(!que.isEmpty())
    {
        qDebug()<<que.dequeue();
    }
```

2、关联容器类：QMap、QMultiMap、QHash、QMultiHash和QSet

QMultiMap和QMultiHash支持一个键关联多个值，QHash和QMultiHash类使用散列函数进行查找，查找速度更快。

（1）QSet是基于散列表的集合模板类，它存储数据的顺序是不定的，查找值的速度非常快。QSet<T>内部就是使用QHash实现的

```
    QSet<int>   arr1;
    for(int i=0;i<20;i++)
    {
        int temp = rand()%100;
        arr1.insert(temp);		//插入元素	
    }
    QSet<int>::iterator iter=arr1.begin();	//使用迭代器遍历元素
    for(;iter!=arr1.end();++iter)
    {
        qDebug()<<*iter;	
    }
```

（2）QMap存储数据按照键的顺序，QMap<Key,T>提供一个字典，一个键映射到一个值，如果不在乎存储顺序，使用QHash会更快

例如：QMap<QString,int>类型变量和赋值实例代码如下：

```
 qDebug()<<"QMap的使用";
    QMap<QString,int>   map;
    for(int i=0;i<20;i++)
    {
        QString temp = QString::number(i);	// QString::number()将int转换为字符串
        int tmp=rand()%100;
        map.insert(temp,tmp);
    }
    qDebug()<<map.size();
    QMap<QString,int>::const_iterator iter_map=map.begin();
    for(;iter_map!=map.end();++iter_map)
    {
        qDebug()<<iter_map.key();
        qDebug()<<iter_map.value();
    }	
```

也可以使用insert()函数赋值，再使用remove()移除一个键值对

其中QString中相关的类型转换函数有toInt()、toDouble()、toFloat()、toLong()、toLongLong()等

例如使用toInt()函数实例：

```
QString str = "125";
    bool ok;
    int hex = str.toInt(&ok,16);    // bool类型的ok为true时表示转换成功，为false时表示转换失败，16表示转化基数为16进制
    qDebug()<<hex;      // 输出293
    bool ok1;
    int dec = str.toInt(&ok1,10);
    qDebug()<<dec;      // 输出125
```

<!--上述toInt()函数中的第二个参数当为0时，会以c语言方式转换，当为0x或者16时会以16进制形式转化、当为8时会以8进制转化；其他情况下一律以10为基数转化-->

(3)QMultiMap是QMap的子类，是用于处理多值映射的便利类，允许一个键对应多个值

![1618923741102](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618923741102.png)

(4)QHash是基于散列表来实现字典功能的模板类，QHash<Key,T>存储的键值对具有非常快的查找速度

QHash与QMap的功能和用法相似，区别在于一下几点：

a、QHash比QMap的查找速度快

b、在QMap上遍历时，数据项是按照键排序的，而QHash的数据项是任意顺序的

c、QMap的键必须提供“<”运算符，QHash的键必须提供“==”运算符和一个名为qHash()的全局散列函数

(5)QMultiHash是QHash的子类，是用于处理多值映射的便利类，其用法与QMultiMap类似。

一些常见的其他数据类型：QVariant类，QVariant类类似于C++的联合(union)数据类型，它不仅能够保存很多Qt类型的值，包括：QColor、QBrush、QFont、QPen、QRect、QString、QSize等，也可以存放Qt容器类型的值。

​		Qt中常见的迭代器有：Java类型的迭代器和C++ STL类型的迭代器，其中java类型的迭代器使用方便，而STL类型的迭代器效率更高。另外Qt还提供了一个关键字foreach（实际是QtGlobal里定义的一个宏）

![1618977062452](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618977062452.png)

![1618977081668](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618977081668.png)

​		![1618977170183](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618977170183.png   )

Qt中的常见算法与正则表达式：







Qt中常见正则表达式符号：

 ![img](https://images2018.cnblogs.com/blog/1035773/201808/1035773-20180827102540808-1085064056.png) 

 注意：C++编译器会对反斜杠进行转换，要想在正则表达式中包括一个\，需要输入两次，例如\\s。要想匹配反斜杠本身，需要输入4次，比如\\\\。 

```
   QRegExp rx("[1-9]\\d{0,3}");
    QRegExpValidator v(rx,0);
    QString s;
    int pos = 0;
    qDebug()<<"例子1";
    s = "0";qDebug()<<v.validate(s,pos);     // output 0,invalid
    s = "12345";qDebug()<<v.validate(s,pos); // output 0
    s = "1";qDebug()<<v.validate(s,pos);     // output 2,acceptable
    qDebug()<<"例子2";
    rx.setPattern("\\S+");  // 匹配非空字符一个或多个
    v.setRegExp(rx);
    s = "myFile.txt"; qDebug()<<v.validate(s,pos);   // output 2,acceptable
    s = "My File.txt"; qDebug()<<v.validate(s,pos);  // output 0,invalid
    qDebug()<<"例子3";
    rx.setPattern("[A-C]\\d{5}[W-Z]");
    v.setRegExp(rx);
    s = "a12345Z"; qDebug()<<v.validate(s,pos);     // output 0,invalid
    s = "B12345X"; qDebug()<<v.validate(s,pos);     // output 2,acceptable
    s = "B12";  qDebug()<<v.validate(s,pos);        // output 1,intermediate
     qDebug()<<"例子4";
    rx.setPattern("read\\S?me(\.(txt|asc|1st))?");
    rx.setCaseSensitivity(Qt::CaseInsensitive);       // 对大小字符识别写不敏感
    v.setRegExp(rx);
    s = "readme";      qDebug()<<v.validate(s, pos); // Returns Acceptable
    s = "README.1ST";  qDebug()<<v.validate(s, pos); // Returns Acceptable
    s = "read me.txt"; qDebug()<<v.validate(s, pos); // Returns Invalid
    s = "readm";       qDebug()<<v.validate(s, pos); // Returns Intermediate
```

QT中的基本模块

![1618924174759](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618924174759.png)

## 第四章 常用界面设计组件

### 4.1 字符串与输入输出

界面设计中使用得最多的就是显示字符串的QLable和用于字符串显示和读取的QLineEdit，这两个类都有如下两个函数用于字符串读取和设置

![1618988833528](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618988833528.png)

可以将数字转换为字符串的四种方法：

![1618991035920](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618991035920.png)

将一个整数转换为不同进制的字符串，可以使用QString的函数setNum()或静态函数number(),他们的函数原型是：

![1618994679518](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618994679518.png)

目前QString类中常见的函数有append()和prepend()，toUpper和toLower()，count()、size()和length()，trimmed()和simplified()，indexOf()和lastIndexOf()，isNull()和isEmpty()，contains()，endsWith()和startsWith()，left()和right()，section()

(1)toUpper和toLower()中toUpper()函数将字符串转换为大写字母，toLower()将字符串转换为小写字母

（2）count()、size()和length()都是返回字符串个数，且这三个函数返回值相同，如果字符串中有汉字，一个汉字算一个字符。

（3）trimmed()和simplifed()，其中trimmed()去掉字符串首尾空格，simplified()不仅去掉首尾的空格，中间连续的空格也会用一个空格替换。

（4）indexOf()函数为查找参数字符串str出现的位置，lastIndexOf()则是查找某个字符串最后出现的位置。

（5）isNull()和isEmpty()都是判断字符串是否为空，但稍有区别。如果一个一个空字符串只有"\0"，则isNull()函数返回false，而isEmpty()函数返回true；只有未赋值的字符串，isNull()才返回true；

![1618997059778](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618997059778.png)

（6）contains()判断字符串是否包含某个字符串，可指定是否区分大小写

![1618997150532](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618997150532.png)

（7）endsWith()和startsWith()，startsWith()判断是否以某个字符串开头，而endsWith()判断是否以某个字符串结束

![1618997240490](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618997240490.png)

（8）left()和right()

![1618997278237](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618997278237.png)

(9)  section()

![1618997314034](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1618997314034.png)

**QGridLayout使用经验总结：**

![1619004168435](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1619004168435.png)

如上图所示：在创建第二个QGridLayout时，先从UI工具栏中选择QLabel标签，分别放到十进制、二进制和十六进制三个位置，然后再选择三个LineEdit分别放在十进制、二进制和十六进制这三个QLabel的右侧，最后在这三个LineEdit的右侧放置三个PushButton按钮完成界面一个GridLayout布局设置。当前还可以使用代码的方式直接布局

![1619004444108](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1619004444108.png)

### 4.2 SpinBox的使用

QSpinBox用于整数的显示和输入，一般显示十进制，也可以显示二进制、十六进制的数，而且可以在显示框中增加前缀或后缀。

QDoubleSpinBox用于浮点数的显示和输入，可以设置显示小数位数，也可以设置显示的前缀和后缀

![1619004943280](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1619004943280.png)

先创建对应UI

![1619006155478](C:\Users\12323\AppData\Roaming\Typora\typora-user-images\1619006155478.png)

然后为计算按钮添加计算功能：

```
void CalWidget::on_btnCalculate_clicked()
{
   int num = ui->sbNum->value();		// 获取spinBox对应的值，使用Value()函数
   double price = ui->sbPrice->value();
    double total = num*price;
    ui->sbTotalPrices->setValue(total);
}
```

### 4.3 时间日期与定时器





### 5 多窗口设计





## 7 文件读写









## 8 绘图











## 9 Qt charts









## 10 数据可视化













## 11 数据库















## 12 自定义插件和库











## 13 多线程











## 14 网络编程













## 15 多媒体











