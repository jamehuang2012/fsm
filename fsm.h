#ifndef FSM_H
#define FSM_H

#include <QStateMachine>
#include <QState>


namespace FSM
{
    enum {
        HANDLE_NO_END = -1,
        RETURN_PARENT = -2,
        HANDLE_END = 0,
        HANDLE_ERR = -3
    };
}

typedef struct tagMESSAGE
{
    unsigned char    did;
    unsigned char    type;
    unsigned char    sid;
    unsigned char    length;
    union
    {
        unsigned char    content[256];
        //what for using union?
    }Union;
} MESSAGE;


class State;

class Fsm : public QStateMachine
{
    Q_OBJECT
public:
    explicit Fsm(QStateMachine *parent = 0);
    virtual ~Fsm();
    virtual int msgProc(MESSAGE *pMsg,int *userId = 0);
    void setCurState(State *state) { m_pCurState = state;}
    State *getCurState() { return m_pCurState;}
    int getCurStateIndex() {return m_stateIndex;}
    void setStateHead(State **ppStateHead) { m_ppStateHead = ppStateHead;}
    virtual void changeState(int stateType);


    State *finalState;
    State *m_pCurState;
    int m_stateIndex;

    
signals:
    
public slots:
private:
    State **m_ppStateHead;
    
};

inline void Fsm::changeState(int stateType) {m_stateIndex = stateType;}

class State : public QState
{
public:
    State(Fsm* stateMachine);
    virtual ~State();
    virtual int msgProc( Fsm* pCtrl, MESSAGE* pMsg, int* userId );

    int handleMsg( unsigned int message, long wParam = 0,  long lParam = 0,int* pUser = 0 );
    void changeState(  Fsm* pCtrl, int stateType );
    int  m_nErrorCount;

    virtual void  stateProc(int index) = 0;
protected:

private:
//attribute:
    int m_stateInfo ;
    Fsm* m_pfsm;
};

#endif // FSM_H
