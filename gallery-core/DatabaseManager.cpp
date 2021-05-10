#include "DatabaseManager.h"

#include <QDebug>
#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance()
{
        static DatabaseManager singleton;
        return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    m_dataBase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{
        m_dataBase->setDatabaseName(path);

        bool openStatus = m_dataBase->open();
        qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");
}

DatabaseManager::~DatabaseManager()
{
        m_dataBase->close();
        delete m_dataBase;
}
