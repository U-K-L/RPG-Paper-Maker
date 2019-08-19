/*
    RPG Paper Maker Copyright (C) 2017-2019 Wano

    RPG Paper Maker engine is under proprietary license.
    This source code is also copyrighted.

    Use Commercial edition for commercial use of your games.
    See RPG Paper Maker EULA here:
        http://rpg-paper-maker.com/index.php/eula.
*/

#ifndef SYSTEMDETECTION_H
#define SYSTEMDETECTION_H

#include <QMetaType>
#include "systemobject3d.h"
#include "position3d.h"
#include "map.h"

// -------------------------------------------------------
//
//  CLASS SystemDetection
//
//  A particulary detection (datas).
//
// -------------------------------------------------------

class SystemDetection : public SuperListItem
{
public:
    static const QString JSON_FIELD_LEFT;
    static const QString JSON_FIELD_RIGHT;
    static const QString JSON_FIELD_TOP;
    static const QString JSON_FIELD_BOT;
    static const QString JSON_BOXES;
    static const int DEFAULT_FIELD_LEFT;
    static const int DEFAULT_FIELD_RIGHT;
    static const int DEFAULT_FIELD_TOP;
    static const int DEFAULT_FIELD_BOT;

    SystemDetection();
    SystemDetection(int i, QString n, int fl = DEFAULT_FIELD_LEFT, int fr =
        DEFAULT_FIELD_RIGHT, int ft = DEFAULT_FIELD_TOP, int fb =
        DEFAULT_FIELD_BOT);
    virtual ~SystemDetection();

    int fieldLeft() const;
    void setFieldLeft(int f);
    int fieldRight() const;
    void setFieldRight(int f);
    int fieldTop() const;
    void setFieldTop(int f);
    int fieldBot() const;
    void setFieldBot(int f);

    Map * createDetectionMap() const;
    void getTargetPosition(QVector3D *position) const;

    virtual bool openDialog();
    virtual SuperListItem * createCopy() const;
    virtual void setCopy(const SuperListItem &super);
    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;

protected:
    int m_fieldLeft;
    int m_fieldRight;
    int m_fieldTop;
    int m_fieldBot;
    QHash<Position3D, SystemObject3D *> m_boxes;
};

Q_DECLARE_METATYPE(SystemDetection);

#endif // SYSTEMDETECTION_H