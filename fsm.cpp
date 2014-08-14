//In order to use same code style , I rewrite the code from Gabriel



#include "fsm.h"



Fsm::Fsm(QStateMachine *parent) :
    QStateMachine(parent)
{
        m_stateIndex = 0;
        m_ppStateHead = NULL;
        m_pCurState = NULL;

}

Fsm::~Fsm()
{

}


int Fsm::msgProc(MESSAGE *pMsg, int *userId)
{
    int rc = m_pCurState->msgProc(this,pMsg,userId);
    m_pCurState->stateProc(m_stateIndex);
    return rc;
}


//State class


State::State(Fsm *stateMachine)
{
    m_stateInfo = 0;
    m_nErrorCount = 0;
    m_pfsm = stateMachine;
}

State::~State()
{

}

void State::changeState(Fsm *pCtrl, int stateType)
{
    pCtrl->changeState(stateType);
}

int State::msgProc(Fsm *pCtrl, MESSAGE *pMsg, int *userId)
{
    int rc = handleMsg(pMsg->type,(long)pCtrl,(long)pMsg,userId);
    return rc;
}

int State::handleMsg(unsigned int message, long wParam, long lParam, int *pUser)
{
    // I am confuse where pActiveState free?
  //  State *pActiveState = ((Fsm *)wParam)->getCurState();
    return FSM::HANDLE_NO_END;
}



