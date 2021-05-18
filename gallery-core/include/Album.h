#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "gallery-core_global.h"

class GALLERYCORE_EXPORT Album
{
public:
        explicit Album(QString name = "");

        int     id() const;
        void    setId(int id);
        QString name() const;
        void    setName(const QString& name);

private:
        int     m_id;
        QString m_name;
};

#endif  // ALBUM_H
