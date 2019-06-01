/*
    RPG Paper Maker Copyright (C) 2017-2019 Marie Laporte

    RPG Paper Maker engine is under LGPL-3 license.

    Commercial license for commercial use of your games:
        https://creativecommons.org/licenses/by-nc/4.0/.

    See more information here: http://rpg-paper-maker.com/index.php/downloads.
*/

#include <QStandardItemModel>
#include "serializable.h"
#include "systemsong.h"
#include "songkind.h"

#ifndef SONGSDATAS_H
#define SONGSDATAS_H

// -------------------------------------------------------
//
//  CLASS SongsDatas
//
//  Contains all the possible pictures of a game. The data file is located in
//  Content/Datas/pictures.json.
//
// -------------------------------------------------------

class SongsDatas : public Serializable
{
public:
    SongsDatas();
    virtual ~SongsDatas();
    void read(QString path);
    QStandardItemModel* model(SongKind kind) const;
    void setModel(SongKind kind, QStandardItemModel* model);
    void setDefault();
    void fillList(QList<SystemSong*> &songs, QList<QString> &names,
                  QString extension);
    void setDefaultSongs(QList<QString>& names, SongKind kind,
                         QString extension);
    void setDefaultMusics(QList<QString>& names);
    void setDefaultBackgroundSounds(QList<QString>& names);
    void setDefaultSounds(QList<QString>& names);
    void setDefaultMusicEffects(QList<QString>& names);

    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;

private:
    QHash<SongKind, QStandardItemModel*> m_models;
};

#endif // SONGSDATAS_H