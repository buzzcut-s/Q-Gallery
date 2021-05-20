#include "include/AlbumModel.h"

AlbumModel::AlbumModel(QObject* parent) :
    QAbstractItemModel{parent},
    m_db{DatabaseManager::instance()},
    m_albums{m_db.albumDao().albums()}
{
}

auto AlbumModel::addAlbum(const Album& album) -> QModelIndex
{
        int rowIndex = rowCount();

        beginInsertRows(QModelIndex(), rowIndex, rowIndex);
        auto newAlbum = std::make_unique<Album>(album);
        m_db.albumDao().addAlbum(*newAlbum);
        m_albums->push_back(std::move(newAlbum));
        endInsertRows();

        return index(rowIndex, 0);
}

int AlbumModel::rowCount(const QModelIndex& parent) const
{
        Q_UNUSED(parent);
        return m_albums->size();
}

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

bool AlbumModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
        if (not isIndexValid(index) || role != Roles::nameRole)
        {
                return false;
        }

        Album& album = *(m_albums->at(index.row()));
        album.setName(value.toString());
        m_db.albumDao().updateAlbum(album);
        emit dataChanged(index, index);

        return true;
}

bool AlbumModel::removeRows(int row, int count, const QModelIndex& parent)
{
        if (row < 0
            || row >= rowCount()
            || count < 0
            || (row + count) > rowCount())
        {
                return false;
        }

        beginRemoveRows(parent, row, row + count - 1);
        int countLeft = count;
        while (countLeft--)
        {
                const Album& album = *(m_albums->at(row + countLeft));
                m_db.albumDao().removeAlbum(album.id());
        }
        m_albums->erase(m_albums->begin() + row,
                        m_albums->begin() + row + count);
        endRemoveRows();

        return true;
}

bool AlbumModel::isIndexValid(const QModelIndex& index) const
{
        return index.isValid() && index.row() < rowCount();
}
