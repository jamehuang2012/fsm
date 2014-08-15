#include "mainuser.h"
#include "windows.h"
#include <QDebug>
#include "smfsm.h"
#include "inputreader.h"

MainUser::MainUser(QWidget *parent) :
    QWidget(parent)
{
    resize(WIN_SIZE::WIDTH,WIN_SIZE::HEIGHT);


    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    hTitleLayout = new QHBoxLayout();
    vMainLayout = new QVBoxLayout();

    titleLabel = new QLabel("Dragon Ball");
    titleLabel->setFont(QFont("Trebuchet",20,QFont::Bold));
    hTitleLayout->addWidget(titleLabel,1,Qt::AlignHCenter);

    //create buttons
    chargerButton = new QPushButton("Charger");
    chargerButton->setFont(QFont("Trebuchet",20,QFont::Bold));


    langButton = new QPushButton("change Language");
    langButton->setFont(QFont("Trebuchet",20,QFont::Bold));

    binderButton = new QPushButton("Binder");
    binderButton->setFont(QFont("Trebuchet",20,QFont::Bold));

    balanceButton = new QPushButton("Balance");
    balanceButton->setFont(QFont("Trebuchet",20,QFont::Bold));

    recButton = new QPushButton("Record");
    recButton->setFont(QFont("Trebuchet",20,QFont::Bold));

    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(chargerButton->sizePolicy().hasHeightForWidth());

    chargerButton->setSizePolicy(sizePolicy1);
    vLeftLayout = new QVBoxLayout();

    vLeftLayout->setSpacing(15);
    vLeftLayout->setContentsMargins(10,50,20,80);
    vLeftLayout->addWidget(chargerButton);



    sizePolicy1.setHeightForWidth(binderButton->sizePolicy().hasHeightForWidth());
    binderButton->setSizePolicy(sizePolicy1);
    sizePolicy1.setHeightForWidth(balanceButton->sizePolicy().hasHeightForWidth());
    balanceButton->setSizePolicy(sizePolicy1);
    sizePolicy1.setHeightForWidth(recButton->sizePolicy().hasHeightForWidth());
    recButton->setSizePolicy(sizePolicy1);
    sizePolicy1.setHeightForWidth(langButton->sizePolicy().hasHeightForWidth());
    langButton->setSizePolicy(sizePolicy1);



    vRightLayout = new QVBoxLayout();
    vRightLayout->addWidget(binderButton);
    vRightLayout->addWidget(balanceButton);
    vRightLayout->addWidget(recButton);
    vRightLayout->addWidget(langButton);
    vRightLayout->setContentsMargins(0,50,10,80);
    vRightLayout->setSpacing(25);


    hButtonLayout = new QHBoxLayout();

    hButtonLayout->addLayout(vLeftLayout);
    hButtonLayout->addLayout(vRightLayout);

    vMainLayout->addLayout(hTitleLayout);
    vMainLayout->addLayout(hButtonLayout);


    setLayout(vMainLayout);
    //setStyleSheet("background-image: url(:/home/james/work/qt/Dragonball/image/image-bg.jpg)");
    //create button
    qDebug() << WIN_SIZE::backImage;
    QPixmap bkgnd(WIN_SIZE::backImage);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // create state

    createState();
    createConnection();



}


void MainUser::start()
{


}


void MainUser::pause()
{

}
\
void MainUser::createState()
{

    m_smFsm = new SMFsm();
    m_smFsm->initialization();

    State *mainState;
    State *chargerState;
    mainState = m_smFsm->getMainState();

    chargerState = m_smFsm->getChargerState();
    mainState->addTransition(chargerButton,SIGNAL(clicked()),chargerState);
    mainState->assignProperty(chargerButton,"clicked",true);
    chargerState->assignProperty(chargerButton,"enabled",true);


    m_chargeFsm = new ChargerFsm();
    m_chargeFsm->initialization();

    m_smFsm->run();



}

void MainUser::createTransaction()
{


}


void MainUser::createConnection()
{
  connect(chargerButton,SIGNAL(clicked()),this,SLOT(chargerProcess()));
}


void MainUser::chargerProcess()
{
    inputDialog = new InputReader();
    inputDialog->show();
    qDebug() << "chargeProcess";
}
