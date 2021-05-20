#include "include/AlbumModel.h"

#include <cstddef>

#include "include/Album.h"
#include "qhash.h"
#include "qnamespace.h"
#include "qvariant.h"

AlbumModel::AlbumModel(QObject* parent) :
    QAbstractItemModel(parent),
    m_db(DatabaseManager::instance()),
    m_albums(m_db.albumDao.albums())
{
}

int AlbumModel::rowCount(const QModelIndex& parent) const
{
        Q_UNUSED(parent);
        return m_albums->size();
};

auto AlbumModel::data(const QModelIndex& index, int role) const -> QVariant
{
        if (not isIndexValid(index))
        {
                return QVariant();
        }

        const Album& album = *(m_albums->at(index.row()));
        switch (role)
        {
                case Roles::idRole:
                        return album.id();

                case Roles::nameRole:
                case Qt::DisplayRole:
                        return album.name();

                default:
                        return QVariant();
        }
}
auto AlbumModel::roleNames() const -> QHash<int, QByteArray>
{
        QHash<int, QByteArray> roles;

        roles[Roles::idRole]   = "id";
        roles[Roles::nameRole] = "name";

        return roles;
}
bool AlbumModel::isIndexValid(const QModelIndex& index) const
{
        return index.isValid() && index.row() < rowCount();
}
