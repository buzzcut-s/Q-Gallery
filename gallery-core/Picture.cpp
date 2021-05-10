#include "Picture.h"

#include <utility>

Picture::Picture(const QString& filePath) :
    Picture(QUrl::fromLocalFile(filePath))
{
}

Picture::Picture(const QUrl& fileUrl) :
    m_id(-1),
    m_albumId(-1),
    m_fileUrl(fileUrl)
{
}

auto Picture::fileUrl() const -> QUrl
{
        return m_fileUrl;
}

void Picture::setFileUrl(const QUrl& fileUrl)
{
        m_fileUrl = fileUrl;
}
