#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <memory>
#include <vector>

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
        auto albums() const -> std::unique_ptr<std::vector<std::unique_ptr<Album>>>;

private:
        QSqlDatabase& m_database;
};

#endif  // ALBUMDAO_H
