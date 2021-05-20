#include "include/DatabaseManager.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager& DatabaseManager::instance()
{
        static DatabaseManager singleton;
        return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    m_dataBase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    m_albumDao(*m_dataBase),
    m_pictureDao(*m_dataBase)
{
        m_dataBase->setDatabaseName(path);

        bool openStatus = m_dataBase->open();
        qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

        m_albumDao.init();
}

DatabaseManager::~DatabaseManager()
{
        m_dataBase->close();
        delete m_dataBase;
}

auto DatabaseManager::albumDao() const -> const AlbumDao&
{
        return m_albumDao;
}

auto DatabaseManager::pictureDao() const -> const PictureDao&
{
        return m_pictureDao;
}

void DatabaseManager::debugQuery(const QSqlQuery& query)
{
        if (query.lastError().type() == QSqlError::ErrorType::NoError)
        {
                qDebug() << "Query OK:" << query.lastQuery();
        }
        else
        {
                qWarning() << "Query KO:" << query.lastError().text();
                qWarning() << "Query text:" << query.lastQuery();
        }
}