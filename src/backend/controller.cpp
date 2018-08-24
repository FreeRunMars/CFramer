#include "controller.h"

Controller::Controller()
{
    m_worker = new Worker;
    m_workerThread = new QThread;
    m_worker->moveToThread(m_workerThread);
    initConnect();
    m_workerThread->start();
}

Controller::~Controller()
{

}

void Controller::initConnect()
{

}
