#include "Album.h"

#include <utility>

Album::Album(QString name) :
    m_id(-1),
    m_name(std::move(name))
{
}
