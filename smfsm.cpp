#include "smfsm.h"
#include <QDebug>
#include <QFinalState>
SMFsm::SMFsm(QStateMachine *parent):Fsm(parent)
{

}

SMFsm::~SMFsm()
{

}
// create the realted state under this statement
int SMFsm::initialization()
{
    m_mainState = new MainIdle(this);
    m_chargeState = new ChargerState(this);
    QFinalState *finalState =new QFinalState(this);

    addState(m_mainState);
    addState(m_chargeState);
    addState(finalState);

    // add Transaction

    setInitialState(m_mainState);
}


int SMFsm::run()
{
    m_mainState->assignProperty(m_mainState,"running",true);
    start();

}


int SMFsm::msgProc(MESSAGE *pMsg, int *userId)
{
    qDebug() << "SMFsm::msgproc";
    State *pState = getCurState();
    int rc = pState->msgProc(this,pMsg,userId);
    int currentIndex = getCurStateIndex();
    pState->stateProc(currentIndex);
    // Access the parent's public varible directly is not a good idea, we need to disscurss this issue
    //I hanve change these variables to private
    return FSM::HANDLE_NO_END;
}


// MainIdle state is responsible for managering main menu and going to sleep


MainIdle::MainIdle(Fsm *parent):State(parent)
{
    m_pfsm = parent;
    connect(this,SIGNAL(propertiesAssigned()),this,SLOT(initialization()));
}

MainIdle::~MainIdle()
{
    qDebug() << "MainIdle state free";
}

void MainIdle::initialization()
{
    qDebug() << "Main Idle initialization";
    m_pfsm->setCurState(this);
}


int MainIdle::msgProc(Fsm *pCtrl, MESSAGE *pMsg, int *userId)
{
    qDebug() << "MainIdle::msgProc " << pMsg->type;

    switch (pMsg->type) {
       case 0x01:
    case 0x02:
    case 0x03:
    default:
        break;
    }
}

void MainIdle::stateProc(int index)
{
    qDebug() << "MainIdle::stateProc index=" << index;

    switch(index) {
        case 0x00:
    case 0x01:
    case 0x02:
    case 0x03:
    default:
        break;
    }


}

//charger state

ChargerState::ChargerState(Fsm *parent):State(parent)
{
    m_pfsm = parent;
    connect(this,SIGNAL(propertiesAssigned()),this,SLOT(initialization()));
}

ChargerState::~ChargerState()
{
    qDebug("ChargeState free");
}

void ChargerState::initialization()
{

    qDebug() << "Charge State initialization";
    m_pfsm->setCurState(this);

}


int ChargerState::msgProc(Fsm *pCtrl, MESSAGE *pMsg, int *userId)
{
    qDebug() << "ChargeState:: msgProc pMsg->type = " << pMsg->type;
    switch(pMsg->type) {
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x04:
    default:
        break;
    }
}

void ChargerState::stateProc(int index)
{
    qDebug() << "ChargerState::stateProc index=" << index;
    switch(index) {
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x04:
    default:
        break;
    }
}







