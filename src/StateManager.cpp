#include "StateManager.hpp"
miniEngine::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false){}

miniEngine:: StateManager::~StateManager() {}

void miniEngine::StateManager:: Add(std::unique_ptr<State> toAdd, bool replace)
{
	m_add = true;
	m_newState = std::move(toAdd);
	m_replace = replace;
}

void miniEngine::StateManager::PopCurrent()
{
	m_remove = true;
}

void miniEngine::StateManager::ProcessStateChange()
{
	if (m_remove && (!m_stateStack.empty()))
	{
		m_stateStack.pop();
		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Start();

		}
		m_remove = false;
	}
	if (m_add)
	{
		if (m_replace && (!m_stateStack.empty()))
		{
			m_stateStack.pop();
			m_replace = false;
		}
		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Pause();
		}
		m_stateStack.push(std::move(m_newState));
		m_stateStack.top()->Init();
		m_stateStack.top()->Start();
		m_add = false;
	}
}

std::unique_ptr <miniEngine::State > &miniEngine::StateManager::GetCurrent()
{
	return m_stateStack.top();
}
