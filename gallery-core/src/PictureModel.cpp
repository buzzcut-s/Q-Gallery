#include "include/PictureModel.h"

PictureModel::PictureModel(const AlbumModel& albumModel, QObject* parent) :
    QAbstractItemModel(parent),
    m_db(DatabaseManager::instance()),
    m_albumId(-1),
    m_pictures(new std::vector<std::unique_ptr<Picture>>())
{
        connect(&albumModel, &AlbumModel::rowsRemoved,
                this, &PictureModel::deletePicturesForAlbum);
}

auto PictureModel::addPicture(const Picture& picture) -> QModelIndex
{
        int rows = rowCount();

        beginInsertRows(QModelIndex(), rows, rows);
        auto newPicture = std::make_unique<Picture>(picture);
        m_db.pictureDao().addPictureInAlbum(m_albumId, *newPicture);
        m_pictures->push_back(move(newPicture));
        endInsertRows();

        return index(rows, 0);
}

int PictureModel::rowCount(const QModelIndex& parent) const
{
        Q_UNUSED(parent);
        return m_pictures->size();
}

auto PictureModel::data(const QModelIndex& index, int role) const -> QVariant
{
        if (not isIndexValid(index))
        {
                return QVariant();
        }

        const Picture& picture = *(m_pictures->at(index.row()));
        switch (role)
        {
                case Qt::DisplayRole:
                        return picture.fileUrl().fileName();

                case Roles::urlRole:
                        return picture.fileUrl();

                case Roles::filePathRole:
                        return picture.fileUrl().toLocalFile();

                default:
                        return QVariant();
        }
}

auto PictureModel::roleNames() const -> QHash<int, QByteArray>
{
        QHash<int, QByteArray> roles;

        roles[Qt::DisplayRole]     = "name";
        roles[Roles::filePathRole] = "filepath";
        roles[Roles::urlRole]      = "url";

        return roles;
}

bool PictureModel::removeRows(int row, int count, const QModelIndex& parent)
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
                const Picture& picture = *(m_pictures->at(row + countLeft));
                m_db.pictureDao().removePicture(picture.id());
        }
        m_pictures->erase(m_pictures->begin() + row,
                          m_pictures->begin() + row + count);
        endRemoveRows();

        return true;
}

void PictureModel::setAlbumId(int albumId)
{
        beginResetModel();
        m_albumId = albumId;
        loadPictures(m_albumId);
        endResetModel();
}

void PictureModel::clearAlbum()
{
        setAlbumId(-1);
}

void PictureModel::deletePicturesForAlbum()
{
        m_db.pictureDao().removePicturesForAlbum(m_albumId);
        clearAlbum();
}

void PictureModel::loadPictures(int albumId)
{
        if (albumId <= 0)
        {
                m_pictures = std::make_unique<std::vector<std::unique_ptr<Picture>>>();
                return;
        }
        m_pictures = m_db.pictureDao().picturesForAlbum(albumId);
}

bool PictureModel::isIndexValid(const QModelIndex& index) const
{
        return not(index.row() < 0
                   || index.row() >= rowCount()
                   || not index.isValid());
}
