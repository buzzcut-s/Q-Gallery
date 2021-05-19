#include "include/AlbumModel.h"

AlbumModel::AlbumModel(QObject* parent) :
    QAbstractItemModel(parent),
    m_db(DatabaseManager::instance()),
    m_albums(m_db.albumDao.albums())
{
}
