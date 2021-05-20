#include "include/Picture.h"

#include <utility>

Picture::Picture(const QString& filePath) :
    Picture{QUrl::fromLocalFile(filePath)}
{
}

Picture::Picture(QUrl fileUrl) :
    m_id{-1},
    m_albumId{-1},
    m_fileUrl{std::move(fileUrl)}
{
}

int Picture::id() const
{
        return m_id;
}

void Picture::setId(int id)
{
        m_id = id;
}

int Picture::albumId() const
{
        return m_id;
}

void Picture::setAlbumId(int albumId)
{
        m_albumId = albumId;
}

auto Picture::fileUrl() const -> QUrl
{
        return m_fileUrl;
}

void Picture::setFileUrl(const QUrl& fileUrl)
{
        m_fileUrl = fileUrl;
}
