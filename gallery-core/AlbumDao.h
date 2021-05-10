#ifndef ALBUMDAO_H
#define ALBUMDAO_H

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
        explicit AlbumDao(QSqlDatabase& database);
        void init() const;

        void addAlbum(Album& album) const;
        void updateAlbum(const Album& album) const;
        void removeAlbum(int id) const;

private:
        QSqlDatabase& m_database;
};

#endif  // ALBUMDAO_H
