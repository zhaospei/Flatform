#include "GameStateMachine.h"
#include "GameStateBase.h"

GameStateMachine::GameStateMachine()
{
    m_ActivesState = nullptr;
    m_NextState = nullptr;
}

GameStateMachine::~GameStateMachine()
{
    while (!m_StateStack.empty()) {
        delete m_StateStack.top();
        m_StateStack.pop();
    }
}

void GameStateMachine::ChangeState(GameStateBase* state)
{
    m_NextState = state;
}

void GameStateMachine::ChangeState(StateTypes st)
{
    GameStateBase* gs = GameStateBase::CreateState(st);
    ChangeState(gs);
}

void GameStateMachine::PushState(StateTypes st)
{
    GameStateBase* gs = GameStateBase::CreateState(st);
    if (!m_StateStack.empty()) {
        m_StateStack.top()->Pause();
    }
    m_NextState = gs;
}

void GameStateMachine::PopState()
{
    if (!m_StateStack.empty()) {
        m_StateStack.top()->Exit();
        m_StateStack.pop();
    }
    if (!m_StateStack.empty()) {
        m_StateStack.top()->Resume();
    }
    m_ActivesState = m_StateStack.top();
}

void GameStateMachine::PerformStateChange()
{
    if (m_NextState != nullptr) {
        if (!m_StateStack.empty()) {
            m_StateStack.top()->Exit();
        }
        m_StateStack.push(m_NextState);
        m_StateStack.top()->Init();
        m_ActivesState = m_NextState;
    }
    m_NextState = nullptr;
}

GameStateBase* GameStateMachine::currentState() const
{
    return m_ActivesState;
}

GameStateBase* GameStateMachine::nextState() const
{
    return m_NextState;
}

bool GameStateMachine::NeedToChangeState()
{
    return m_NextState != nullptr;
}

bool GameStateMachine::HasState()
{
    return m_StateStack.size() > 0;
}
