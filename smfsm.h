#ifndef SMFSM_H
#define SMFSM_H
#include "fsm.h"


class MainIdle;
class ChargerState;


class SMFsm : public Fsm
{
     Q_OBJECT
public:
    SMFsm(QStateMachine *parent =0);
    virtual ~SMFsm();
    int msgProc(MESSAGE *pMsg, int *userId);
    int initialization();
    int run();

public slots:
signals:
private:
    MainIdle *m_mainState;
    ChargerState *m_chargeState;

};


class MainIdle:public State
{
    Q_OBJECT
public:
    MainIdle(Fsm *parent = 0);
    virtual ~MainIdle();
    int msgProc(Fsm *pCtrl, MESSAGE *pMsg, int *userId);
    void stateProc(int index);
public slots:
    void initialization();
signals:
private:
    Fsm *m_pfsm;
    // I have changed SMFsm *m_pfsm to Fsm *m_pfsm

};


class ChargerState:public State
{
     Q_OBJECT
public:
    ChargerState(Fsm *parent = 0);
    virtual ~ChargerState();
    int msgProc(Fsm *pCtrl, MESSAGE *pMsg, int *userId);
    void stateProc(int index);
public slots:
    void initialization();
signals:

private:
    Fsm *m_pfsm;


};


#endif // SMFSM_H
