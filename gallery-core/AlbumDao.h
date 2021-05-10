#ifndef ALBUMDAO_H
#define ALBUMDAO_H

class QSqlDatabase;

class AlbumDao
{
public:
        explicit AlbumDao(QSqlDatabase& database);
        void init() const;

private:
        QSqlDatabase& m_database;
};

#endif  // ALBUMDAO_H
