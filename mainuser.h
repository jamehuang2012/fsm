#ifndef MAINUSER_H
#define MAINUSER_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "smfsm.h"
#include "inputreader.h"
class MainUser : public QWidget
{
    Q_OBJECT
public:
    explicit MainUser(QWidget *parent = 0);
    
signals:
    void machineStopped();
    
public slots:
    void chargerProcess();

private slots:
    void start();
    void pause();


private:
        void createState();
        void createConnection();
        void createTransaction();

        QLabel *titleLabel;
        QHBoxLayout *hTitleLayout;
        QHBoxLayout *hButtonLayout;

        QVBoxLayout *vMainLayout;
        QVBoxLayout *vLeftLayout;
        QVBoxLayout *vRightLayout;

        QPushButton *chargerButton;
        QPushButton *langButton;
        QPushButton *balanceButton;
        QPushButton *recButton;
        QPushButton *binderButton;

        QFont *labelFont;

        SMFsm *m_smFsm;
        ChargerFsm *m_chargeFsm;

        InputReader *inputDialog;



    
};

#endif // MAINUSER_H
