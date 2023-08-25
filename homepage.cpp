#include "homepage.h"
#include "ui_homepage.h"
#include "listtemplate.h"
#include<QTextEdit>
#include<QDebug>
HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QVBoxLayout* layout = new QVBoxLayout(ui->scrollAreaWidgetContents); // 创建垂直布局
       layout->setSpacing(10); // 设置布局的间距

      connect(ui->pushButton_5, &QPushButton::clicked, this, &HomePage::addCustomWidget); // 点击 "Update" 按钮时添加自定义界面

      setWindowTitle("用户信息表");

          UserNameLabel=new QLabel("用户名");

          UserNameLineEdit=new QLineEdit;

          NameLabel=new QLabel("姓名");

          NameLineEdit=new QLineEdit;

          SexLabel=new QLabel("性别");

          SexComBox=new QComboBox;

          SexComBox->addItem("男");

          SexComBox->addItem("女");

          DepartmentEdit=new QLineEdit;

          DepartmentLabel=new QLabel("部门选择");

          AgeLabel=new QLabel("年龄");

          AgeEdit=new QLineEdit;

          OtherLabel=new QLabel("备注");

          OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

          LeftLayout=new QGridLayout();

          //开始加入控件

          LeftLayout->addWidget(UserNameLabel,0,0);

          LeftLayout->addWidget(UserNameLineEdit,0,1);

          LeftLayout->addWidget(NameLabel,1,0);

          LeftLayout->addWidget(NameLineEdit,1,1);

          LeftLayout->addWidget(SexLabel,2,0);

          LeftLayout->addWidget(SexComBox,2,1);

          LeftLayout->addWidget(DepartmentLabel,3,0);

          LeftLayout->addWidget(DepartmentEdit,3,1);

          LeftLayout->addWidget(AgeLabel,4,0);

          LeftLayout->addWidget(AgeEdit,4,1);

          LeftLayout->setColumnStretch(0,1);

          LeftLayout->setColumnStretch(1,3);

          //接下来是右侧的部分

          HeadLabel=new QLabel("头像");

          HeadIconLabel =new QLabel;

          QPixmap icon("touxiang.png");

          HeadIconLabel->setPixmap(icon);

          HeadIconLabel->resize(icon.width(),icon.height());

          UpdateHeadButn=new QPushButton("更新");

          TopRightLayout=new QHBoxLayout();

          TopRightLayout->setSpacing(5);

          TopRightLayout->addWidget(HeadLabel);

          TopRightLayout->addWidget(HeadIconLabel);

          TopRightLayout->addWidget(UpdateHeadButn);

          IntroductionLabel=new QLabel("个人说明");

          IntroductionText=new QTextEdit;

          //右侧的布局

          RightLayout=new QVBoxLayout();

          RightLayout->setMargin(10);

          RightLayout->addLayout(TopRightLayout);

          RightLayout->addWidget(IntroductionLabel);

          RightLayout->addWidget(IntroductionText);

          //接下来是底部的布局

          OKBtn=new QPushButton("确定");

          CancelBtn=new QPushButton("取消");

          BtnLayout=new QHBoxLayout();

          BtnLayout->addStretch();//增加一个占位符，使得按钮都显示在右侧

          BtnLayout->addWidget(OKBtn);

          BtnLayout->addWidget(CancelBtn);

          QGridLayout *mainLayout=new QGridLayout(ui->My);

          mainLayout->setMargin(15);

          mainLayout->setSpacing(10);

          mainLayout->addLayout(LeftLayout,0,0);

          mainLayout->addLayout(RightLayout,0,1);

          mainLayout->addLayout(BtnLayout,1,0,1,2);

          mainLayout->setSizeConstraint(QLayout::SetFixedSize);//增加一个约束，控件都按照sizeHint()来显示

}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::addCustomWidget()
{
    QTextEdit* customWidget = new QTextEdit(ui->scrollAreaWidgetContents); // 创建自定义界面部件
    customWidget->setText("Title");

    customWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // 设置大小策略
    ui->scrollAreaWidgetContents->layout()->addWidget(customWidget); // 将自定义界面部件添加到垂直布局中

    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
}
