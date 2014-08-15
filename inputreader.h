#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <QWidget>
#include "button.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>



class InputReader : public QWidget
{
    Q_OBJECT
public:
    explicit InputReader(QWidget *parent = 0);
    
signals:
    
public slots:

    void digitClicked();
    void backspaceClicked();
    void clear();
    void pointClicked();
private:
    QLabel *titleLabel;
    QHBoxLayout *hTitleLayout;
    QHBoxLayout *hBottomLayout;
    QHBoxLayout *hButtonLayout;

    QVBoxLayout *vMainLayout;
    QVBoxLayout *vLeftLayout;
    QVBoxLayout *vRightLayout;

    QPushButton *nextButton;
    QPushButton *backButton;
    QPushButton *cancelButton;
   // QGridLayout *gridLayout;

    QLabel *tipLabel;
    QLineEdit *edit;

    enum { NumDigitButton = 10};
    Button *digitButtons[NumDigitButton];

    Button *createButton(const QString &text,const char *member);
};

#endif // INPUTREADER_H
